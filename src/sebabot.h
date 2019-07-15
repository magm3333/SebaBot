#ifndef sebabot_h
#define sebabot_h

#include <Arduino.h>
#include <Servo.h>
#include <NECIRrcv.h>
///@brief Class for SebaBot
class SebaBot {
	public:
		SebaBot(int ENA1, int IN1, int IN2, int ENA2, int IN3, int IN4, int SERVO, int TRIG, int ECHO, int SL1, int SL2, int IR);
		void inicio();
		void setSerial(int baudRate);

	private:
		//Motores
    int pinPotenciaMotor1, pinIn1, pinIn2, pinPotenciaMotor2, pinIn3, pinIn4;
		int pinServo;		

		//Ultrasonido
		int pinTrigger, pinEcho;


		//Seguidores de Línea
		int pinSL1, pinSL2;

		//Receptor Infrarojo
		int pinIR;

		//Serial
		int serialBaudRate;

		//Variables internas
		int potenciaMotor1, potenciaMotor2;
		Servo servo;
		NECIRrcv ir;

};

#endif
