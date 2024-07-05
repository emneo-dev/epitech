global strncmp

; int strncmp(const char *s1, const char *s2, size_t n);
;             rdi,            rsi,            rdx
section .text
strcmp:
    xor rbx, rbx        ; Put the used registers to zero
    xor rax, rax        ;
    xor rcx, rcx        ;

.loop:
    mov cl, [rsi+rbx]   ; Get the fist byte
    mov al, [rdi+rbx]   ; Get the second byte
    test cl, cl         ; Check if the first byte is null
    jz .end             ; If yes jump to the end
    test al, al         ; Check if the second byte is null
    jz .end             ; If yes jump to the end
    test rdx, rdx       ; Check if the maximum number of bytes as been reached
    jz .end             ; If yes jump to the end
    cmp cl, al          ; Check if the first and second bytes are equal
    jne .end            ; If no jump to the end
    inc rbx             ; Forward from the string pointer
    dec rdx             ; Decrement the maximum nulber of bytes
    jmp .loop           ; Jump back to the beginning of the loop

.end:
    sub rax, rcx        ; Get the difference between the two bytes
    ret                 ; Return