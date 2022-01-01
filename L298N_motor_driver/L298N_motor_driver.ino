 
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
        break;
      case 's':
      case 'S':
        Serial.println("Traz");
        break;
      case 'a':
      case 'A':
        Serial.println("Esquerda");
        break;
      case 'd':
      case 'D':
        Serial.println("Direita");
        break;
    }
  }
}
