#include <WiFi.h>
#include <WebServer.h>
#include "ArrayList.h"
#include <Wire.h>
#include "MS5837.h"

struct DepthPacket {
  double depth;
  double pressure;
  unsigned long Time;
};

struct PIDControl {
  unsigned long time;
  unsigned long prevTime;
  int timeStep;
  double depth;
  double error;
  double integral;
  double derivative;
  double control;
};

MS5837 sensor;
DepthPacket mySensorData;
ArrayList<DepthPacket> mySensorDataList;
ArrayList<PIDControl> myPIDControlList;

const int MOTOR_IN1 = 33;
const int MOTOR_IN2 = 15;
const int SERVO_PIN = 32;
const int LED = 27;
int pumpState = 0; // 0 = idle

const char* ssid = "JHS_POD";
const char* password = "JHSRobo";
const int Wi_Fi_CHANNEL = 6;
String Wi_Fi_IP;

WebServer webServer(80);

TaskHandle_t Task1;
DepthPacket readDepthSensor() {
  DepthPacket data;
  sensor.read();
  data.depth = sensor.depth();
  data.pressure = sensor.pressure();
  data.Time = millis()/1000;
  return data;
}

String getDataPacketString(DepthPacket data) {
  return String(data.Time) + " s, " + String(data.pressure) + " kPa, " + String(data.depth) + " m";
}

String getQuotedString(String s){ return "\"" + s + "\""; }
String getQuotedFieldName(String s){ return "\"" + s + "\":"; }

void handleDataRequest() { webServer.send(200, "text/plain", "Data OK"); }
void handleControlRequest() { webServer.send(200, "text/plain", "Control OK"); }
void handlePIDDataRequest() { webServer.send(200, "text/plain", "PID Data OK"); }

void runLight(void * pvParameters){
  while (true) {
    digitalWrite(LED, LOW); // off
    delay(500);
  }
}

void setup() {
  Serial.begin(115200);
  delay(100);
  Wire.begin();
  Wire.setClock(100000);

  while (!sensor.init()) {
    Serial.println("MS5837 sensor init failed! Check SDA/SCL wiring.");
    delay(5000);
  }
  sensor.setModel(MS5837::MS5837_02BA);
  sensor.setFluidDensity(1000); 
  Serial.println("Sensor initialized successfully.");

  pinMode(MOTOR_IN1, OUTPUT);
  pinMode(MOTOR_IN2, OUTPUT);
  pinMode(LED, OUTPUT);

  digitalWrite(MOTOR_IN1, LOW);
  digitalWrite(MOTOR_IN2, LOW);
  pumpState = 0;

   WiFi.softAP(ssid, password, Wi_Fi_CHANNEL);
  Wi_Fi_IP = WiFi.softAPIP().toString();
  Serial.println("Wi-Fi network created: " + String(ssid));
  Serial.println("IP Address: " + Wi_Fi_IP);

   webServer.on("/data", handleDataRequest);
  webServer.on("/ctrl", handleControlRequest);
  webServer.on("/piddata", handlePIDDataRequest);
  webServer.begin();
  Serial.println("Web server started.");

    xTaskCreatePinnedToCore(
      runLight,    // task function
      "Task1",     // name
      10000,       // stack size
      NULL,        // parameter
      1,           // priority
      &Task1,      // task handle
      1              
      );

  Serial.println("Setup complete. System is idle.");
}
void loop() {
  webServer.handleClient(); 
  delay(100);              
}
void pumpStop() {
  digitalWrite(MOTOR_IN1, LOW);
  digitalWrite(MOTOR_IN2, LOW);
  pumpState = 0;
}

void pumpUp() {
  digitalWrite(MOTOR_IN1, LOW);
  digitalWrite(MOTOR_IN2, HIGH);
  pumpState = -1;
}

void pumpDown() {
  digitalWrite(MOTOR_IN2, LOW);
  digitalWrite(MOTOR_IN1, HIGH);
  pumpState = 1;
}


void algorithm() {
if depth
