#include "SebaBot.h"
SebaBot::SebaBot(int ENA1, int IN1, int IN2, int ENA2, int IN3, int IN4, int SERVO, int TRIG, int ECHO, int SL1, int SL2, int IR, int BUZZER){
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
	pinBuzzer=BUZZER;
}

void SebaBot::inicio(){
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
	ir=NECIRrcv(pinIR);
}
void SebaBot::avanzar(int motor, int potencia){
	if(motor==1) {
		mueveMotorAdelante(pinIn1, pinIn2, pinPotenciaMotor1, potencia);
	} 
	if(motor==2) {
		mueveMotorAdelante(pinIn3, pinIn4, pinPotenciaMotor2, potencia);
	} 
	if(motor==3) {
		mueveMotorAdelante(pinIn1, pinIn2, pinPotenciaMotor1, potencia);
		mueveMotorAdelante(pinIn3, pinIn4, pinPotenciaMotor2, potencia);
	} 
}

void SebaBot::retroceder(int motor, int potencia){
	if(motor==1) {
		mueveMotorAtras(pinIn1, pinIn2, pinPotenciaMotor1, potencia);
	} 
	if(motor==2) {
		mueveMotorAtras(pinIn3, pinIn4, pinPotenciaMotor2, potencia);
	} 
	if(motor==3) {
		mueveMotorAtras(pinIn1, pinIn2, pinPotenciaMotor1, potencia);
		mueveMotorAtras(pinIn3, pinIn4, pinPotenciaMotor2, potencia);
	} 
}

void SebaBot::parar(int motor){
	if(motor==1) {
		pararMotor(pinIn1, pinIn2);
	} 
	if(motor==2) {
		pararMotor(pinIn3, pinIn4);
	} 
	if(motor==3) {
		pararMotor(pinIn1, pinIn2);
		pararMotor(pinIn3, pinIn4);
	} 
}

void SebaBot::mirarDerecha() {
    servo.write(0);
}

void SebaBot::mirarAdelante() {
    servo.write(90);
}

void SebaBot::mirarIzquierda() {
    servo.write(180);
}

void SebaBot::mirarALas(int horas) {
    if (horas == 3) {
		mirarDerecha();
	} else if(horas == 2) {
    	servo.write(90-30);
	} else if(horas == 1) {
    	servo.write(90-60);
	} else if(horas == 12) {
    	mirarAdelante();
	} else if(horas == 11) {
    	servo.write(90+30);
	} else if(horas == 10) {
    	servo.write(90+60);
	} else if(horas == 9) {
    	mirarIzquierda();
	}
}

bool SebaBot::hayLineaDebajoDe(int sensor) {
	int pin=pinSL1;
	if(sensor==2)
		pin=pinSL2;
	bool val = digitalRead(pin);
  	return val;
}

void SebaBot::mueveMotorAdelante(int p1, int p2, int pPot, int potencia){
	digitalWrite(p1,1);
	digitalWrite(p2,0);
	analogWrite(pPot,potencia);
}

void SebaBot::mueveMotorAtras(int p1, int p2, int pPot, int potencia){
	digitalWrite(p1,0);
	digitalWrite(p2,1);
	analogWrite(pPot,potencia);
}

void SebaBot::pararMotor(int p1, int p2){
	digitalWrite(p1,0);
	digitalWrite(p2,0);
}


void SebaBot::espera(long milisegundos){
	long fin = millis() + milisegundos;
	while(millis() < fin)_loop();
}
void SebaBot::_loop() {
}

int SebaBot::distanciaObjeto() {
	digitalWrite(pinTrigger, LOW);
 	delayMicroseconds(5);
 	digitalWrite(pinTrigger, HIGH);
 	delayMicroseconds(10);
 	digitalWrite(pinTrigger, LOW);
 	long duration = pulseIn(pinEcho, HIGH);
 	long cm = (duration/2) / 29.1;
   	return cm;
}

void SebaBot::buzzer(long frecuencia){
	tone(pinBuzzer, frecuencia);
}
void SebaBot::buzzer(long frecuencia, int duracion){
	tone(pinBuzzer, frecuencia, duracion);
}
void SebaBot::buzzerParar(){
	noTone(pinBuzzer);
}



void SebaBot::setSerial(int baudRate){
	serialBaudRate=baudRate;
}


