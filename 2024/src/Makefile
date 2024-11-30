# AVR-GCC Makefile
PROJECT=octopus
SOURCES=octopus.c lib/led/led.c
INCLUDES=-Ilib
CC=avr-gcc
OBJCOPY=avr-objcopy
MMCU=attiny45
USBDEV=/dev/tty.usbserial-A600eyob

CFLAGS=-mmcu=$(MMCU) -Wall -Os -DF_CPU=1000000UL


$(PROJECT).hex: $(PROJECT).out
	$(OBJCOPY) -j .text -O ihex $(PROJECT).out $(PROJECT).hex

$(PROJECT).out: $(SOURCES) 
	$(CC) $(CFLAGS) $(INCLUDES) $(SOURCES) -o $(PROJECT).out

program: $(PROJECT).hex
	avrdude -p t45 -c buspirate -P $(USBDEV) -e -U flash:w:$(PROJECT).hex

read_fuses: $(PROJECT).hex
	avrdude -p t45 -c buspirate -P $(USBDEV) -e -U hfuse:r:-:i -U lfuse:r:-:i -vv

clean:
	rm -f $(PROJECT).o
	rm -f $(PROJECT).out
	rm -f $(PROJECT).map
	rm -f $(PROJECT).hex
