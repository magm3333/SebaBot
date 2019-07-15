#include "sebabot.h"
SebaBot::SebaBot(int ENA1, int IN1, int IN2, int ENA2, int IN3, int IN4, int SERVO, int TRIG, int ECHO, int SL1, int SL2, int IR){
	pinPotenciaMotor1=ENA1;
	pinIn1=IN1;
	pinIn2=IN2;
	pinPotenciaMotor2=ENA2;
	pinIn3=IN3;
	pinIn4=IN4;
	pinServo=SERVO;
	pinTrigger=TRIG;
	pinEcho=ECHO;
	pinSL1=SL1;
	pinSL2=SL2;
	pinIR=IR;
}

void SebaBot::begin(){
  pinMode(pinPotenciaMotor1, OUTPUT);
  pinMode(pinIn1, OUTPUT);
  pinMode(pinIn2, OUTPUT);
  pinMode(pinPotenciaMotor2, OUTPUT);
  pinMode(pinIn3, OUTPUT);
  pinMode(pinIn4, OUTPUT);
	servo.attach(pinServo);
  pinMode(pinTrigger,OUTPUT);
  pinMode(pinEcho,INPUT);
	pinMode(pinSL1, INPUT);
	pinMode(pinSL2, INPUT);
	ir=ir(pinIR);
}

void SebaBot::setSerial(int baudRate){
	serialBaudRate=baudRate;
}


