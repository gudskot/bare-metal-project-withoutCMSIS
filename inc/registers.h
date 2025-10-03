#ifndef REGISTERS_H
#define REGISTERS_H

#include <stdint.h>

// RCC definiton
#define RCC_BASE 0x40021000UL
#define RCC_IOPENR (*(volatile uint32_t*)(RCC_BASE + 0x2C))

// GPIO definition
#define GPIOA_BASE 0X50000000UL
#define GPIOA_MODER (*(volatile uint32_t*)(GPIOA_BASE + 0x00))
#define GPIOA_ODR   (*(volatile uint32_t*)(GPIOA_BASE + 0x14))

#endif