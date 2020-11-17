#define PIN_HEATER 14 // D14(A0)
#define PIN_SENSOR 15 // D15(A1)
#define PIN_OUTPUT 34 // A3 for esp32
void setup() {
 pinMode(PIN_HEATER,OUTPUT);
 pinMode(PIN_SENSOR,OUTPUT);
 
 digitalWrite(PIN_HEATER,HIGH); // Heater Off
 digitalWrite(PIN_SENSOR,LOW); // Sensor Pullup Off

 Serial.begin(9600);
}
void loop() {
  int val=0;
  //float val=0; not good ?
  float voutka=0;
  float rs=0;
  float rl=27;// OK?

  delay(237);
  digitalWrite(PIN_SENSOR,HIGH); // Sensor Pullup On 
  delay(3);
  val = analogRead(PIN_OUTPUT); // Get Sensor Voltage 
  voutka = 3.3 - val * 3.3 /4096; // Vout ? for esp32 0-4096max / 0-3.3Voltage
  delay(2);
  digitalWrite(PIN_SENSOR,LOW); // Sensor Pullup Off
  
  digitalWrite(PIN_HEATER,LOW); // Heater On 
  delay(8);
  digitalWrite(PIN_HEATER,HIGH); // Heater Off
 

  //Serial.println(val,8);
  //Serial.println(voutka,8);
  rs = (3.3 - voutka) / voutka * rl;
  Serial.println(rs,8);

  //R0 = 7.05 ohm ? air ? 70.5 ohm for ethanol?
  Serial.println(rs/70.5,8);

}
