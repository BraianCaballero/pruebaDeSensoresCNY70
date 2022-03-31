/*----------------------------------------------------------
    Librería para crear robot Tatu-bot
  ----------------------------------------------------------*/
#ifndef TATUBOT_H
#define TATUBOT_H
#include <Arduino.h>

// Motor 0
#define IN1 4 // 3 
#define IN2 5 // 2
#define ENA 3  // 5
// Motor 1
#define IN3 6 // 8 
#define IN4 23 // 7
#define ENB 7 // 9
// Matriz de Leds
#define DIN 44 // 11 
#define CLK 47 // 13 
#define CS 45 // 10
#define MATRICES 2
// Pulsadores
#define PIN_INICIO_ORDENES A0
#define PIN_FIN_ORDENES A1
#define PIN_ORDEN_AVANZAR A2
#define PIN_ORDEN_REVERSA A3
#define PIN_ORDEN_GIRO_DERECHA A5
#define PIN_ORDEN_GIRO_IZQUIERDA A4
#define PIN_RESET A6

//Led 1
#define PIN_R_A 8
#define PIN_G_A 9
#define PIN_B_A 10
//Led 2
#define PIN_R_B 11
#define PIN_G_B 12
#define PIN_B_B 13
//sensores 
#define SENSOR0 30
#define SENSOR1 29    
#define SENSOROPTICO0 A8
#define SENSOROPTICO1 A9
#define SENSOROPTICO2 31
#define SENSOROPTICO3 32


#define CANTIDAD_ORDENES 10

class Led {
  private:
    byte ledR;
    byte ledG;
    byte ledB;

   public:
    Led(byte ledR, byte ledG, byte ledB);
    void iniciar();
    void rgb(char color);
    };


class Motor {
  private:
    byte pinAtras;
    byte pinAdelante;
    byte pinVelocidad;
    
  public:
    Motor(byte pinAtras, byte pinAdelante, byte pinVelocidad);
    void iniciar();
    void adelante(int velocidad);
    void atras(int velocidad);
    void parar();
};


class Robot {
  private:
    int listaOrdenes[10];
  public:
    byte pinEscucharOrdenes = PIN_INICIO_ORDENES;
    byte pinAvanzar = PIN_ORDEN_AVANZAR;
    byte pinReversa = PIN_ORDEN_REVERSA;
    byte pinGiroDerecha = PIN_ORDEN_GIRO_DERECHA;
    byte pinGiroIzquierda = PIN_ORDEN_GIRO_IZQUIERDA;
    byte pinFinOrdenes = PIN_FIN_ORDENES;
    byte pinReset = PIN_RESET;

    
    void iniciar();
    void avanzar(int velocidad, int velocidad2);
    void movimientoAdelante(int velocidad, int velocidad2);
    void retroceder(int velocidad, int velocidad2);
    void movimientoReversa(int velocidad, int velocidad2);
    void girarDerecha();
    void movimientoDerecha();
    void girarIzquierda();
    void movimientoIzquierda();
    void detectarAmbosImanes();
    void pararRobot();
    void restarleUnoAlContadorMayor();
    void frenarAvance(float velocidad, float velocidad2);
    void frenarReversa(float velocidad, float velocidad2);
    void escucharOrdenes();
    void ejecutarTodasLasOrdenes();
    void ejecutarOrden(byte caso);
    void contador();
    void detectarLineaNegraEIgualar();
    void detectarLineaNegraEIgualarEnReversa();
    void avanzarLineaNegraConMotor_(class Motor motorAvance, class Motor motorFrenado, int sensorDelMotorDeAvance );
    void retrocederLineaNegraConMotor_( class Motor motorReversa, class Motor motorFrenado, int sensorDelMotorDeReversa ); 
    void autocorregir();
    void igualarRuedaAdelantada0();
    void igualarRuedaAdelantada1();
    void autocorregirReversa();
    void igualarRuedaAdelantadaReversa0();
    void igualarRuedaAdelantadaReversa1();
    //void corregir0(int caso);
    void dibujarCarita(byte ojos[8], byte boca[8]);
    void dibujarCaritaFeliz();
    void dibujarCaritaSorprendida();
    void dibujarCaritaEntusiasmada();
    void dibujarCaritaGuiniando();
    void dibujarCaritaTriste();
    void dibujarCaritaEnojada();
    void despertar();
};

#endif
