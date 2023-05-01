all: 
	gcc -o hex2bin hex2bin.c 
	./hex2bin

run : 
	qemu-system-i386 -drive format=raw,file=hw.bin -net none

.PHONY: clean

clean:
	rm -rf *.bin *.o *.s hex2bin
