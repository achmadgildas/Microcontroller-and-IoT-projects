//program ini udah berhasil, tapi fungsi air masih belum jalan
//pada 16 Agustus, aku mencoba untuk menghilangkan detach servonya.
//aku juga mencoba melepas RTCnya
//selanjutnya perbaiki threshold air dan pelajari tentng core sleep mode
//atau pelajari untuk membuat program berjalan air dan pakan bergantian
//pada 17 Agustus, aku mencoba membedakan ground untuk servo, 
//hasilnya fungsi air dan fungsi pakan dapat berjalan
//selanjutnya aku akan mencoba untuk memasukkan program blink dan RTC
//pada 18 Agustus, program untuk blink sudah berhasil


//BLYNK
#define BLYNK_TEMPLATE_ID "TMPLz-zA-pvD"
#define BLYNK_DEVICE_NAME "M0n1t0r1ng Pakan dan Minum Burung"
#define BLYNK_AUTH_TOKEN "cOwlWpZIyxTgIHZe1TjbDCRLQ8F4qj6p"
#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Telekomunity Zone";
char pass[] = "labtelkom";

//FlagUntukNotif
bool log_Pkosong_terkirim = false;
bool log_Psetengah_terkirim = false;
bool log_Pseperempat_terkirim = false;
bool log_Akosong_terkirim = false;
bool log_Asetengah_terkirim = false;
bool log_Aseperempat_terkirim = false;
bool pengisian_air = false;

//SERVO
#include <ESP32Servo.h>
Servo servoPakan;
Servo servoAir;

 
int pos=0;
int Pos=0;

//LDR
const int pin_ldr = 34;    
int nilai_ldr;
const int threshold1 = 0;   
//WATERLEVEL
const int pin_waterlevel = 35;
int nilai_waterlevel;
const int threshold2 = 180;

// ULTRASONIK PAKAN
#define echoPin 25  //Echo Pin
#define trigPin 33  //Trigger Pin
float duration, jarak, ketinggian_pakan;
float jarak_dasar = 19;
float panjang = 5, lebar = 5;
float kuantitas;


// ULTRASONIK AIR
#define EchoPin 26 //Echo Pin
#define TrigPin 27 //Trigger Pin
float Duration, Jarak, ketinggian_air;
float Jarak_dasar = 10;
float Panjang = 8, Lebar = 8;
float Kuantitas;

TaskHandle_t Task1;

void loop2( void * parameter )
{
  for (;;) {
   nilai_ldr = analogRead(pin_ldr);
      nilai_waterlevel = analogRead(pin_waterlevel);
  //ULTRASONIK PAKAN
  digitalWrite(trigPin, LOW);delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  jarak = duration/58.2;
  ketinggian_pakan = jarak_dasar - jarak;
  kuantitas = panjang * lebar * ketinggian_pakan;
/*
//PROSES CEK PAKAN
if(kuantitas <= 25){if(kuantitas <= 25 && log_Pkosong_terkirim == false )
   { Blynk.logEvent("pakan_dalam_tangki_habis");
   Serial.println("pakan kosong");
   log_Pkosong_terkirim = true;}
   else if (kuantitas > 25)
   { log_Pkosong_terkirim = false;}}
else if(kuantitas <= 87){if(82 > kuantitas <= 87 && log_Pseperempat_terkirim == false )
   { Blynk.logEvent("pakan_dalam_tangki_tinggal_seperempat",
   String("volume pakan: ")+kuantitas);
   Serial.println("pakan tinggal seperempat");
   log_Pseperempat_terkirim = true;}
   else if (kuantitas >= 82 && kuantitas > 87)
   { log_Pseperempat_terkirim = false;}}
else if (kuantitas <= 175){if(170 > kuantitas <= 175 && log_Psetengah_terkirim == false )
   { Blynk.logEvent("pakan_dalam_tangki_tinggal_setengah",
   String("volume pakan: ")+kuantitas);
   Serial.println("pakan tinggal setengah");
   log_Psetengah_terkirim = true;}
   else if (kuantitas >= 170 && kuantitas > 175)
   { log_Psetengah_terkirim = false;}}
   */

//SERIAL PRINT
  Serial.print("nilai Waterlevel: ");
  Serial.println(nilai_waterlevel);
  Serial.print("nilai LDR: ");
  Serial.println(nilai_ldr);
  Serial.print("jarak ultrasonik pakan: ");
  Serial.println(jarak);
  Serial.print("ketinggian pakan: ");
  Serial.println(ketinggian_pakan);
  Serial.print("volume sisa pakan: ");
  Serial.println(kuantitas);
  Serial.print("jarak ultrasonik air: ");
  Serial.println(Jarak);
  Serial.print("ketinggian air: ");
  Serial.println(ketinggian_air);
  Serial.print("volume sisa air: ");
  Serial.println(Kuantitas);

  Serial.print("pengisian_air: ");
  Serial.println(pengisian_air);
  
  Serial.println();
  
    delay(100);
  //KONDISI UNTUK PAKAN
  if (kuantitas <= 25){Serial.println("pakan dalam tangki habis");
  Serial.println();
   for(pos=30;pos<=90;pos++){
    servoPakan.write(pos);
    delay(1);}
   // notif_pakan_kosong();
  } 
  else if (kuantitas > 25){   
    if(nilai_ldr > threshold1){
       //servoAir.detach();
  
  // BUKA KATUP PAKAN
  for(pos=90;pos>=30;pos-=1){
    servoPakan.write(pos);
    delay(1);
  }
  delay(1000);
  
  // TUTUP KATUP PAKAN
  for(pos=30;pos<=90;pos+=1){
    servoPakan.write(pos);
    delay(1);
  }
  delay(1000);
  Serial.println("pakan telah ditambahkan");
  }}
  
delay (3000);
 
  }
}



