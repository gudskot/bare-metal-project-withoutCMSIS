#include <registers.h>

int main(void) {
    // Open tackting
    RCC_IOPENR |= (1 << 0);

    // PA5 output
    GPIOA_MODER &= ~(3 << (2 * 5));
    GPIOA_MODER |= (1 << (2 * 5));

    while(1) {
        for(int i = 0; i < 100000; i++) {
            GPIOA_ODR ^= (1 << 5);
            for(int i = 0; i < 100000; i++) {};
            GPIOA_ODR ^= (0 << 5);
        }
    }
}
