// Open loop motor control example
#include <SimpleFOC.h>
#include <Arduino.h>

TwoWire I2Cone = TwoWire(0);

// BLDC motor & driver instance
MagneticSensorPWM sensor = MagneticSensorPWM(GPIO_NUM_22, 2, 922);
void doPWM(){sensor.handlePWM();}

BLDCMotor motor = BLDCMotor(11);
BLDCDriver3PWM driver = BLDCDriver3PWM(32, 33, 25, 22);


//target variable
float target_velocity = 1;

// instantiate the commander
Commander command = Commander(Serial);
void doTarget(char* cmd) { command.scalar(&target_velocity, cmd); }
void doLimit(char* cmd) { command.scalar(&motor.voltage_limit, cmd); }

// this function is registered as an event, see setup()

void receiveEvent(int howMany)
{
    target_velocity = Wire.read();
    Serial.print("Recebido: ");
    Serial.println(target_velocity);
}

void setup() {
  I2Cone.begin(4, 19, 18, 400000);
  I2Cone.onReceive(receiveEvent);

  // driver config
  // power supply voltage [V]
  driver.voltage_power_supply = 12;
  // limit the maximal dc voltage the driver can set
  // as a protection measure for the low-resistance motors
  // this value is fixed on startup
  driver.voltage_limit = 6;
  driver.init();
  // link the motor and the driver
  motor.linkDriver(&driver);

  // limiting motor movements
  // limit the voltage to be set to the motor
  // start very low for high resistance motors
  // current = voltage / resistance, so try to be well under 1Amp
  motor.voltage_limit = 3;   // [V]
  motor.velocity_limit = 5; // [rad/s] cca 50rpm 
 
  // open loop control config
  motor.controller = MotionControlType::velocity_openloop;

  // init motor hardware
  motor.init();

  // add target command T
  command.add('T', doTarget, "target velocity");
  command.add('L', doLimit, "voltage limit");

  Serial.begin(115200);
  Serial.println("Motor ready!");
  Serial.println("Set target velocity [rad/s]");
  _delay(1000);
}

void loop() {

  // open loop velocity movement
  // using motor.voltage_limit and motor.velocity_limit
  // to turn the motor "backwards", just set a negative target_velocity
  motor.move(target_velocity);

  // user communication
  command.run();
}
