# This is one of ROVOTICS' internal libraries.
# It's a class that simulates motion in one dimension.
# Input speed is meters / second

class MotionSimulator():
  def __init__(self, position):
    self.position = position
    self.velocity = 0
    
  def update_position(self, velocity):
    cutoff = 0.05 # Speed below which you can neglect velocity
    if self.velocity <= cutoff:
      self.velocity = 0
    
    self.velocity = self.velocity * 0.8 + velocity * 0.2
    self.position += self.velocity

  def get_position(self):
    return self.position

