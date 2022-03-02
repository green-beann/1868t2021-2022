using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern controller Controller2;
extern motor LeftMotor;
extern motor RightMotor;
extern motor_group ClawMotors;
extern limit LimitSwitch;
extern motor Intake;
extern motor Conveyor;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );