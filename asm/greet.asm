
section .data
	question db "What is your name? "	; 19 characters (" doesnt count)
	reply db "Hello, "					; 7 characters

section .bss
	name resb 16 						; reserve 16 bytes of memory
										; address = name

section .text
	global _start

_start:

	call _printQuestion
	call _getName
	call _printReply
	call _printName
	call _exit

_printQuestion:

	mov rax, 1
	mov rdi, 1
	mov rsi, question
	mov rdx, 19
	syscall
	ret

_getName:

	mov rax, 0               	; standard input
	mov rdi, 0            		; standard input
	mov rsi, name
	mov rdx, 16                 ; 16 character buffer
	syscall
	ret

_printReply:

	mov rax, 1
	mov rdi, 1
	mov rsi, reply
	mov rdx, 7
	syscall
	ret

_printName:

	mov rax, 1
	mov rdi, 1
	mov rsi, name
	mov rdx, 16
	syscall
	ret

_exit:

	mov rax, 60 						;exit
	mov rdi, 0
	syscall