/*  Demo zum Anschluß eines unipolaren Stepmotors 28BYJ-48
 *  mit Verwendung einer Beschleunigungsrampe
 *      Danke an 'agmue' vom arduino.cc Forum für dieses Beispiel
*/
#include <MobaTools.h>
Stepper4 Step1(4096);           // HALFSTEP ist default
EggTimer delayTime;


void setup() {
  Step1.attach( 4, 5, 6, 7 ); // Anschluß an digitalen Ausgängen; Treiber IN1,IN2,IN3,IN4
  //Step1.attach( SPI_1 );        // alternativ über SPI
  Step1.setSpeed( 240 );        // = 24 U/Min
  Step1.setRampLen(500);        // Beschleunigung
  Step1.setZero();              // Referenzpunkt f�r Motor 1 setzen
}

void loop() {
  static byte status;               // Schrittkettenstatus

  switch (status) {
    case 0:
      if ( !delayTime.running() ) {     // warten bis delay-Zeit abgelaufen ist
        Step1.write(360);                 // 1 Umdrehung zur�ck
        status++;
      }
      break;
    case 1:
      if ( !Step1.moving() ) {          // warten bis die Bewegung abgeschlossen ist
        delayTime.setTime(1000);        // Timer aufziehen
        status++;
      }
      break;
    case 2:
      if ( !delayTime.running() ) {     // warten bis delay-Zeit abgelaufen ist
        Step1.write(0);                 // 1 Umdrehung zur�ck
        status++;
      }
      break;
    case 3:
      if ( !Step1.moving() ) {          // warten bis die Bewegung abgeschlossen ist
        delayTime.setTime(1000);        // Timer aufziehen
        status++;
      }
      break;
    default:
      status = 0;
  }
}
