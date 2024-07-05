global memset

; void *memset(void *s, int c, size_t n);
;              rdi,     rsi,   rdx
section .text
memset:
    xor rcx, rcx            ; Put to zero

.loop:
    cmp rcx, rdx            ; If we are at the end of the number of bytes to copy
    je .end                 ; Then jump to the end
    mov [rdi+rcx], sil      ; Copy the constant byte to the pointed memory
    inc rcx                 ; Move forward from the starting pointer
    jmp .loop               ; Jump back at the beginning of the loop

.end:
    mov rax, rdi            ; Move the destination pointer to the return register
    ret                     ; Return