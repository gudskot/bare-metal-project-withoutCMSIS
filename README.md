# Bare-metal LED Blinker for STM32L053R8

This project makes the MCU blink its onboard LED. The key difference is that I didn’t use CMSIS; instead, I created my own header file based on the MCU’s datasheet.
Also, I'm working on adding USART to this project.

## Features
- Works without HAL, direct register access
- Configures GPIOA (pin PA5) as output
- Infinite loop with delay
- Build system: `makefile`

## Future improvements
- Adding USART

## Requirements
- Microcontroller: STM32L053xx
- Compiler: `arm-none-eabi-gcc`
- Build system: `makefile`
- Flashing tool: ST-Link

## Project structure
- src/        # Source files (main.c, system_stm32l0xx.c)
- include/    # Header files (defines, prototypes)
- linker/     # Linker scripts (MCU memory description)
- startup/    # Vector table
- Makefile    # Build system: describes how to compile and link
- README.md   # Project documentation

## How it works
GPIOA5 is configured as output, and in the infinite loop it toggles (LED on/off) with a delay.

## Build and Run
```bash
make        # build
make st-flash  # flash via ST-Link
```
