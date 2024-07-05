global strcspn

; size_t strcspn(const char *s, const char *reject);
;                rdi,           rsi
section .text
strcspn:
    xor rax, rax            ; Put the used registers to zero
    xor rbx, rbx            ;

.loop:
    cmp BYTE [rdi+rax], 0   ; Check if the pointed byte is zero
    je .end                 ; If yes jump to the end

.test_reject:
    cmp BYTE [rsi+rbx], 0   ; Check if the pointed reject byte is zero
    je .end_reject          ; If yes then the reject has been tested, jump to the end of the loop
    mov r8b, [rsi+rbx]      ; Move the pointed reject byte to a register
    cmp r8b, [rdi+rax]      ; Check if the reject equal the pointed byte
    je .end                 ; If yes then jump to the end
    inc rbx                 ; Forward from the reject pointer
    jmp .test_reject        ; Jump to the beginning of the reject test loop

.end_reject:
    xor rbx, rbx            ; Put the counter register to zero
    inc rax                 ; Forward from the string pointer
    jmp .loop               ; Jump to the beginning of the loop

.end:
    ret                     ; Return