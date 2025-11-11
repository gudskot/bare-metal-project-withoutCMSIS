#ifndef GPIO_H
#define GPIO_H

#define GPIO_CLEAR(pin) (3 << (2 * pin))
#define GPIO_MODE_OUTPUT(pin) (1 << (2 * pin))
#define GPIOA_MODE_AF(pin) (2 << (2 * pin))

#define AF_CLEAR(pin) (15 << ((pin - 8) * 4))
#define AF_TYPE4(pin) (4 << ((pin - 8) * 4))

#define USART_RESET 0
#define USART_ENABLE_TRANSMIT (1 << 2)
#define USART_ENABLE_RECIEVE (1 << 3)
#define USART_ENABLE (1 << 0)

#endif