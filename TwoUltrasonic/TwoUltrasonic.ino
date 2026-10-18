const int triggerDerecha = A1;
const int echoDerecha = A0;

const int triggerAdelante = A2;
const int echoAdelante = A3;

int IN1 = 5;
int IN2 = 6;
int IN3 = 9;
int IN4 = 10;




void setup() {
  pinMode(triggerDerecha, OUTPUT);
  pinMode(echoDerecha, INPUT);

  pinMode(triggerAdelante, OUTPUT);
  pinMode(echoAdelante, INPUT);

  pinMode(IN2, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  detenerMotores();

  Serial.begin(9600);
}




void loop() {

  float distanciaDerecha = medirDistancia(triggerDerecha, echoDerecha);
  delay(20);
  float distanciaAdelante = medirDistancia(triggerAdelante, echoAdelante);
  delay(20);


  const int DETECCION = 25;

  bool rivalDerecha = (distanciaDerecha > 0) && (distanciaDerecha <= DETECCION);
  bool rivalAdelante = (distanciaAdelante > 0) && (distanciaAdelante <= DETECCION);
  bool rivalDerechaAdelante = rivalDerecha && rivalAdelante;


  if (rivalDerechaAdelante) {
    avanzar();
  }

  else if (rivalAdelante) {
    avanzar();
  }

  else if (rivalDerecha) {
    girarDerecha();
  }

  else {
    girarIzquierda();
  }


  Serial.print("Der: ");
  Serial.print(distanciaDerecha);

  Serial.print("  Adel: ");
  Serial.println(distanciaAdelante);

  Serial.print("\n");

  delay(200);
}




float medirDistancia(int trigger, int echo) {
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);


  long tiempo = pulseIn(echo, HIGH, 30000);

  if (tiempo == 0) {
    return 1;

  }
  return tiempo * 0.034 / 2.0;
}


// ================================================

void retroceder() {
  analogWrite(IN4, 200);
  analogWrite(IN3, 0);

  analogWrite(IN2, 200);
  analogWrite(IN1, 0);
}


void avanzar() {
  analogWrite(IN4, 0);
  analogWrite(IN3, 200);

  analogWrite(IN2, 0);
  analogWrite(IN1, 200);
}


void detenerMotores() {
  analogWrite(IN4, 0);
  analogWrite(IN3, 0);

  analogWrite(IN2, 0);
  analogWrite(IN1, 0);
}


void girarIzquierda() {
  analogWrite(IN4, 0);
  analogWrite(IN3, 0);

  analogWrite(IN2, 0);
  analogWrite(IN1, 0);
}



void girarDerecha() {
  analogWrite(IN4, 0);
  analogWrite(IN3, 0);

  analogWrite(IN2, 0);
  analogWrite(IN1, 0);
}