# EDGE-GS

# GRUPO
Leonardo Rodrigues Amzehnhoff - RM553372
Daniel Wahba Krasilchik - RM552768
Gustavo Bonani Favero Marcos - RM553493

# Descrição:
Descrição do Projeto BLUE 

O BLUE é uma iniciativa inovadora projetada para monitorar a qualidade da água e ajudar a manter os oceanos limpos e saudáveis. Utilizando sensores modernos e modelos de Inteligência Artificial (IA), o BLUE é capaz de identificar problemas presentes ou futuros na qualidade da água, facilitando a ação preventiva ou corretiva. O sistema é alimentado por energia solar e maremotriz, permitindo operações contínuas em áreas com alto tráfego marítimo e em locais com alto risco de poluição, como costas, orlas e plataformas de petróleo. 

Papel do Arduino com Sonar no Projeto BLUE 

A combinação de Arduino com sonar no contexto do monitoramento ambiental e qualidade da água traz diversas vantagens: 

Custo-Efetividade: Soluções baseadas em Arduino são relativamente baratas e podem ser facilmente implementadas em grande escala. 

Adaptabilidade: A flexibilidade do Arduino permite a integração de uma ampla gama de sensores, incluindo sonares, para diversas aplicações ambientais. 

Precisão e Confiabilidade: Sensores de sonar fornecem dados precisos sobre o ambiente subaquático, essenciais para uma análise detalhada e decisões informadas. 

# Link Wokwi:
https://wokwi.com/projects/399340031537461249

# Código

#include <Servo.h>
const int trigPin = 12;
const int echoPin = 11;
long   duration;
int distance;
Servo s1;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  s1.attach(9);
}

void   loop() {
  for (int i = 0; i < 180; i = i + 1) {
    s1.write(i);
    delay(30);
    distance = calDist();
    Serial.print(i);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(".");
  }
  for (int i = 180; i > 0; i = i - 1) {
    s1.write(i);
    delay(30);
    distance = calDist();
    Serial.print(i);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(".");
  }
}

int calDist() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,   LOW);
  duration =   pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  return distance;
}
