#include "UltraSonicSensor.h"
#include "TwoControllerBase.h"
#include "RobotPixyV2.h"

 UltraSonicSensor *frontUltraSensor,*backUltraSensor,*leftUltraSensor,*rightUltraSensor;
         unsigned long previousMillis = 0UL;
         unsigned long interval = 1000UL;

  TwoControllerBase *myBase;
  //RobotPixy *myPixy;
      int ball, goal, ownGoal;


//initiates all variables
void setup(){
      
      myBase->set_adjust(0,0,0,0);
//     pixy = new RobotPixyV2();
      Serial.begin(9600);
	    // the code you write in here runs once at the very start of the program
      myBase = new TwoControllerBase();
     	//myPixy = new RobotPixy();
      

	    ball = 1;
    	goal = 2;
    	ownGoal = 3;
      frontUltraSensor = new UltraSonicSensor(A0, A1);
      backUltraSensor = new UltraSonicSensor(A2, A3);
      leftUltraSensor = new UltraSonicSensor(A4, A5);
      rightUltraSensor = new UltraSonicSensor(A6, A7);
      Serial.begin(9600);
  }

  void loop(){
    unsigned long currentMillis = millis();
    if(currentMillis - previousMillis > interval){
    previousMillis = currentMillis;


        // all the code you write in here will run over and over 50 times per second
        main();



        //the code should end here
        // speeds: frontright, frontleft, backright, backleft.
   }
  }




 int Forward(int frontRightSpeed,int frontLeftSpeed,int backRightSpeed,int backLeftSpeed){
    myBase->driveForward(frontRightSpeed, frontLeftSpeed, backRightSpeed, backLeftSpeed);
 }

  int Backward(int frontRightSpeed,int frontLeftSpeed,int backRightSpeed,int backLeftSpeed){
    myBase->driveBackward(frontRightSpeed, frontLeftSpeed, backRightSpeed, backLeftSpeed);
 }

   int Right(int frontRightSpeed,int frontLeftSpeed,int backRightSpeed,int backLeftSpeed){
    myBase->driveRight(frontRightSpeed, frontLeftSpeed, backRightSpeed, backLeftSpeed);
 }

   int Left(int frontRightSpeed,int frontLeftSpeed,int backRightSpeed,int backLeftSpeed){
    myBase->driveLeft(frontRightSpeed, frontLeftSpeed, backRightSpeed, backLeftSpeed);
 }

  int main(){
    int speed = myBase->Def;
    
    Forward(speed, speed, speed, speed);
}





  
