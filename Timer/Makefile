CC=avr-gcc
CFLAGS=-Wall -Os -DF_CPU=$(F_CPU) -mmcu=$(MCU)
MCU=atmega328p
F_CPU=16000000UL

OBJCOPY=avr-objcopy
BIN_FORMAT=ihex

PORT=/dev/ttyUSB1
BAUD=115200
PROTOCOL=arduino
PART=m328p
AVRDUDE=avrdude -F -V

RM=rm -f

all: timer.hex
	sudo $(AVRDUDE) -c$(PROTOCOL) -p $(PART) -P $(PORT) -b $(BAUD) -D -U flash:w:$<

compile: timer.hex

timer.hex: timer.elf 
	 $(OBJCOPY) -O $(BIN_FORMAT) -R .eeprom $< $@

timer.elf: timer.o 
	 $(CC) $(CFLAGS) -o $@ $<

timer.o: timer.c 
	 $(CC) $(CFLAGS) -c -o $@ $<

upload : 
	sudo $(AVRDUDE) -c $(PROTOCOL) -p $(PART) -P $(PORT) $(BAUD) -U flash:w:timer.hex

clean:
	$(RM) timer.elf timer.hex timer.s timer.o


