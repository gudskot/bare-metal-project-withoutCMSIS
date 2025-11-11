#include <registers.h>
#include <gpio.h>
#include <stdio.h>

void uart_transmit(char c) {
    while(!(USART_ISR & USART_ISR_TXE));
    USART_TDR = c;
}

char uart_recieve(void) {
    while(!(USART_ISR & USART_ISR_RXNE));
    return USART_RDR;
}

void uart_send_string(const char *s) {
    while(*s) uart_transmit(*s++);
}

void ledInfo(void) {
    if((GPIOA_ODR & (1 << 5))) uart_send_string("LED PA5 is: HIGH\n");
    else uart_send_string("LED PA5 is: LOW\n");
}

int main(void) {
    char c;

    // Open tackting
    RCC_IOPENR |= (1 << 0);
    RCC_APB2ENR |= (1 << 14);

    // PA5 output
    GPIOA_MODER &= ~GPIO_CLEAR(5);
    GPIOA_MODER |= GPIO_MODE_OUTPUT(5);

    //PA9 alternate function
    GPIOA_MODER &= ~GPIO_CLEAR(9);
    GPIOA_MODER |= GPIOA_MODE_AF(9);
    GPIOA_AFRH &= ~AF_CLEAR(9); // reset bits
    GPIOA_AFRH |= AF_TYPE4(9);   // function type AF4  

    //PA10 alternate function
    GPIOA_MODER &= ~GPIO_CLEAR(10);
    GPIOA_MODER |= GPIOA_MODE_AF(10);
    GPIOA_AFRH &= ~AF_CLEAR(10);  // reset bits
    GPIOA_AFRH |= AF_TYPE4(10);   // function type AF4

    //  set baud rate
    USART_BRR = 18; // (2.1Mhz / 115200)
    
    //  Enable USART
    USART_CR1 = USART_RESET;  // reset all bits
    USART_CR1 |= USART_ENABLE_TRANSMIT;  // enable transmit
    USART_CR1 |= USART_ENABLE_RECIEVE;  // enable recieve
    USART_CR1 |= USART_ENABLE;  // enable USART

    while(1) {
        uart_send_string("\nEnter number of operation:\n1 - LED info\n2 - Toggle LED\n");

        c = uart_recieve();
        switch(c) {
        case '1':
            ledInfo();
            break;
        case '2':
            GPIOA_ODR ^= (1 << 5);
            break;
        default:
            uart_send_string("Wrong option. Try again\n");
            break;
        }
    }
}
