#include <avr/io.h>
#include <stdint.h>

void adc_init(int freq){
  /*Passar o pino para configurar na inicialização */
    ADMUX |= (1<<REFS0);
    /*Configurar o valor de referência do clock */
    //set prescaller to 128 and enable ADC 
    ADCSRA |= (1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0)|(1<<ADEN);  
}

float read_Level(int pin_int){
/* 
 * Definição do pino de leitura
 */
    int ok = -1;
    for(int i=0; i<8; i++){
        if (pin_int == i){
          ok = 1;
        }
      }
    if (ok == -1){
        return float(ok)
    }
    uint8_t pin = (uint8_t)pin_int;
    float nivel_analogico = adc_read(uint8_t pin);
    
    /*Cálculo feito no momento da leitura para 
    * maior precisão do dado coletado
    * mesmo após conversão para valores entre 0.00 e 1.00 */
    float multiplicador = float(100)/float(1023);

    /*Gerador dos valores entre 0.00 e 1.00 */
    float nivel_digital = (multiplicador * nivel_analogico);
    return nivel_digital;

}

/*Retorna o valor entre 0 e 1023 */
uint16_t adc_read(uint8_t pin) {
    /*pin = pino usado para a leitura */
  /*Seleção de  */
	ADMUX = (ADMUX & 0xF0) | (pin & 0x0F);

	/* Conversão */
	ADCSRA |= _BV(ADSC);

    /* Espera até que a conversão tenha sido concluida */
	while ((ADCSRA & _BV(ADSC)));

	return ADC;
}



/*
// setprecision example
#include <iostream>     // std::cout, std::fixed
#include <iomanip>      // std::setprecision

int main () {
  double f =3.14159;
  std::cout << std::setprecision(5) << f << '\n';
  std::cout << std::setprecision(9) << f << '\n';
  std::cout << std::fixed;
  std::cout << std::setprecision(5) << f << '\n';
  std::cout << std::setprecision(9) << f << '\n';
  return 0;
}
// Example program
#include <iostream>
#include <string>
#include <iomanip>
int main()
{
  float multiplicador = float(100)/float(1023);
  //std::cout << multiplicador;
  float nivel_analogico = 51.5;
  nivel_analogico = (multiplicador * nivel_analogico);
  std::cout <<  setprecision(5) << nivel_analogico;
}
 */