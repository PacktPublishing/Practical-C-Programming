float voltage;
int tempPin = 0;

void setup() {
   Serial.begin(9600);
}

void loop() {
   voltage = analogRead(tempPin);
   float tempInCelsius = voltage * 0.48828125;
   float tempinFahrenheit = (tempInCelsius*9)/5 + 32;
   Serial.print("Temperature in Celsius is: ");
   Serial.print(tempInCelsius); 
   Serial.print("*C");
   Serial.println();
   Serial.print("Temperature in Fahrenheit is: ");
   Serial.print(tempinFahrenheit); 
   Serial.print("*F");
   Serial.println();
   delay(1000); 
}
