// ===== ULTRASONIDOS =====

// IZQUIERDA
const int triggerIzq = 3;
const int echoIzq = 2;


// CENTRO
const int triggerDerecha = A5;
const int echoDerecha = A4;

// DERECHA
const int triggerAdelante = A3;
const int echoAdelante = A2;



int IN1 = 5;
int IN2 = 6;
int IN3 = 9;
int IN4 = 10;






void setup() {
  pinMode(triggerIzq, OUTPUT);
  pinMode(echoIzq, INPUT);


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

  //delay(4000);
}





void loop() {

  //Guardar valores de distancia
  float distanciaIzquierda = medirDistancia(triggerIzq, echoIzq);
  delay(20);
  float distanciaDerecha = medirDistancia(triggerDerecha, echoDerecha);
  delay(20);
  float distanciaAdelante = medirDistancia(triggerAdelante, echoAdelante);
  delay(20);



  const int DETECCION = 25;

  bool rivalIzquierda = (distanciaIzquierda > 0) && (distanciaIzquierda <= DETECCION);
  bool rivalDerecha = (distanciaDerecha > 0) && (distanciaDerecha <= DETECCION);
  bool rivalAdelante = (distanciaAdelante > 0) && (distanciaAdelante <= DETECCION);

  bool rivalIzquierdaAdelante = rivalIzquierda && rivalAdelante;
  bool rivalDerechaAdelante = rivalDerecha && rivalAdelante;

  bool rivalIzquierdaDerecha = rivalIzquierda && rivalDerecha;
  bool rivalTodos = rivalIzquierda && rivalDerecha && rivalAdelante;



  if (rivalTodos) {
      avanzar();
  }


  else if (rivalAdelante) {
      avanzar();
  }



  else {
      detenerMotores();
  }



  // ===== Imprimir valores de distancia =====
  Serial.print("Izq: ");
  Serial.print(distanciaIzquierda);

  Serial.print("  Der: ");
  Serial.print(distanciaDerecha);

  Serial.print("  Adel: ");
  Serial.println(distanciaAdelante);


  Serial.print("\n");

  delay(400);
}



//======== FUNCION DE DETECCIÓN =========
float medirDistancia(int trigger, int echo) {
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);

  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigger, LOW);

  long tiempo = pulseIn(echo, HIGH, 30000);

  if (tiempo == 0) {
    return 30;
  }

  return tiempo * 0.034 / 2.0;
}


// ========= FUNCIONES DE MOVIMIENTO =========

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