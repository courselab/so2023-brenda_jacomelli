CFLAGS = -m16 -O0 -I. -Wall -fno-pic -fcf-protection=none --freestanding -nostdlib

all:  hw-hex.bin hw-s.bin hw-c.bin
	@echo "Making all binaries..."

# Part a
hex2bin: hex2bin.c
	gcc -o $@ $<

hw-hex.bin: hex2bin hw.hex
	./$<

# Part b
hw.o : hw.S
	as --32 $< -o $@

hw-s.bin : hw.o
	ld -melf_i386 --oformat=binary -Ttext=0x7c00  $< -o $@

# Part c
hw_utils.o hw_rt0.o: hw_utils.c hw_rt0.c
	gcc $(CFLAGS) -c $^

hw-c.bin: hw.c hw_rt0.o hw_utils.o hw.ld
	gcc -m16 -O0 -I. -Wall -fno-pic -fcf-protection=none  --freestanding -nostdlib -T hw.ld -Wl,--orphan-handling=discard hw.c -o $@

# QEMU
%.bin/run: %.bin
	qemu-system-i386 -drive format=raw,file=$< -net none

.PHONY: clean

clean:
	rm -rf *.bin *.o *.s hex2bin