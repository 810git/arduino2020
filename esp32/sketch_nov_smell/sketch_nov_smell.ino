#define PIN_HEATER 14 // D14(A0)
#define PIN_SENSOR 15 // D15(A1)
#define PIN_OUTPUT 34 // A3
void setup() {
 pinMode(PIN_HEATER,OUTPUT);
 pinMode(PIN_SENSOR,OUTPUT);
 digitalWrite(PIN_HEATER,HIGH); // Heater Off
 digitalWrite(PIN_SENSOR,LOW); // Sensor Pullup Off

 Serial.begin(9600);
}
void loop() {
 int val=0;
 float valflo=0;
 float vout=0;
 float resultflo=0;

 delay(237);
 digitalWrite(PIN_SENSOR,HIGH); // Sensor Pullup On
 delay(3);
 val = analogRead(PIN_OUTPUT); // Get Sensor Voltage
 valflo = analogRead(PIN_OUTPUT); // Get Sensor Voltage
 delay(2);
 digitalWrite(PIN_SENSOR,LOW); // Sensor Pullup Off

 digitalWrite(PIN_HEATER,LOW); // Heater On
 delay(8);
 digitalWrite(PIN_HEATER,HIGH); // Heater Of

 //Serial.println("---------------------");
 //Serial.println(val);
 
 Serial.println("maybe..voltage");
 Serial.println(valflo/4096*5);
 //Serial.print((5 - valflo/4096*5) * 1000 /valflo/4096*5);
 //not good ? vout = valflo/4096*5;
 vout = 5 - valflo/4096*5;
 
 resultflo = (5 - vout)/vout * 1000 / (56*1000 *   70);
 
 //Serial.print(resultflo , 8);
 //Serial.println("   QQQQ");
 //Serial.println(resultflo , 8);

 float valfix=100000;

 //Serial.print(resultflo, 8);
 Serial.println("   /R0 desu");
 Serial.println(resultflo , 8);
 
 //Serial.println("---------------------");

}
