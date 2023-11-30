int GreenLED=10;    //pin 10 är kopplad till gröna lampan
int YellowLED=11;   //pin 11 är kopplad till gula lampan
int RedLED=12;       //pin 12 är kopplad till röda lampan

void setup() {
//Preppa arduinon så den vet vad de olika pins:en ska vara  

//Tala om att GreenLED är en output, alltså något som skickas ut från arduinon. Motsatsen är en input.
pinMode(GreenLED,OUTPUT); 
//Tala om att YellowLED är en output
pinMode(YellowLED,OUTPUT); 
//Tala om att RedLED är en output
pinMode(RedLED,OUTPUT); 

//"Write" betyder skriva. När vi bestämmer vad en pin ska ha för värde så skriver vi till den. 
//"Digital" betyder att den bara kan ha två värden: de kallas LOW och HIGH.
//Om vi sätter den till LOW så stänger vi av lampan
digitalWrite(GreenLED,LOW); 
digitalWrite(YellowLED,LOW); 
digitalWrite(RedLED,LOW); 
 //  Serial.begin()-funktionen talar om hur snabbt vi ska skicka info: 9600 bits per seconds
Serial.begin(9600); 
}

void loop() {
//Trafikljuset är gult:

digitalWrite(GreenLED,LOW); 
digitalWrite(YellowLED,HIGH); 
digitalWrite(RedLED,LOW);
//Vi säger exakt hur många millisekunder den ska vänta. 1000 milli-sekunder är 1 sekund
delay(1000); 
//"Delay" betyder att fördröja; att vänta lite. 

//Trafikljuset är grönt:

digitalWrite(GreenLED,HIGH); 
digitalWrite(YellowLED,LOW); 
digitalWrite(RedLED,LOW); 
delay(2000);        

//Trafikljuset är rött:

digitalWrite(GreenLED,LOW);
digitalWrite(YellowLED,LOW); 
digitalWrite(RedLED,HIGH); 
delay(2000);          
}









