#include <SimpleFOC.h>

MagneticSensorPWM sensor = MagneticSensorPWM(GPIO_NUM_22, 2, 922);
void doPWM(){sensor.handlePWM();}

void setup() {
  pinMode(GPIO_NUM_23, OUTPUT);
  digitalWrite(GPIO_NUM_23, HIGH);
  // monitoring port
  Serial.begin(115200);
  
  // initialise encoder hardware
  sensor.init();
  // hardware interrupt enable
  sensor.enableInterrupt(doPWM);

  Serial.println("Encoder ready");
  _delay(1000);
}

void loop() {
  // IMPORTANT
  // read sensor and update the internal variables
  sensor.update();
  // display the angle and the angular velocity to the terminal
  Serial.print(sensor.getAngle());
  Serial.print("\t");
  Serial.println(sensor.getVelocity());
}
