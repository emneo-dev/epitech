global rindex

; char *rindex(const char *s, int c);
;              rdi,           rsi
section .text
rindex:
    xor rbx, rbx                ; Initialize the counter register
.start:                         ; Put the pointer to the end of the given string
    cmp BYTE [rdi+rbx], 0       ; Check if the pointed byte is null
    je .loop                    ; If yes, then we are at the end of the string, jump to the beginning of the loop
    inc rbx                     ; Move forward from the given string
    jmp .start                  ; Jump back at the start of the loop

.loop:
    cmp [rdi+rbx], sil          ; Check if the pointed byte is the requested one
    je .found                   ; If found then jump to the end
    test rbx, rbx               ; Check if we are at the beginning of the string
    jz .not_found               ; If yes, then we didn't find the requested character
    dec rbx                     ; Go down in the string
    jmp .loop                   ; Jump back at the beginning of the loop

.found:
    mov rax, rdi                ; Move the string pointer to the return register
    add rax, rbx                ; Add the found offset to the string pointer
    ret                         ; Return

.not_found:
    xor rax, rax                ; Put 0 in the return register
    ret                         ; Return