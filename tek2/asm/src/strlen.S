global strlen

; This is cool
; https://www.aldeid.com/wiki/X86-assembly/Instructions/repne
section .text
strlen:
    xor rcx, rcx        ; Put rcx to 0 to prevent unwanted bytes in return
    mov ecx, -1         ; Put ecx to -1 to prepare for repne, since it increments then test
    xor rax, rax        ; Put eax to 0, so that repne tests for null bytes
    repne scasb         ; Scan the string for a null byte, result is stored in rcx
    not ecx             ; Reverse the result
    dec ecx             ; Decrease the result because repne counts the null byte
    mov eax, ecx        ; Move the result into rax for the return
    ret                 ; Return
