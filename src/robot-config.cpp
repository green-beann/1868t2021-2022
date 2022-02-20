#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
controller Controller2 = controller(partner);
motor LeftMotor = motor(PORT11, ratio18_1, false);
motor RightMotor = motor(PORT18, ratio18_1, true);
motor IntakesMotorA = motor(PORT20, ratio18_1, false);
motor IntakesMotorB = motor(PORT12, ratio18_1, false);
motor_group Intakes = motor_group(IntakesMotorA, IntakesMotorB);
motor ClawMotorsMotorA = motor(PORT15, ratio18_1, false);
motor ClawMotorsMotorB = motor(PORT10, ratio18_1, true);
motor_group ClawMotors = motor_group(ClawMotorsMotorA, ClawMotorsMotorB);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}