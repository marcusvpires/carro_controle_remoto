int motor1pin1 = 8;
int motor1pin2 = 9;

int motor2pin1 = 10;
int motor2pin2 = 11;

void setup(){
  Serial.begin(9600);
  Serial.flush();
}

void loop(){
  if (Serial.available() > 0) {  
    char rxChar = Serial.read();  
    switch (rxChar) {
      case 'w':
      case 'W':
        Serial.println("Frente");
        digitalWrite(motor1pin1, HIGH);
        digitalWrite(motor1pin2, LOW);

        digitalWrite(motor2pin1, HIGH);
        digitalWrite(motor2pin2, LOW);
        delay(1000);
        break;
      case 's':
      case 'S':
        Serial.println("Traz");
        digitalWrite(motor1pin1, LOW);
        digitalWrite(motor1pin2, HIGH);

        digitalWrite(motor2pin1, LOW);
        digitalWrite(motor2pin2, HIGH);
        delay(1000);
        break;
      case 'a':
      case 'A':
        Serial.println("Esquerda");
        digitalWrite(motor1pin1, HIGH);
        digitalWrite(motor1pin2, LOW);

        digitalWrite(motor2pin1, LOW);
        digitalWrite(motor2pin2, HIGH);
        delay(1000);
        break;
      case 'd':
      case 'D':
        Serial.println("Direita");
        digitalWrite(motor1pin1, LOW);
        digitalWrite(motor1pin2, HIGH);

        digitalWrite(motor2pin1, HIGH);
        digitalWrite(motor2pin2, LOW);
        delay(1000);
        break;
      default:
        digitalWrite(motor1pin1, LOW);
        digitalWrite(motor1pin2, LOW);

        digitalWrite(motor2pin1, LOW);
        digitalWrite(motor2pin2, LOW);        
    }
  }
}
