import rclpy
from rclpy.node import Node 
from core.msg import ThrusterVoltage
import matplotlib.pyplot as plt 
import matplotlib.animation as animation
import threading
from collections import deque

class ThrusterGraph(Node):
    def __init__(self):
        super().__init__('thruster_graph')

        self.max_samples = 200
        self.counter = 0 
        self.volt_x = deque(maxlen=self.max_samples)
        self.volt_y = {
            "48V": deque(maxlen=self.max_samples),
            "12VL": deque(maxlen=self.max_samples),
            "12VR": deque(maxlen=self.max_samples),
            "3V3": deque(maxlen=self.max_samples)
        }
        
        self.lock = threading.Lock()

        self.volt_sub = self.create_subscription(ThrusterVoltage, '/thruster_voltage', self.volt_callback, 10)

    def volt_callback(self, msg):
        with self.lock:
            self.volt_x.append(self.counter)
            self.counter += 1
            
            self.volt_y["48V"].append(msg.v48v)
            self.volt_y["12VL"].append(msg.v12v_left)
            self.volt_y["12VR"].append(msg.v12v_right)
            self.volt_y["3V3"].append(msg.v3v3)

def main(args=None):
    rclpy.init(args=args)
    node = ThrusterGraph()

    thread = threading.Thread(target=rclpy.spin, args=(node,), daemon=True)
    thread.start()

    fig, ax = plt.subplots()
    lines = {
        "48V": ax.plot([], [], label="48V", color="red")[0],
        "12VL": ax.plot([], [], label="12V Left", color="blue")[0],
        "12VR": ax.plot([], [], label="12V Right", color="green")[0],
        "3V3": ax.plot([], [], label="3V3", color="purple")[0]
    }
    
    ax.set_ylim(0, 60) 
    ax.set_xlabel("Sample Count")
    ax.set_ylabel("Voltage (V)")
    ax.set_title("Real-time Thruster Voltages")
    plt.legend(loc="upper right")

    def animate(i):
        with node.lock:
            if not node.volt_x:
                return lines.values()
            
            x_data = list(node.volt_x)
            for label, line in lines.items():
                line.set_data(x_data, list(node.volt_y[label]))
            
            ax.set_xlim(x_data[0], x_data[-1] + 1)
        
        return lines.values()

    ani = animation.FuncAnimation(fig, animate, interval=100, blit=False)
    
    try:
        plt.show()
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == "__main__":
    main()
