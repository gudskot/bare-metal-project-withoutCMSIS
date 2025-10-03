TARGET = stm32_project

CC = arm-none-eabi-gcc
AS = arm-none-eabi-as
OBJCOPY = arm-none-eabi-objcopy
SIZE = arm-none-eabi-size

CFLAGS = -mcpu=cortex-m0plus -mthumb -g -Wall -O0 -Iinc
ASFLAGS = -mcpu=cortex-m0plus -mthumb

BUILD = build
SRC = src
STARTUP = src/startup
LINKER = linker.ld

OBJECTS = \
	$(BUILD)/startup.o \
	$(BUILD)/main.o

all: $(BUILD)/$(TARGET).elf

$(BUILD)/$(TARGET).elf: $(OBJECTS)
	$(CC) $(CFLAGS) $^ -T$(LINKER) -nostartfiles -o $@
	$(OBJCOPY) -O binary $@ $(BUILD)/$(TARGET).bin
	$(SIZE) $@

$(BUILD)/startup.o: $(SRC)/startup.s
	mkdir -p $(BUILD)
	$(AS) $(ASFLAGS) $< -o $@

$(BUILD)/main.o: $(SRC)/main.c
	mkdir -p $(BUILD)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD)

st-flash: $(BUILD)/$(TARGET).bin
	st-flash write $< 0x8000000
