#ifndef sebabot_h
#define sebabot_h

#include <Arduino.h>
#include <Servo.h>
#include <NECIRrcv.h>
///@brief Class for SebaBot
class SebaBot {
	public:
		SebaBot(int ENA1, int IN1, int IN2, int ENA2, int IN3, int IN4, int SERVO, int TRIG, int ECHO, int SL1, int SL2, int IR, int BUZZER);
		void inicio();
		void avanzar(int motor, int potencia);
		void retroceder(int motor, int potencia);
		void parar(int motor);
		void setSerial(int baudRate);
		void mirarDerecha();
		void mirarAdelante();
		void mirarIzquierda();
		void mirarALas(int horas);
		bool hayLineaDebajoDe(int sensor);
		int distanciaObjeto();
		void buzzer(long frecuencia);
		void buzzer(long frecuencia, int duracion);
		void buzzerParar();
		

	private:
		void mueveMotorAdelante(int p1, int p2, int pPot, int potencia);
		void mueveMotorAtras(int p1, int p2, int pPot, int potencia);
		void pararMotor(int p1, int p2);
		void espera(long milisegundos);
		void _loop();
	
		//Motores
    	int pinPotenciaMotor1, pinIn1, pinIn2, pinPotenciaMotor2, pinIn3, pinIn4;
		int pinServo;		

		//Ultrasonido
		int pinTrigger, pinEcho;


		//Seguidores de Línea
		int pinSL1, pinSL2;

		//Receptor Infrarojo
		int pinIR;

		//Otros
		int pinBuzzer;

		//Serial
		int serialBaudRate;

		//Variables internas
		Servo servo;
		NECIRrcv ir=NECIRrcv(0);

};

#endif