void setup() {
//BLYNK
  Blynk.begin(auth, ssid, pass);
  
//SERVO
  ESP32PWM::allocateTimer(0);
  ESP32PWM::allocateTimer(1);
  ESP32PWM::allocateTimer(2);
  ESP32PWM::allocateTimer(3);
  Serial.begin(9600);
  servoPakan.setPeriodHertz(50);
  servoAir.setPeriodHertz(50);
  servoAir.attach(12);
  servoPakan.attach(32);

   pinMode(pin_ldr, INPUT);
   pinMode(pin_waterlevel, INPUT);
   analogReadResolution(9);
   
   //HC-SR04
   pinMode(trigPin, OUTPUT);
   pinMode(echoPin, INPUT);
   pinMode(TrigPin, OUTPUT);
   pinMode(EchoPin, INPUT);
  
  // Initialize your task (2nd loop)
  xTaskCreatePinnedToCore(
    loop2,          // name of the task function
    "buttonCheck",  // name of the task
    1000,           // memory assigned for the task
    NULL,           // parameter to pass if any
    1,              // priority of task, starting from 0(Highestpriority) *IMPORTANT*( if set to 1 and there is no activity in your 2nd loop, it will reset the esp32)
    &Task1,         // Reference name of taskHandle variable
    0);             // choose core (0 or 1)


}

void loop() {

   
   //ULTRASONIK AIR
  digitalWrite(TrigPin, LOW);delayMicroseconds(2);
  digitalWrite(TrigPin, HIGH);delayMicroseconds(10);
  digitalWrite(TrigPin, LOW);
  Duration = pulseIn(EchoPin, HIGH);
  Jarak = Duration/58.2;
  ketinggian_air = Jarak_dasar - Jarak;
  Kuantitas = Panjang * Lebar * ketinggian_air;
/*
delay(100);
//PROSES CEK AIR
if(Kuantitas <= 64){if(Kuantitas <= 64 && log_Akosong_terkirim == false )
   { Blynk.logEvent("air_dalam_tangki_habis");
   Serial.println("air kosong");
   log_Akosong_terkirim = true;}
   else if (Kuantitas > 64)
   { log_Akosong_terkirim = false;}}
else if(Kuantitas <= 114){ if( 110 > Kuantitas <= 114 && log_Aseperempat_terkirim == false )
   { Blynk.logEvent("air_dalam_tangki_tinggal_seperempat",
   String("volume air: ")+Kuantitas+String("ml"));
   Serial.println("air tinggal seperempat");
   log_Aseperempat_terkirim = true;}
   else if (Kuantitas >= 110 && Kuantitas > 114)
   { log_Aseperempat_terkirim = false;}}
else if(Kuantitas <= 164){if( 160 > Kuantitas <= 164 && log_Asetengah_terkirim == false )
   { Blynk.logEvent("air_dalam_tangki_tinggal_setengah",
   String("volume air: ")+Kuantitas+String("ml"));
   Serial.println("air tinggal setengah");
   log_Asetengah_terkirim = true;}
   else if (Kuantitas >= 160 && Kuantitas > 164)
   { log_Asetengah_terkirim = false;}}
*/
  //KONDISI UNTUK AIR
  if (Kuantitas <= 64){Serial.println("air dalam tangki habis");
  Serial.println();
     
    }
  else if (Kuantitas > 64){ 
   if (nilai_waterlevel >= threshold2 )
 {
    //TUTUP KATUP AIR
   for(Pos=47;Pos>=0;Pos-=1){
    servoAir.write(Pos); 
    delay(1);
  } 
  Serial.println("air masih penuh");
  pengisian_air = false;}
  
    else if(nilai_waterlevel <= threshold2 && pengisian_air == false )
 { //BUKA KATUP AIR
     //servoPakan.detach();
    for(Pos=0;Pos<=47;Pos+=1){
      servoAir.write(Pos);
      delay(1);
    }
 Serial.println("air sudah diisi");
   pengisian_air = true;}
  
  }
  
  //servoAir.detach();
  delay (3000); 
   Blynk.virtualWrite(V0, kuantitas);
  Blynk.virtualWrite(V1, Kuantitas);
  Blynk.run(); 
}
