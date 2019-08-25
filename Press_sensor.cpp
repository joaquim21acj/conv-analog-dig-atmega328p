#include <avr/io.h>
#include <stdint.h>
#include "Press_sensor.h"

/*Retorna 1 se der certo e -1 se não der certo*/
int adc_init(int pin_config = 0, int aden_config=ADEN){
  /*Passar o pino para configurar na inicialização */
    int ok = -1;
    for(int i=0; i<8; i++){
        if (pin_int == i){
          ok = 1;
        }
      }
    if (ok == -1){
        return ok;
    }
    ADMUX |= (1<<REFS0);
    aden_init = aden_config;
    pin_int = pin_config;
    /*Configurar o valor de referência do clock */
    ADCSRA |= (1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0)|(1<<aden_config);  
    ok = 1;
    return ok;
}

float read_Level(){
/* 
 * Definição do pino de leitura
 */

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
