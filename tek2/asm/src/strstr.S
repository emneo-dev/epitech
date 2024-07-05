global strstr

; char *strstr(const char *haystack, const char *needle);
;              rdi,                  rsi
section .text
strstr:
    xor rcx, rcx        ; Put the used registers to zero
    xor rbx, rbx        ;

.loop:
    mov r8b, [rdi+rcx]  ; Get the first byte
    test r8b, r8b       ; Check if it is null
    jz .not_found_end   ; If yes then jump to the end

.loop_needle:
    mov r9b, [rsi+rbx]  ; Get the needle byte
    mov r8b, [rdi+rcx]  ; Get the haystack byte
    cmp r8b, r9b        ; Check if the two are equal
    jne .continue_loop  ; If no then jump to the end of the loop
    inc rbx             ; Forward from the needle string pointer
    mov r9b, [rsi+rbx]  ; Get the needle byte
    test r9b, r9b       ; Check if we got to the end of the needle
    jz .found_end       ; If yes the n jump to the end
    inc rcx             ; Forward from the haystack byte
    jmp .loop_needle    ; Jump to the beginning of the needle loop

.continue_loop:
    inc rcx             ; Forward from the haystack string pointer
    jmp .loop           ; Jump to the beginning of the loop

.not_found_end:
    xor rax, rax        ; Put the return register to zero
    ret                 ; Return

.found_end:
    mov rax, rcx        ; Put the offset found in the return register
    sub rax, rbx        ; Substract the length of the needle
    inc rax             ; Increment by one
    add rax, rdi        ; Add the haystack string pointer
    ret                 ; Return

; If someone sees this, I want you to know that putting all of those fucking
; comments in this project made me want to die, and I hope people understand
; that a good code shouldn't need comments every fucking where
