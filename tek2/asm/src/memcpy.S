global memcpy

; void *memcpy(void *dest, const void *src, size_t n);
;              rdi,        rsi,             rdx
section .text
memcpy:
    xor rax, rax        ; Initialization of used registers
    xor rbx, rbx

.loop:
    cmp rbx, rdx        ; Test if we are at the end of the n bytes
    je .end             ; If yes then jump to the end
    mov cl, [rsi+rbx]   ; We store the value to copy
    mov [rdi+rbx], cl   ; We "paste" the stored copy
    inc rbx             ; Increment the cursor
    jmp .loop           ; Jump back to th beginning of the loop

.end:
    mov rax, rdi        ; Put the dest ptr in rax for return
    ret                 ; Return