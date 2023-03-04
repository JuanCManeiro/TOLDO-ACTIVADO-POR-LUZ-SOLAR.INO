# TOLDO-ACTIVADO-POR-LUZ-SOLAR.INO
Baixada dun toldo pola accion da luz.

  /***** Toldo activado por luz solar 

Este script activa un motor que desprega un toldo cando aumento a luz solar. Non é un caso real , porque non
recolle o toldo.

O sensor 

Autor:Comunidade
Data:Marzo 2023

*****/

#define RELE 12 // salida
#define LDR A0  // entrada

int umbral = 950;
int entrada = -999;
bool releON = 0;
int contador = 0;
//bool finCarreira = false;


void setup () {
  pinMode(RELE, OUTPUT);
  pinMode(LDR, INPUT); // Non é necesario declarala xa que e unha saida analoxica
  Serial.begin(9600);
}
void loop() {
  //LECTURA DE ENTRADAS
  entrada = analogRead(LDR); // A lectura vai estar entre 54 e 974
  Serial.print("entrada LDR: ");
  Serial.println(entrada);
  //delay(500); // quitamos o delay xa que unha vez comprovado non o necesitamos o unico que fai e retrasar o script
  
  //ACCIONAMENTO DOS ACTUADORES

  if(/*contador <= 0 && */entrada > umbral){ //( finCarreira == false && entrada > umbral){  //
  releON = true;
  contador = 100;
}
  
/*else {
  releON = false;  
 // contador = 100; // quitamolo porque no caso de aparecer unha nuve o motor pararia e o volver o sol reiniciariase, non queremos que esto suceda
}
*/
  if(contador > 0 && entrada > umbral){
    Serial.print("contador: "); Serial.println(contador);
    contador--;
    delay(70);
  }   
    else {
    releON = false;
    }
   digitalWrite(RELE, releON);
  
 /* if(contador == 0){
    releON = false;
  }*/

}
