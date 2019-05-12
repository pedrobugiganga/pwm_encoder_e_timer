
#include <RotaryEncoder.h>
#define saida_pwm 9

//Pinos de ligacao do encoder
RotaryEncoder encoder(A2, A3);

int valor = 0;
int newPos = 0;
int value;

void setup()
{
  Serial.begin(9600);
  Serial.println("Gire o encoder....");
  pinMode(saida_pwm, OUTPUT);
}

void loop()
{

  //Le as informacoes do encoder
  static int pos = 0;
  encoder.tick();
  int newPos = encoder.getPosition();
  value = newPos * 12;

  if(value >= 256){ value = 256;
  value--;}

 if(value <= 0){ value = 0;}

 analogWrite(saida_pwm, value); 
 

  if (pos != newPos) {
    Serial.print(value);
    Serial.println();
    pos = newPos;
  }
}
