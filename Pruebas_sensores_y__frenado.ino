#include "tatubot.h"
int a = 0;
/*boolean sensor0DetectaNegro = analogRead(A8)< 460;
boolean sensor0DetectaBlanco = analogRead(A8)> 460;
boolean sensor1DetectaNegro = analogRead(A9)< 460;
boolean sensor1DetectaBlanco = analogRead(A9)> 460;
*/

Motor motor0(IN1, IN2, ENA);
Motor motor1(IN4, IN3, ENB);
void setup() {
 
  Serial.begin(115200);
  motor0.iniciar();
  motor1.iniciar();

}

void loop() {
  a = 0;
  Serial.print("sensor rueda 0: ");
  Serial.println(analogRead(A8));
  Serial.print("sensor rueda 1: ");
  Serial.println(analogRead(A9));

  
  for(int j=0; j<1000; j++)
  {
        if (sensor0DetectaNegro() && sensor1DetectaBlanco())
        {
            Serial.println("Entre al if donde el sensor 0 esta en negro y el 1 en blanco");
            while(!sensor1DetectaNegro())
            {
              Serial.println("Entre al while de movimiento para que el sensor1 alcanze al 0");
              motor0.parar();
              motor1.adelante(70);
             }
              a = 1;        
        }
        if ( sensor1DetectaNegro() && sensor0DetectaBlanco())
        {
            Serial.println("Entre al if donde el sensor 1 esta en negro, el 0 en blanco ademas no se dio la opcion del anterio if");
            while(!sensor0DetectaNegro())
            {
              Serial.println("Entre al while para que el sensor 0 alcanze al 1");
              motor1.parar();
              motor0.adelante(70);
             }
             a = 1;
        }
    
        motor0.adelante(70);
        motor1.adelante(70);
        delay(5);
  }
  motor0.parar();
  motor1.parar();
  delay(5000);
}

boolean sensor0DetectaNegro(){
  return  analogRead(A8)< 300;
}
boolean sensor0DetectaBlanco(){
  return  analogRead(A8)> 301;
}
boolean sensor1DetectaNegro(){
  return  analogRead(A9)< 300;
}
boolean sensor1DetectaBlanco(){
  return  analogRead(A9)> 301;
}

//---------------------------------------------
Motor::Motor(byte pinAtras, byte pinAdelante, byte pinVelocidad) {
  this->pinAtras = pinAtras;
  this->pinAdelante = pinAdelante;
  this->pinVelocidad = pinVelocidad;
}

void Motor::iniciar() {
  pinMode(pinAtras, OUTPUT);
  pinMode(pinAdelante, OUTPUT);
  pinMode(pinVelocidad, OUTPUT);
  this->parar();
}

void Motor::adelante(int velocidad) {
  analogWrite(pinVelocidad, velocidad);
  digitalWrite(pinAtras, LOW);
  digitalWrite(pinAdelante, HIGH);
}

void Motor::atras(int velocidad) {
  analogWrite(pinVelocidad, velocidad);
  digitalWrite(pinAdelante, LOW);
  digitalWrite(pinAtras, HIGH);
}

void Motor::parar() {
  analogWrite(pinVelocidad, 0);
}


//-------------------------------------------------------
