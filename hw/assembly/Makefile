hw.bin : %.bin : %.o
	ld -melf_i386 --oformat=binary -Ttext=0x7c00  $< -o $@

hw.o : %.o : %.S
	as --32 $< -o $@


.PHONY: clean

clean:
	rm -f *.bin *.o

run: hw.bin
	qemu-system-i386 -drive format=raw,file=$< -net none