#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
controller Controller2 = controller(partner);
motor LeftMotor = motor(PORT10, ratio18_1, false);
motor RightMotor = motor(PORT3, ratio18_1, true);
motor ClawMotorsMotorA = motor(PORT15, ratio36_1, false);
motor ClawMotorsMotorB = motor(PORT1, ratio36_1, true);
motor_group ClawMotors = motor_group(ClawMotorsMotorA, ClawMotorsMotorB);
motor BottomIntake = motor(PORT20, ratio18_1, false);
motor Conveyor = motor(PORT12, ratio18_1, false);
bumper BumperSwitch = bumper(Brain.ThreeWirePort.B);
motor TopIntake = motor(PORT17, ratio18_1, false);
motor armMotor = motor(PORT14, ratio18_1, false);

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