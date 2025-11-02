#include <registers.h>
#include <stdio.h>

void uart_transmit(char c) {
    while(!(USART_ISR & USART_ISR_TXE)) {}
    USART_TDR = c;
}

char uart_recieve(void) {
    while(!(USART_ISR & USART_ISR_RXNE)) {}
    return USART_RDR;
}

void uart_send_string(const char *s) {
    while(*s) {
        uart_transmit(*s++);
        GPIOA_ODR ^= (1 << 5);
    }
}

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
    GPIOA_AFRH &= ~(4 << (1 * 4)); // reset bits
    GPIOA_AFRH |= (4 << 4);   // function type AF4  

    //PA10 alternate function
    GPIOA_MODER &= ~(3 << (2 * 10));
    GPIOA_MODER |= (2 << (2 * 10));
    GPIOA_AFRH &= ~(4 << (2 * 4));  // reset bits
    GPIOA_AFRH |= (4 << 8);   // function type AF4

    //  set baud rate
    USART_BRR = 18; // (2.1Mhz / 115200)
    
    //  Enable USART
    USART_CR1 = 0;  // reset all bits
    USART_CR1 |= (1 << 2);  // enable transmit
    USART_CR1 |= (1 << 3);  // enable recieve
    USART_CR1 |= (1 << 0);  // enable USART

    while(1) {
        uart_send_string("Hello World\n");
        for(int i = 0; i < 100000; i++);
    }
}
