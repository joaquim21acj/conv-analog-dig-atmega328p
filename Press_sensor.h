#ifndef Press_sensor
#define press_sensor
class Press_sensor{
    int pin_int;
    int aden_init;
    private:
        uint16_t adc_read(uint8_t pin);
    public:
        /*Valores de pint_int devem ir de 0 a 7
        *   -1.0 se o valor não corresponde ao esperado
        * Retorna 1 se der certo e -1 se não der certo*/
        int adc_init(int pin_config = 0, int aden_config=ADEN);
        /* 0.00 a 1.00 valores de leitura sem erro*/
        float read_Level();
    
    };
#endif Press_sensor