

int __attribute__((thiscall, naked))  printf(const char* s)
{
__asm__
(
"   mov   %cx, %bx            \n"
"	mov   $0x0e, %ah           \n"
"	mov   $0x0, %si            \n"
"loop:	           	           \n"
"	mov   (%bx, %si), %al      \n"
"	cmp   $0x0, %al            \n"
"	je    end                  \n"
"	int   $0x10	           \n"
"	inc   %bx	           \n"
"	jmp   loop	           \n"
"end:                              \n"
"        mov   %si, %ax            \n"
"        ret                       \n"
);
}



