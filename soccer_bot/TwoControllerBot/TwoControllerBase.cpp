/*******************************************************************
*	This is the workings of the base of your robot, you should not  
*	need to adapt any of this code unless you want to change the  
*	pins for the motor controller.
*
*	You should use this file to check your pin location against the  
*	pin values.
*	
*	Author: Phil Legge
*	Date: 7/8/18
*********************************************************************/

#include "TwoControllerBase.h"\



TwoControllerBase::TwoControllerBase(){
	// signal pins need to be pwm pins on the UNO board (~ near the number)
	rightFrontSignal = 13; //ENA F
	rightRearSignal = 11;  //ENA R
	leftFrontSignal = 12; //ENB F
	leftRearSignal = 10;  //ENB R
	// these pins don't need to be pwm
	rightFrontIn1 = 31;
	rightFrontIn2 = 33;
	leftFrontIn1 = 35;
	leftFrontIn2 = 37;
	rightRearIn1 = 22;
	rightRearIn2 = 24;
	leftRearIn1 = 26;
	leftRearIn2 = 28;
	_motorFrontRight = new L298N(rightFrontSignal,rightFrontIn1,rightFrontIn2);
	_motorFrontLeft = new L298N(leftFrontSignal,leftFrontIn1,leftFrontIn2);
	_motorRearRight = new L298N(rightRearSignal,rightRearIn1,rightRearIn2);
	_motorRearLeft = new L298N(leftRearSignal,leftRearIn1,leftRearIn2);
}

int right_Adjust = 0; //slows right
int left_Adjust = 0; //slows left my int
int back_left_Adjust = 0;//slows back left
int back_right_Adjust = 0; //slows back right



// easy way to adjust wheels;
void TwoControllerBase::set_adjust(int right, int left, int back_left, int back_right){
	int right_Adjust = right;
	int left_Adjust = left;
  int back_left_Adjust = back_left;
	int back_right_Adjust = back_right;
}




//forward
void TwoControllerBase::driveForward(unsigned short frontRightSpeed, unsigned short frontLeftSpeed, unsigned short backRightSpeed, unsigned short backLeftSpeed){
	_motorFrontRight->setSpeed(frontRightSpeed-right_Adjust);
	_motorFrontLeft->setSpeed(frontLeftSpeed-left_Adjust);
	_motorRearRight->setSpeed(backRightSpeed-back_right_Adjust);
	_motorRearLeft->setSpeed(backLeftSpeed-back_left_Adjust);
	_motorFrontRight->backward();
	_motorFrontLeft->forward();
	_motorRearRight->backward();
	_motorRearLeft->forward();
}

void TwoControllerBase::driveLeft(unsigned short frontRightSpeed, unsigned short frontLeftSpeed, unsigned short backRightSpeed, unsigned short backLeftSpeed){
	_motorFrontRight->setSpeed(frontRightSpeed-right_Adjust);
	_motorFrontLeft->setSpeed(frontLeftSpeed-left_Adjust);
	_motorRearRight->setSpeed(backRightSpeed-back_right_Adjust);
	_motorRearLeft->setSpeed(backLeftSpeed-back_left_Adjust);
	_motorFrontRight->forward();
	_motorFrontLeft->backward();
	_motorRearRight->backward();
	_motorRearLeft->forward();	  

}

void TwoControllerBase::driveRight(unsigned short frontRightSpeed, unsigned short frontLeftSpeed, unsigned short backRightSpeed, unsigned short backLeftSpeed){
	_motorFrontRight->setSpeed(frontRightSpeed-right_Adjust);
	_motorFrontLeft->setSpeed(frontLeftSpeed-left_Adjust);
	_motorRearRight->setSpeed(backRightSpeed-back_right_Adjust);
	_motorRearLeft->setSpeed(backLeftSpeed-back_left_Adjust);
	_motorFrontRight->backward();
	_motorFrontLeft->forward();
	_motorRearRight->forward();
	_motorRearLeft->backward();
}

