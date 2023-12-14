// C++ code
#include <Servo.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h> 


#define DHTTYPE DHT11
#define DHTPIN A0

LiquidCrystal_I2C lcd(0x27,16,2);  


int servo = 4;
Servo miServo;

void setup()
{
  // SERVOMOTOR
  pinMode(servo, OUTPUT);
  miServo.attach(servo);

  // Inicializamos el objeto lcd
  lcd.init();
  //Encendemos la luz de fondo.
  lcd.backlight();


 //myservo.attach(0);
  pinMode(3,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(7,OUTPUT); 
  pinMode(6, INPUT);
  Serial.begin(9600);

}

void loop()
{
  digitalWrite(7,HIGH);
  delay(100);       // milisegundos
  digitalWrite(7,LOW);
  
                                          
  float distancia = (pulseIn(6,HIGH)/58.2)-4.3;
  Serial.println(distancia);
  
   //Sensor proximida
  if(distancia<100){
    digitalWrite(2,HIGH);
    digitalWrite(3,LOW);
  
    miServo.write(0); //

    lcd.setCursor(0,0);
    lcd.print("Dist: "+String(distancia)+"cm");

   //PRUEBAA PARA SABER EL ANGULO DEL SERVO
    lcd.setCursor(0,1);
    lcd.print(miServo.read());
    delay(2000);

 }else{ 
    digitalWrite(2,LOW);
    digitalWrite(3,HIGH);
    miServo.write(90); //

    lcd.setCursor(0,0);
    lcd.print("Dist: "+String(distancia)+"cm");
    lcd.setCursor(0,1);
    lcd.print(miServo.read());
    delay(2000);

}
}