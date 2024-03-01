
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "7UD**************************";

// Your WiFi credentials.
// Set password to "" for open networks.

char ssid[] = "************";
char pass[] = "***********";


// #include<ESP8266WiFi.h>
// #include<BlynkSimpleEsp8266.h>

#define BLYNK_TEMPLATE_ID "********"
#define BLYNK_TEMPLATE_NAME "iot smart rack system"
#define BLYNK_AUTH_TOKEN "***********"                                                               

const int sen = A0;
const float gravity=9.81;
void setup() {

  Serial.begin(9600);    //Start serial monitor

  pinMode(A0,INPUT);
  pinMode(D0, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  Blynk.begin(auth, ssid, pass);
  
}
const int adcRange = 500;       // ADC range for weight measurement
const int weightRange = 500;    // Weight range in grams
const int weightThreshold = 10; // Minimum weight change to update Blynk app
float previousWeight = 0.0;     // Previous weight value

void loop() {
  
Blynk.run();
int value_force = analogRead(sen);                  

 //Wait for sensor
 digitalWrite(D0, 0);
 
 digitalWrite(D1, 0);
 
 digitalWrite(D2, 0);

float weight = map(value_force, 0, adcRange, 0, weightRange);
// float weightgram = (weight/gravity)*10; 
// delay(100);

   Serial.print("weight = ");   
   Serial.print(weight);
   Blynk.virtualWrite(V2, weight);
   
   delay(500);
   
  Serial.print(" weight in gram = ");   
  Serial.println(weight);

  if (weight < 100)
   {
    digitalWrite(D0, 1);
    delay(2000);
  }
  else if (weight >= 100 && weight < 300) 
  {
    digitalWrite(D0, 1);
    digitalWrite(D1, 1);
    delay(2000);
  }
  else
  {
    digitalWrite(D0, 1);
    digitalWrite(D1, 1);
    digitalWrite(D2, 1);
    delay(2000);
  }
}
