class press_sensor{
    private:
        uint16_t adc_read(uint8_t pin);
    public:
        /*Valores de pint_int devem ir de 0 a 7
        *   -1.0 se o valor não corresponde ao esperado
        *   0.00 a 1.00 valores de leitura sem erro*/
        float read_Level(int pin_int);
    
    }