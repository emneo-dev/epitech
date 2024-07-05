global strchr

; char *strchr(const char *s, int c);
;              rdi,           rsi
section .text
strchr:
    xor rbx, rbx            ; Set the counter register to 0

.loop:
    cmp [rdi+rbx], sil      ; Check if the currently pointed byte is the requested one
    je .found               ; If yes jump to the end
    cmp BYTE [rdi+rbx], 0   ; Check if we are at the end of the string
    jz .not_found           ; If yes then we didn't find the requested byte, jump to the end
    inc rbx                 ; Move forward from the original string pointer
    jmp .loop               ; Jump back to the beginning of the loop

.found:
    mov rax, rdi            ; Move the string pointer to the return register
    add rax, rbx            ; Add the found offset to the string pointer
    ret                     ; Return

.not_found:
    xor rax, rax            ; Put the return register to zero
    ret                     ; Return