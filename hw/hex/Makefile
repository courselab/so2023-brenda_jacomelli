hex2bin: hex2bin.c
	gcc -o $@ $<

hw.bin: hex2bin
	./$<

run : hw.bin
	qemu-system-i386 -drive format=raw,file=$< -net none

.PHONY: clean

clean:
	rm -f *.bin *.o *.s hex2bin
