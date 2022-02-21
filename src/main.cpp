// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Controller2          controller                    
// LeftMotor            motor         11              
// RightMotor           motor         18              
// Intakes              motor_group   20, 12          
// ClawMotors           motor_group   15, 10          
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Controller2          controller                    
// LeftMotor            motor         11              
// RightMotor           motor         18              
// Intakes              motor_group   20, 12          
// ClawMotors           motor_group   15, 10          
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Controller2          controller                    
// LeftMotor            motor         11              
// RightMotor           motor         18              
// Intakes              motor_group   20, 12          
// MotorGroup15         motor_group   15, 10          
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Controller2          controller                    
// LeftMotor            motor         11              
// RightMotor           motor         18              
// Intakes              motor_group   20, 12          
// MotorGroup15         motor_group   15, 16          
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Controller2          controller                    
// LeftMotor            motor         11              
// RightMotor           motor         18              
// Intakes              motor_group   20, 12          
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Controller2          controller                    
// LeftMotor            motor         11              
// RightMotor           motor         18              
// Claw                 motor         15              
// Intakes              motor_group   20, 12          
// ---- END VEXCODE CONFIGURED DEVICES ----
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*    Robot name:   Bellicostic Belligerence                                  */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Controller2          controller                    
// LeftMotor            motor         11              
// RightMotor           motor         18              
// Claw                 motor         13              
// Intakes              motor_group   20, 12          
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) { // drive control
  // User control code here, inside the loop
  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    double leftSpeed = Controller1.Axis3.value(); //defines the axis for the left side of the chassis
    double rightSpeed = Controller1.Axis2.value(); //defines the axis for the right side of the chasssis
    double clawSpeed = Controller2.Axis2.value();
 
    
    LeftMotor.spin(forward, leftSpeed, pct); //left side
    RightMotor.spin(forward, rightSpeed, pct); //right side
    ClawMotors.spin(forward, clawSpeed, pct);


    if (Controller2.ButtonUp.pressing()) {
      //moves the intake rollers so they intake cubes
      Intakes.spin(forward, 55, pct);
 
    } else if (Controller2.ButtonDown.pressing()) {
      //moves the intake rollers so they outtake cubes
      Intakes.spin(reverse, 55, pct);
      
    } else {
      //keeps the motors from moving when the buttons are not pressed
      Intakes.stop();

    }
/*
    if (Controller2.ButtonR1.pressing()) {
      ClawMotors.spin(forward, 80, pct);
    }
    else if (Controller2.ButtonR2.pressing()) {
      ClawMotors.spin(reverse, 80, pct);
    } else {
      ClawMotors.stop();
    }
*/

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  //weewoo on 2/20/22
  // Set up callbacks for autonomous and driver control periods.
  //Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }

}