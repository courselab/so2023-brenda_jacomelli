
CFLAGS = -m16 -O0 -I. -Wall -fno-pic -fcf-protection=none --freestanding -nostdlib

hw_utils.o hw_rt0.o: hw_utils.c hw_rt0.c
	gcc $(CFLAGS) -c $^

hw.bin: hw.c hw_rt0.o hw_utils.o hw.ld
	gcc -m16 -O0 -I. -Wall -fno-pic -fcf-protection=none  --freestanding -nostdlib -T hw.ld -Wl,--orphan-handling=discard hw.c -o $@

run: hw.bin
	qemu-system-i386 -drive format=raw,file=$< -net none

.PHONY: clean

clean:
	rm -f *.bin *.o *.s 