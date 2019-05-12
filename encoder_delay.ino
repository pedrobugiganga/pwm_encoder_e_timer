
#include <RotaryEncoder.h>
#define saida 9

//Pinos de ligacao do encoder
RotaryEncoder encoder(A2, A3);

int valor = 0;
int newPos = 0;
int value = 500;

void read_encoder ();
void read_encoder2 ();

void setup()
{
  Serial.begin(9600);
  Serial.println("Gire o encoder....");
  pinMode(saida, OUTPUT);
  pinMode(2,INPUT_PULLUP);
  pinMode(3,INPUT_PULLUP);
  
  attachInterrupt(digitalPinToInterrupt(2),read_encoder, FALLING);
  attachInterrupt(digitalPinToInterrupt(3),read_encoder2,FALLING);
}

void loop()
{
    Serial.println("Valor no loop");
    Serial.println();
    Serial.print(value);
    Serial.println();
 digitalWrite(saida, HIGH);
 delay(value);
 digitalWrite(saida, LOW);
 delay(value);

  }


void read_encoder (){

 value = value + 100;
}

void read_encoder2 (){

 value = value - 100;
}
