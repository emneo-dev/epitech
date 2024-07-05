global memmove

; void *memmove(void *dest, const void *src, size_t n);
;               rdi,        rsi,             rdx
section .text
memmove:
    xor rbx, rbx            ; Initialization of used registers

.loop_buffer:
    cmp rbx, rdx            ; Test if we are at the end of the n bytes
    je .loop_dest           ; If yes then jump to the dest writer
    mov cl, [rsi+rbx]       ; We store the value to copy
    push cx                 ; Store the byte to write back to the stack
    inc rbx                 ; Increment the cursor
    jmp .loop_buffer        ; Jump back to th beginning of the loop

.loop_dest:
    test rbx, rbx           ; Test if we are at the end of the n bytes
    jz .end                 ; If yes then jump to the end
    pop cx                  ; Get the byte to write back from the stack
    dec rbx                 ; Decrement the cursor
    mov [rdi+rbx], cl       ; We "paste" the stored copy
    jmp .loop_dest          ; Jump back to th beginning of the loop

.end:
    mov rax, rdi            ; Put the dest ptr in rax for return
    ret                     ; Return