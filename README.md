# Bare-metal LED Blinker for STM32L053R8

This project makes the MCU receive user commands via UART and control the onboard LED. The key difference is that I didn’t use CMSIS; instead, I created my own header file based on the MCU’s datasheet.

## Features
- Works without HAL, direct register access
- Configures GPIOA (pin PA5) as output
- Implements UART communication for command control
- Build system: `makefile`

## Future improvements
- Add SPI features

## Requirements
- Microcontroller: STM32L053xx
- Compiler: `arm-none-eabi-gcc`
- Build system: `makefile`
- Flashing tool: ST-Link

## Project structure
- src/        # Source files (main.c)
- include/    # Header files (defines, macros)
- linker/     # Linker scripts (MCU memory description)
- startup/    # Vector table
- Makefile    # Build system: describes how to compile and link
- README.md   # Project documentation

## How it works
The MCU communicates via UART, allowing you to send commands to control the LED. You can check whether the LED is ON or OFF, and toggle its state.

## Build and Run
```bash
make        # build
make st-flash  # flash via ST-Link
```
