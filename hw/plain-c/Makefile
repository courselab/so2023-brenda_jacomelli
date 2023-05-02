
all:
	gcc -m16 -O0 -I. -Wall -fno-pic -fcf-protection=none --freestanding -nostdlib  -c hw_utils.c -o hw_utils.o
	gcc -m16 -O0 -I. -Wall -fno-pic -fcf-protection=none -c hw_rt0.c -o hw_rt0.o
	gcc -m16 -O0 -I. -Wall -fno-pic -fcf-protection=none  --freestanding -nostdlib -T hw.ld -Wl,--orphan-handling=discard hw.c -o hw.bin

.PHONY: clean

run:
	qemu-system-i386 -drive format=raw,file=hw.bin -net none

clean:
	rm -f *.bin *.o *.s 