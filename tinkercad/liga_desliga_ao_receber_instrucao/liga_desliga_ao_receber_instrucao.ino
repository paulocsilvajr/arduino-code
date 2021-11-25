// Veja o Monitor serial para aconpanhar os laços(loops) que
// verificam o array de String 'm'
// Array 'm' representa o recebimento de dados externos, por
// exemplo via requisição HTTP. String vazia('') representa
// que não foi recebido dados, String 'OK' representa o 
// recebimento de dados

const int LED1 = 7;
const int TEMPO = 1000;

int posicao = 0;
String m[] = {
	"",
    "",
    "",
    "",
    "OK",
};

int tamanhoM = sizeof(m) / sizeof(m[0]);

void setup()
{
  pinMode(LED1, OUTPUT);
  
  Serial.begin(9600);
}

void loop()
{
  String msg = "LOOP ";
  String p = String(posicao + 1);
  msg.concat(p);
  log(msg);
  
  if (m[posicao] == "OK") {
    log("Recebido RESPOSTA: OK");
  	ligaLED(LED1);
  	desligaLED(LED1);
  } else {
  	log("."); 
  }
  
  posicao++;
}

void ligaLED(int led) {
  dw(led, HIGH);
}

void desligaLED(int led) {
  dw(led, LOW);
}

void log(String msg) {
  Serial.println(msg); 
}

void dw(int led, int estado) {
  String msg = "Ligado";
  if (estado == LOW) {
    msg = "Desligado";
  }
  msg.concat(" LED conectado em Pino ");
  msg.concat(led);
      
  log(msg);
  
  digitalWrite(led, estado);
  delay(TEMPO);
}