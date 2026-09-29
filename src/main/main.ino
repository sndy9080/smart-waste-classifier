#include<Servo.h>
// Inisialisasi Pin Sensor
int trigPin = 13;
int echoPin = 12;
int MQ2 = A0;
int MQ135 = A1;
int Inductive = 11;
int LDR = A3;
int laser = 7;
int Capacitive = 8;

//Jarak Maksimal Sensor Ultrasonic
#define maxdistance 50

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;

void setup()
{
  // Inisialisasi Input-Output
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(MQ2, INPUT);
  pinMode(MQ135, INPUT);

  pinMode(Inductive, INPUT);

  pinMode(LDR, INPUT);
  pinMode(laser, OUTPUT);

  pinMode(Capacitive, INPUT);

  // Pengkoneksian Pin servo pada Papan Arduino
  servo1.attach(6); // Penutup Tempat Sampah
  servo2.attach(5); // Sensor Sampah Berbahaya
  servo3.attach(4); // Sensor Sampah Logam
  servo4.attach(3); // Sensor Sampah Kertas
  servo5.attach(2); // Sensor Sampah Organik

  Serial.begin(9600);
}

void loop()
{
  // Ultrasonic Sensor
  digitalWrite(trigPin, LOW); //Menyamakan trigPin ke LOW untuk membersihkan nilai
  delay(500); // Menunggu selama 500 milidetik(s)

  digitalWrite(trigPin, HIGH); // Set trigPin to HIGH
  delay(500); // Menunggu selama 1000 milidetik(s)

  digitalWrite(trigPin, LOW); // Kembali ke LOW

  // Mengukur Durasi getaran yang diterima (pulsed echo) menggunakan pulseIn()
  int d = pulseIn(echoPin, HIGH);

  // Mengonversi durasi getaran menjadi jarak (cm), menggunakan rumus kecepatan gelombang suara
  d = d/ 29/ 2;

  Serial.println(" ---------------------------- ");
  Serial.print  ("|        Jarak : ");
  Serial.print(d);
  Serial.println(" cm       |");
  Serial.println(" ---------------------------- ");
  Serial.println(" ");
  
  // Penutup Tempat sampah
  if( d <= maxdistance )
  {
    servo1.write(0); //if jarak <= maxdistance_servo1, maka servo diposisikan ke 0 derajat
    delay(5000); // Tunggu selama 5000 milidetik
    servo1.write(90); // Kembali ke-posisi semula
    delay(500);

    //Sensor Pendeteksi Sampah B3
    int value_MQ2 = analogRead(MQ2); // Mengukur nilai Sensor MQ2
    delay(10);
    
    int value_MQ135 = analogRead(MQ135); // Mengukur nilai Sensor MQ135
    delay(10);

    if( value_MQ2 >= 100 || value_MQ135 >= 100 ) {
      Serial.println(" ----------------------------- ");
      Serial.println("| Terdeteksi Sampah Berbahaya |");
      Serial.println(" ----------------------------- ");
      Serial.print  ("   Nilai Sensor MQ-2   : ");
      Serial.println(value_MQ2);

      Serial.print  ("   Nilai Sensor MQ-135 : ");
      Serial.println(value_MQ135);
      Serial.println(" ---------------------------- ");
      Serial.println(" ");
      
      servo2.write(180); // Penampung sampah ke-1 berputar ke kanan
      delay(2000); // Delay sebentar sebelum servo kembali ke posisi awal
      servo2.write(90); // Servo kembali ke posisi semula
      
    }
    else {
      Serial.println(" ---------------------------- ");
      Serial.println("|   Terdeteksi Sampah Aman   |");
      Serial.println(" ---------------------------- ");
      Serial.print  ("   Nilai Sensor MQ-2   : ");
      Serial.println(value_MQ2);
      
      Serial.print  ("   Nilai Sensor MQ-135 : ");
      Serial.println(value_MQ135);
      Serial.println(" ---------------------------- ");
      Serial.println(" ");
     
      servo2.write(0); // Penampung sampah ke-1 berputar ke kiri
      delay(2000); // Delay sebentar sebelum servo kembali ke posisi awal
      servo2.write(90); // Servo kembali ke posisi semula
      delay(500);
      
      //Sensor Sampah Logam
      int inductiveValue = digitalRead(Inductive);
      if(inductiveValue == HIGH) {
        Serial.println(" ---------------------------- ");
        Serial.println("|  Terdeteksi Sampah Logam   |");
        Serial.println(" ---------------------------- ");
        Serial.println(" ");

        servo3.write(180); // Penampung sampah ke-2 berputar ke kanan
        delay(2000); // Delay sebentar sebelum servo kembali ke posisi awal
        servo3.write(90); // Servo kembali ke posisi semula
      }
      else {
        Serial.println(" ----------------------------- ");
        Serial.println("| Terdeteksi Sampah Non Logam |");
        Serial.println(" ----------------------------- ");
        Serial.println(" ");

        servo3.write(0); // Penampung sampah ke-2 berputar ke kiri
        delay(2000); // Delay sebentar sebelum servo kembali ke posisi awal
        servo3.write(90); // Servo kembali ke posisi semula
        delay(500);

        //Sensor Kertas
        digitalWrite(laser, HIGH); // laser dihidupkan
        int ldr_value = analogRead(LDR);
        if(ldr_value <= 200 && ldr_value >= 80 ){
          Serial.println(" ---------------------------- ");
          Serial.println("|  Terdeteksi Sampah Kertas  |");
          Serial.println(" ---------------------------- ");
          Serial.print  ("       Nilai Sensor : ");
          Serial.println(ldr_value);
          
          Serial.println(" ---------------------------- ");
          Serial.println(" ");
          
          servo4.write(180); // Penampung sampah ke-3 berputar ke kanan
          delay(2000); // Delay sebentar sebelum servo kembali ke posisi awal
          digitalWrite(laser, LOW); //Laser dimatikan
          servo4.write(90); // Servo kembali ke posisi semula
        }
        else {
          Serial.println(" ---------------------------- ");
          Serial.println("|     Bukan Sampah Kertas    |");
          Serial.println(" ---------------------------- ");
          Serial.print  ("       Nilai Sensor : ");
          Serial.println(ldr_value);
          
          Serial.println(" ---------------------------- ");
          Serial.println(" ");
          
          servo4.write(0); // Penampung sampah ke-3 berputar ke kiri
          delay(2000); // Delay sebentar sebelum servo kembali ke posisi awal
          digitalWrite(laser, LOW); // Laser dimatikan
          servo4.write(90); // Servo kembali ke posisi semula
          delay(500);

          //Sensor Organik
          int capacitive_value = digitalRead(Capacitive);
          if(capacitive_value == HIGH){
            Serial.println(" ---------------------------- ");
            Serial.println("| Terdeteksi Sampah Organik  |");
            Serial.println(" ---------------------------- ");
            Serial.println(" ");
            
            servo5.write(180); // Penampung sampah ke-4 berputar ke kanan
            delay(2000); // Delay sebentar sebelum servo kembali ke posisi awal
            servo5.write(90); // Servo kembali ke posisi semula
          }
          else {
            Serial.println(" ---------------------------- ");
            Serial.println("|        Sampah Residu       |");
            Serial.println(" ---------------------------- ");
            Serial.println(" ");
            
            servo5.write(0); // Penampung sampah ke-4 berputar ke kiri
            delay(2000); // Delay sebentar sebelum servo kembali ke posisi awal
            servo5.write(90); // Servo kembali ke posisi semula
            delay(500);
          }
        }
      }
    }
  }
  else{
    delay(500); // if jarak > maxdistance_servo1, maka tunggu 1 detik
    servo1.write(90); // Kemudian, servo tetap di posisi semula
  }
}