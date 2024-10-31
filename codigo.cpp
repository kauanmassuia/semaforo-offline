// Definição dos pinos dos LEDs
const int ledVermelho = 8;
const int ledAmarelo = 9;
const int ledVerde = 10;

// Definindo os tempos de cada fase em milissegundos
const unsigned long tempoVermelho = 6000;
const unsigned long tempoAmarelo = 2000;
const unsigned long tempoVerde = 2000;
const unsigned long tempoVerdeAdicional = 2000;

unsigned long tempoAnterior = 0; // Armazena o tempo anterior para calcular o próximo
int estadoAtual = 0; // 0: vermelho, 1: amarelo, 2: verde, 3: verde adicional

void setup() {
  // Define os pinos como saídas
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
}

void loop() {
  unsigned long tempoAtual = millis();

  switch (estadoAtual) {
    case 0: // Fase Vermelho
      if (tempoAtual - tempoAnterior >= tempoVermelho) {
        tempoAnterior = tempoAtual;
        estadoAtual = 1; // Próximo estado: amarelo
      }
      digitalWrite(ledVermelho, HIGH);
      digitalWrite(ledAmarelo, LOW);
      digitalWrite(ledVerde, LOW);
      break;

    case 1: // Fase Amarelo
      if (tempoAtual - tempoAnterior >= tempoAmarelo) {
        tempoAnterior = tempoAtual;
        estadoAtual = 2; // Próximo estado: verde
      }
      digitalWrite(ledVermelho, LOW);
      digitalWrite(ledAmarelo, HIGH);
      digitalWrite(ledVerde, LOW);
      break;

    case 2: // Fase Verde
      if (tempoAtual - tempoAnterior >= tempoVerde) {
        tempoAnterior = tempoAtual;
        estadoAtual = 3; // Próximo estado: verde adicional
      }
      digitalWrite(ledVermelho, LOW);
      digitalWrite(ledAmarelo, LOW);
      digitalWrite(ledVerde, HIGH);
      break;

    case 3: // Fase Verde Adicional
      if (tempoAtual - tempoAnterior >= tempoVerdeAdicional) {
        tempoAnterior = tempoAtual;
        estadoAtual = 4; // Próximo estado: amarelo
      }
      digitalWrite(ledVermelho, LOW);
      digitalWrite(ledAmarelo, LOW);
      digitalWrite(ledVerde, HIGH);
      break;

    case 4: // Fase Amarelo (para retorno ao vermelho)
      if (tempoAtual - tempoAnterior >= tempoAmarelo) {
        tempoAnterior = tempoAtual;
        estadoAtual = 0; // Volta ao estado vermelho
      }
      digitalWrite(ledVermelho, LOW);
      digitalWrite(ledAmarelo, HIGH);
      digitalWrite(ledVerde, LOW);
      break;
  }
}
