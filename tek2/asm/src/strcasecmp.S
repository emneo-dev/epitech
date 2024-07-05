global strcasecmp

; int strcasecmp(const char *s1, const char *s2);
;                rdi,            rsi
section .text
strcasecmp:
    xor rbx, rbx                ; Set the used pointers
    xor eax, eax                ;

.loop:
    mov cl, [rsi+rbx]           ; Get the first pointer
    mov al, [rdi+rbx]           ; Get the second pointer
    test cl, cl                 ; Check if one of the pointers is null
    jz .end                     ; If yes then jump to the end
    test al, al                 ;
    jz .end                     ;
    jmp .test_case_lower        ; Jump to the case check

.next_loop:
    cmp cl, al                  ; Check if the two bytes are equal
    jne .end                    ; If no jump to the end
.next_loop_check_passed:
    inc rbx                     ; Forward from the first string pointer
    jmp .loop                   ; Jump to the beginning of the loop

.test_case_lower:
    cmp cl, 0x61                ; Check if the first byte is a lower case character
    jl .test_case_upper         ; If no then jump to the correct symbol
    cmp cl, 0x7A                ;
    jg .next_loop               ;
    sub cl, 0x20                ; Put the first byte in uppercase by substracting 0x20
    cmp cl, al                  ; Check if the first byte and the second one are equal
    je .next_loop_check_passed  ; If yes then jump to the beginning of the loop
    add cl, 0x20                ; Put the byte back to lowercase
    jmp .next_loop              ; Jump to the end of the loop

.test_case_upper:
    cmp cl, 0x41                ; Check if the first byte is uppercase
    jl .next_loop               ; If yes the jump to the end of the loop
    cmp cl, 0x5A                ;
    jg .next_loop               ;
    add cl, 0x20                ; Put the first byte to lowercase
    cmp cl, al                  ; Check if the first and second bytes are equal
    je .next_loop_check_passed  ; If yes jump to the end of the loop
    sub cl, 0x20                ; Put the byte back to uppercase
    jmp .next_loop              ; Jump to the beginning of the loop

.end:
    sub eax, ecx                ; Get the difference between the two bytes
    ret                         ; Return