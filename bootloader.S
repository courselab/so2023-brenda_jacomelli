## Boot, say hello, and halt (AT&T assembly)

	.global _start
        .code16

_start:	

        movb  $0xe, %ah	       
	movw  $0x0, %bx	    

loop:
        movb  string(%bx), %al    
	int   $0x10	       
	inc   %bx	       
        cmp   $str_len, %bx
        je    halt            
        jmp   loop	

string: 
        .asciz "Hello World!"
	str_len =   . - string       

halt:
        hlt
        jmp halt

        .fill 510 - (. - _start), 1, 0       
	.word 0xaa55


