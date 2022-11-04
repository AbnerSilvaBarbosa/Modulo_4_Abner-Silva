#define red 40
#define green 47
#define blue 48
#define yellow 45
#define buzzer 12
#define LDR 5
#define btnGreen 6
#define btnBlue 15

// array para armazenar os 4 digitos em binário
int binario[4];

// array aonde cada posição armazena uma frequencia passada para o buzzer
int freqs[100];

// variavel que será utilizada para contagem do tamanho do array , nos futuros whiles
int x = 0;

// Função para fazer a converção binaria dos valores que chegarem, onde estará em um intervalo de 0 a 15
void convert(int valor) {
  int i = 0;

  while (i != 4) {
    binario[i] = valor % 2;
    valor = valor / 2;
    i++;
  }
}


void setup() {

  Serial.begin(115200);

  pinMode(red, OUTPUT);     // led vermelho
  pinMode(green, OUTPUT);   // led verde
  pinMode(blue, OUTPUT);    // led azul
  pinMode(yellow, OUTPUT);  // led amarelo

  pinMode(buzzer, OUTPUT);  // buzzer
  pinMode(LDR, INPUT);      // leitro de luz

  pinMode(btnGreen, INPUT_PULLUP);  // botão verde
  pinMode(btnBlue, INPUT_PULLUP);   // botão azul
}


// Função para armazenar a frequencia entre o intervalo de 0 a 15 , em um vetor global
// E ela toca a frequencia que foi passada para ser armazenada
// - a multiplicação por 100 da frequencia seria para ter uma frequencia relevante para ser ouvida.
void armazena(int freq) {
  freqs[x] = freq;
  x += 1;
  tone(buzzer, freq * 100, 250);
}

// Função para tocar todas as frequencias que foram armazenadas no array
void music() {
  int i = 0;
  while (i <= x) {
    tone(buzzer, freqs[i] * 100, 250);
    convert(freqs[i]);
    delay(1000);
    leds();
    i += 1;
  }
}

// Função que olha as posições do array que estão em binario , e se aquela posição do array e do led estiverem 1 ela acende
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

  // pega o valor do LDR
  int ldr = analogRead(LDR);

  // Limitando o valor do LDR entre 0 e 15, fazendo uma regra de 3 onde 0 - 4065, onde agora o valor maximo e 15
  // ficando 15 - 4065, limitando ao escopo de 0 a 15, fiquei em duvida do por que o 273
  int NumberDecimal = (ldr / 273);

  // Converte o valor de 0 a 15 para binario
  convert(NumberDecimal);

  // Função para ligar os leds de acordo com o binario
  leds();

  // Se o botão verde for precionado, ele armazena o valor atual do LDR entre 0 e 15
  if (digitalRead(btnGreen) == LOW) {
    armazena(ldr / 273);
  }

  // Se o botão azul for precionado
  if (digitalRead(btnBlue) == LOW) {
    music();
  }

  delay(200);
}