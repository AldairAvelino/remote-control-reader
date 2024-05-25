#include <IRremote.h>
#define receptor 11 //Porta da saída para a entrada digital do Arduino
IRrecv recptorIR(receptor); //Criar a classe do IRrecv
decode_results resultado; //Criar um decode_results, para fazer a decodificação do resultado e vai passar o valor do sinal que recebeu

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  recptorIR.enableIRIn(); //Inicializar o receptor. Para habilitar o Receptor Infravermelho
}

void loop() {
  // put your main code here, to run repeatedly:
  if(recptorIR.decode(&resultado)){ //Para verificar se ouve alguma recepção. &Endereço
    Serial.println(resultado.value,HEX);
    delay(330);
    recptorIR.resume();//Preparar ele para ler um outro comando
  }
}
