#ifndef REGISTERS_H
#define REGISTERS_H

#include <stdint.h>

// RCC definiton
#define RCC_BASE 0x40021000UL
#define RCC_IOPENR (*(volatile uint32_t*)(RCC_BASE + 0x2C))
#define RCC_APB2ENR (*(volatile uint32_t*)(RCC_BASE + 0x34))

// GPIO definition
#define GPIOA_BASE 0X50000000UL
#define GPIOA_MODER (*(volatile uint32_t*)(GPIOA_BASE + 0x00))
#define GPIOA_ODR   (*(volatile uint32_t*)(GPIOA_BASE + 0x14))
#define GPIOx_AFRH  (*(volatile uint32_t*)(GPIOA_BASE + 0x24))

// USART definiton
#define USART_BASE 0X40013800UL
#define USART_BRR   (*(volatile uint32_t*)(USART_BASE + 0x0C))

#endif