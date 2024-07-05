global strpbrk

; char *strpbrk(const char *s, const char *accept);
;               rdi,           rsi
section .text
strpbrk:
    mov rbx, -1         ; Set the used registers
    xor rcx, rcx        ;

.loop:
    inc rbx             ; Forward from the string pointer
    mov r8b, [rdi+rbx]  ; Get the currently pointed byte
    test r8b, r8b       ; Check if the byte is null
    jz .not_found       ; If yes then jump to the end
    xor r9, r9          ; Put r9 to zero

.loop_check:
    mov r10b, [rsi+r9]  ; Get the accept byte
    test r10b, r10b     ; Check if we are at the end of the accept string
    jz .loop            ; If yes then jump to the beginning of the loop
    cmp r8b, r10b       ; Check if the two bytes are equal
    je .found           ; If yes then jump to the end
    inc r9              ; Forward from the accept string pointer
    jmp .loop_check     ; Jump to the beginning of the loop

.found:
    mov rax, rdi        ; Put the string pointer in the return register
    add rax, rbx        ; Add the found offset to the string pointer
    ret                 ; Return

.not_found:
    xor rax, rax        ; Put the return register to zero
    ret                 ; Return