#include <IRremote.h>

const int up = 96;
const int down = 97;
const int rigth = 98;
const int left = 101;

const int bluePin = 6;     
const int greenPin = 5;        
const int redPin = 4; 
int IR_rcv;
bool no_comunication = true;

void setup() {
  Serial.begin(115200);
  Serial.println("IR Receive test");
  IrReceiver.begin(7, ENABLE_LED_FEEDBACK);
  pinMode(redPin, OUTPUT);     
  pinMode(greenPin, OUTPUT);     
  pinMode(bluePin, OUTPUT); 
}

void loop() {
  no_comunication = true;
  if (IrReceiver.decode()) {
    IR_rcv = IrReceiver.decodedIRData.command;
    Serial.println(IR_rcv);
    if (IR_rcv == 96) {
      Serial.println("UP");
      digitalWrite(redPin, HIGH);     
      digitalWrite(greenPin,LOW);     
      digitalWrite(bluePin, LOW);     
      no_comunication = false;    
    } else if (IR_rcv == 97) {
      Serial.println("DOWN");
      digitalWrite(redPin, LOW);     
      digitalWrite(greenPin, HIGH);     
      digitalWrite(bluePin, LOW);     
      no_comunication = false;    
    } else if (IR_rcv == 98) {
      Serial.println("RIGHT");
      digitalWrite(redPin, LOW);     
      digitalWrite(greenPin,LOW);     
      digitalWrite(bluePin, HIGH);     
      no_comunication = false;    
    } 
    IrReceiver.resume();
  } else {
    digitalWrite(redPin, LOW);     
    digitalWrite(greenPin,LOW);     
    digitalWrite(bluePin, LOW); 
  }
  delay(200);
}