//backward
void TwoControllerBase::driveBackward(unsigned short frontRightSpeed, unsigned short frontLeftSpeed, unsigned short backRightSpeed, unsigned short backLeftSpeed){
	_motorFrontRight->setSpeed(frontRightSpeed-right_Adjust);
	_motorFrontLeft->setSpeed(frontLeftSpeed-left_Adjust);
	_motorRearRight->setSpeed(backRightSpeed-back_right_Adjust);
	_motorRearLeft->setSpeed(backLeftSpeed-back_right_Adjust);
	_motorFrontRight->forward();
	_motorFrontLeft->backward();
	_motorRearRight->forward();
	_motorRearLeft->backward();
}


//diagonals



//forward left

void TwoControllerBase::driveForwardLeft(unsigned short frontRightSpeed, unsigned short frontLeftSpeed, unsigned short backRightSpeed, unsigned short backLeftSpeed){
	_motorFrontRight->setSpeed(frontRightSpeed-right_Adjust);
	_motorFrontLeft->setSpeed(0);
	_motorRearRight->setSpeed(0);
	_motorRearLeft->setSpeed(backLeftSpeed-back_left_Adjust);
	_motorFrontRight->backward();
	_motorFrontLeft->forward();
	_motorRearRight->backward();
	_motorRearLeft->forward();
}


//forward right

void TwoControllerBase::driveForwardRight(unsigned short frontRightSpeed, unsigned short frontLeftSpeed, unsigned short backRightSpeed, unsigned short backLeftSpeed){
	_motorFrontRight->setSpeed(0);
	_motorFrontLeft->setSpeed(frontLeftSpeed-left_Adjust);
	_motorRearRight->setSpeed(backRightSpeed-back_right_Adjust);
	_motorRearLeft->setSpeed(0);
	_motorFrontRight->backward();
	_motorFrontLeft->forward();
	_motorRearRight->backward();
	_motorRearLeft->forward();
}

//backward right
void TwoControllerBase::driveBackwardRight(unsigned short frontRightSpeed, unsigned short frontLeftSpeed, unsigned short backRightSpeed, unsigned short backLeftSpeed){
	_motorFrontRight->setSpeed(frontRightSpeed+right_Adjust);
	_motorFrontLeft->setSpeed(0);
	_motorRearRight->setSpeed(0);
	_motorRearLeft->setSpeed(backLeftSpeed-back_left_Adjust);
	_motorFrontRight->forward();
	_motorFrontLeft->backward();
	_motorRearRight->forward();
	_motorRearLeft->backward();
}

//backward left

void TwoControllerBase::driveBackwardLeft(unsigned short frontRightSpeed, unsigned short frontLeftSpeed, unsigned short backRightSpeed, unsigned short backLeftSpeed){
	_motorFrontRight->setSpeed(0);
	_motorFrontLeft->setSpeed(frontLeftSpeed-left_Adjust);
	_motorRearRight->setSpeed(backRightSpeed-back_right_Adjust);
	_motorRearLeft->setSpeed(0);
	_motorFrontRight->forward();
	_motorFrontLeft->backward();
	_motorRearRight->forward();
	_motorRearLeft->backward();
}



//Robot rotations

//rotate right

void TwoControllerBase::rotateRight(unsigned short turnSpeed){
	_motorFrontRight->setSpeed(turnSpeed);
	_motorFrontLeft->setSpeed(turnSpeed);
	_motorRearRight->setSpeed(turnSpeed);
	_motorRearLeft->setSpeed(turnSpeed);
	_motorFrontRight->forward();
	_motorFrontLeft->forward();
	_motorRearRight->forward();
	_motorRearLeft->forward();	
}

//rotate left

void TwoControllerBase::rotateLeft(unsigned short turnSpeed){
	_motorFrontRight->setSpeed(turnSpeed);
	_motorFrontLeft->setSpeed(turnSpeed);
	_motorRearRight->setSpeed(turnSpeed);
	_motorRearLeft->setSpeed(turnSpeed);
	_motorFrontRight->backward();
	_motorFrontLeft->backward();
	_motorRearRight->backward();
	_motorRearLeft->backward();
}
