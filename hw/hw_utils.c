

int __attribute__((thiscall, naked))  printf(const char* s)
{
__asm__
(
"   mov   %cx, %si             \n"
"	mov   $0x0e, %ah           \n"
"loop:	           	           \n"
"   lodsb                      \n" // Load byte at address DS:(E)SI into AL and increment
"	cmp   $0x0, %al            \n"
"	je    end                  \n"
"	int   $0x10	               \n"
"	jmp   loop	               \n"
"end:                          \n"
"   mov   %si, %ax             \n"
"   ret                        \n"
);
}



