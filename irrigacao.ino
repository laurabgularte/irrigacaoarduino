// Definindo os pinos
const int sensorUmidade = A0;  // Sensor de umidade do solo conectado ao pino A0
const int reléPino = 7;         // Relé conectado ao pino digital 7

// Definindo as variáveis
int umidadeSolo = 0;   // Variável para armazenar o valor da umidade
int umidadeMinima = 400;  // Valor de umidade abaixo do qual a irrigação será acionada (ajustar conforme necessário)
int umidadeMaxima = 700;  // Valor de umidade acima do qual a irrigação será desligada (ajustar conforme necessário)

void setup() {
  // Inicializando os pinos
  pinMode(reléPino, OUTPUT);  // O relé será uma saída
  
  // Iniciando comunicação serial para monitoramento
  Serial.begin(9600);
}

void loop() {
  // Lê o valor do sensor de umidade (valor analógico entre 0 e 1023)
  umidadeSolo = analogRead(sensorUmidade);
  
  // Imprime o valor do sensor de umidade no monitor serial
  Serial.print("Umidade do Solo: ");
  Serial.println(umidadeSolo);
  
  // Se a umidade do solo estiver abaixo do valor mínimo, ativa a irrigação
  if (umidadeSolo < umidadeMinima) {
    digitalWrite(reléPino, HIGH);  // Liga o relé (aciona a bomba/válvula)
    Serial.println("Irrigação ativada.");
  }
  // Se a umidade do solo estiver acima do valor máximo, desliga a irrigação
  else if (umidadeSolo > umidadeMaxima) {
    digitalWrite(reléPino, LOW);  // Desliga o relé (desliga a bomba/válvula)
    Serial.println("Irrigação desativada.");
  }

  // Aguarda 1 segundo antes de ler novamente
  delay(1000);
}
