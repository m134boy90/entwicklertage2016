    section .text
    global  _start
_start:
	jmp STACKUP
RUN:
    mov eax, 4 ; write(stdout, hello, len)
    mov ebx, 1 ; fd of stdout
    pop ecx		; address of string from stack to ecx
    mov edx, 11 ; length of string
    int 80h		; interrupt for syscall
	jmp STACKUP ; repeat infinitly

    mov eax, 1 ; exit(0)
    mov ebx, 0
    int 80h
STACKUP:
	call RUN	; pushes address of string to the stack for returning here
	db "Pwned You!",10

