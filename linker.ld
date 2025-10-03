ENTRY(Reset_Handler)

MEMORY
{
  FLASH (rx)  : ORIGIN = 0x08000000, LENGTH = 64K
  RAM   (xrw) : ORIGIN = 0x20000000, LENGTH = 8K
}

_estack = ORIGIN(RAM) + LENGTH(RAM);

SECTIONS
{
  .isr_vector :
  {
      KEEP(*(.vector_table))
  } > FLASH

  .text :
  {
      *(.text*)
  } > FLASH

  .rodata :
  {
      *(.rodata*)
  } > FLASH

  _sidata = .;

  .data : AT(_sidata)
  {
      _sdata = .;
      *(.data*)
      _edata = .;
  } > RAM

  .bss :
  {
      _sbss = .;
      *(.bss*)
      *(COMMON)
      _ebss = .;
  } > RAM
}