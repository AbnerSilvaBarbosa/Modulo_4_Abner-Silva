#define red 21
#define green 19
#define blue 18
#define yellow 5
#define buzzer 23
#define LRD 14
#define btnGreen 33
#define btnBlue 32

int binario[4];
int freqs[100];
int x = 0;


void convert(int valor) {
  int i = 0;

  while (i != 4)
  {
    binario[i] = valor % 2;
    valor = valor / 2;
    i++;
  }
}

void setup() {

  Serial.begin(115200);

  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(yellow, OUTPUT);

  pinMode(buzzer, OUTPUT);
  pinMode(LRD, INPUT);

  pinMode(btnGreen, INPUT_PULLUP);
  pinMode(btnBlue, INPUT_PULLUP);


}

void armazena(int freq) {
  freqs[x] = freq;
  x += 1;
  tone(buzzer, freq * 100, 250);
}

void music() {
  Serial.println(x);
  while (x >= 0) {
    tone(buzzer, freqs[x] * 100, 250);
    x = x - 1;
  }
}

void leds() {
  if (binario[3] == 1) {
    digitalWrite(red, HIGH);
  } else {
    digitalWrite(red, LOW);
  }

  if (binario[2] == 1) {
    digitalWrite(green, HIGH);
  } else {
    digitalWrite(green, LOW);
  }

  if (binario[1] == 1) {
    digitalWrite(blue, HIGH);
  } else {
    digitalWrite(blue, LOW);
  }

  if (binario[0] == 1) {
    digitalWrite(yellow, HIGH);
  } else {
    digitalWrite(yellow, LOW);
  }

}

void loop() {

  int lrd = analogRead(LRD);

  int NumberDecimal = (lrd / 273);
  convert(NumberDecimal);

  leds();

  if (digitalRead(btnGreen) == LOW) {
    armazena(lrd / 273);
  }

  if (digitalRead(btnBlue) == LOW) {
    music();
  }

  delay(200);






}
