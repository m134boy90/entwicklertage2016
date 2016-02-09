; ----------------------------------------------------------------------------------------
; Hello World
; ----------------------------------------------------------------------------------------

        global  main

        section .text
main:
        ; write(1, message, 13)
        mov     eax, 4                  ; system call 1 is write
        mov     ebx, 1                  ; file handle 1 is stdout
        mov     ecx, message            ; address of string to output
        mov     edx, 14                 ; number of bytes
        int 80h                         ; invoke operating system to do the write

        ; exit(0)
        mov     eax, 1                 ; system call 60 is exit
        xor     ebx, ebx                ; exit code 0
        int 80h                         ; invoke operating system to exit
message:
        db      "Hello, World!", 10      ; note the newline at the end
