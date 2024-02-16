// Open loop motor control example
#include <SimpleFOC.h>

// BLDC motor & driver instance
MagneticSensorPWM sensor = MagneticSensorPWM(GPIO_NUM_22, 2, 922);
void doPWM(){sensor.handlePWM();}
BLDCMotor motor = BLDCMotor(11);
BLDCDriver3PWM driver = BLDCDriver3PWM(GPIO_NUM_19, GPIO_NUM_18, GPIO_NUM_5, GPIO_NUM_17);

// instantiate the commander
Commander command = Commander(Serial);
void doTarget(char* cmd) { command.scalar(&motor.target, cmd); }

void setup() {

  // driver config
  // power supply voltage [V]
  driver.voltage_power_supply = 12;
  driver.init();
  // link the motor and the driver
  motor.linkDriver(&driver);

  // limiting motor movements
  // motor.phase_resistance = 3.52 // [Ohm]
  // motor.current_limit = 2;   // [Amps] - if phase resistance defined
  motor.voltage_limit = 3;   // [V] - if phase resistance not defined
  motor.velocity_limit = 5; // [rad/s] cca 50rpm
 
  // open loop control config
  motor.controller = MotionControlType::velocity_openloop;

  // init motor hardware
  motor.init();

  // add target command T
  command.add('T', doTarget, "target velocity");

  Serial.begin(115200);
  Serial.println("Motor ready!");
  Serial.println("Set target velocity [rad/s]");
  _delay(1000);
}
void loop() {

  // open loop velocity movement
  // using motor.voltage_limit and motor.velocity_limit
  motor.move();

  // user communication
  command.run();
}
