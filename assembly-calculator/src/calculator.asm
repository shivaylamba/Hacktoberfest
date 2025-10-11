section .data
    prompt db "Enter first number: ", 0
    prompt_len equ $ - prompt
    prompt2 db "Enter second number: ", 0
    prompt2_len equ $ - prompt2
    result_msg db "Result: ", 0
    result_msg_len equ $ - result_msg
    newline db 10, 0

section .bss
    num1 resb 10
    num2 resb 10
    result resb 10
    operation resb 1

section .text
    global _start

_start:
    ; Input first number
    mov rax, 1          ; syscall: write
    mov rdi, 1          ; file descriptor: stdout
    mov rsi, prompt     ; message to write
    mov rdx, prompt_len ; message length
    syscall

    mov rax, 0          ; syscall: read
    mov rdi, 0          ; file descriptor: stdin
    mov rsi, num1      ; buffer to store input
    mov rdx, 10         ; number of bytes to read
    syscall

    ; Input second number
    mov rax, 1
    mov rdi, 1
    mov rsi, prompt2
    mov rdx, prompt2_len
    syscall

    mov rax, 0
    mov rdi, 0
    mov rsi, num2
    mov rdx, 10
    syscall

    ; Input operation
    mov rax, 1
    mov rdi, 1
    mov rsi, operation
    mov rdx, 1
    syscall

    ; Perform calculation based on operation
    ; Assuming operation is '+' for addition
    ; Convert ASCII to integer
    sub byte [num1], '0'
    sub byte [num2], '0'
    mov al, [num1]
    add al, [num2]
    add al, '0'        ; Convert back to ASCII
    mov [result], al

    ; Output result
    mov rax, 1
    mov rdi, 1
    mov rsi, result_msg
    mov rdx, result_msg_len
    syscall

    mov rax, 1
    mov rdi, 1
    mov rsi, result
    mov rdx, 1
    syscall

    ; New line
    mov rax, 1
    mov rdi, 1
    mov rsi, newline
    mov rdx, 1
    syscall

    ; Exit
    mov rax, 60         ; syscall: exit
    xor rdi, rdi        ; status: 0
    syscall

global _start

section .text
_start:
    ; Your code here

    ; Exit
    mov rax, 60         ; syscall: exit
    xor rdi, rdi        ; status: 0
    syscall