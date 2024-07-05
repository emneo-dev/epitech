global strcmp

; int strcmp(const char *s1, const char *s2);
;            rdi,            rsi
section .text
strcmp:
    xor rbx, rbx        ; Put used registers to zero
    xor rax, rax        ;
    xor rcx, rcx        ;

.loop:
    mov cl, [rsi+rbx]   ; Put the pointed first string byte in a register
    mov al, [rdi+rbx]   ; Put the pointed second string byte in a register
    test cl, cl         ; Check if the first byte is null
    jz .end             ; If yes then jump to the end
    test al, al         ; Check if the second byte is null
    jz .end             ; If yes then jump to the end
    cmp cl, al          ; Check if the two bytes are equals
    jne .end            ; If no then jump to the end
    inc rbx             ; Go forward from the original string pointer
    jmp .loop           ; Jump back to the start of the loop

.end:
    sub rax, rcx        ; Substract the second byte by the first one
    ret                 ; Return