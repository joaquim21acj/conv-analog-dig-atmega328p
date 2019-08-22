#include <avr/io.h>
#include <stdint.h>
/* 
 * Definição do pino de leitura
 */
#define ADC_PIN			0

float Read_Level(){
    /*10.23% = 1 */
    float nivel_analogico = adc_read(uint8_t pin)
    
    /* */
    nivel_analogico = (nivel_analogico / 100)
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