#include <registers.h>

int main(void) {
    // Open tackting
    RCC_IOPENR |= (1 << 0);
    RCC_APB2ENR |= (1 << 14);

    // PA5 output
    GPIOA_MODER &= ~(3 << (2 * 5));
    GPIOA_MODER |= (1 << (2 * 5));

    //PA9 alternate function
    GPIOA_MODER &= ~(3 << (2 * 9));
    GPIOA_MODER |= (2 << (2 * 9));
    GPIOx_AFRH |= (1 << (1 * 4));

    //PA10 alternate function
    GPIOA_MODER &= ~(3 << (2 * 10));
    GPIOA_MODER |= (2 << (2 * 10));
    GPIOx_AFRH |= (1 << (2 * 4));

    while(1) {
        for(int i = 0; i < 100000; i++) {
            GPIOA_ODR ^= (1 << 5);
            for(int i = 0; i < 100000; i++) {};
            GPIOA_ODR ^= (0 << 5);
        }
    }
}