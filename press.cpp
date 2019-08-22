#include <avr/io.h>
#include <stdint.h>
/* 
 * Definição do pino de leitura
 */
#define ADC_PIN			0

float Read_Level(){
    float nivel_analogico = adc_read(uint8_t pin)
    
    /*Cálculo feito no momento da leitura para 
    * maior precisão do dado coletado
    * mesmo após conversão para valores entre 0.00 e 1.00 */
    float multiplicador = float(100)/float(1023)

    /*Gerador dos valores entre 0.00 e 1.00 */
    nivel_analogico = (multiplicador * nivel_analogico)
}

/*Retorna o valor entre 0 e 1023 */
uint16_t adc_read(uint8_t pin) {
    /*pin = pino usado para a leitura */

	ADMUX &= 0xf0;
	ADMUX |= adcx;

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