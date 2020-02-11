
int Led = 13;
void setup() {
  pinMode(Led,OUTPUT);
  Serial.begin(9600);
  Serial.println("Enter 0 to switch Off LED and 1 to switch it On");
}

void loop() {
if(Serial.available())
  {
    int input=Serial.read();
   input=input-48;
   if(input==0)
   {
     Serial.println("LED is OFF");
     digitalWrite(Led,LOW);
   }
   else if(input==1)
   {
     Serial.println("LED is ON");
     digitalWrite(Led,HIGH);
   }
   else
   {
     Serial.println("Enter 0 to switch Off LED and 1 to switch it On");
   }
  }


}
