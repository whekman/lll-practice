
section .data
	line db 0, 10	; 2 characters: 0 \n

section .text
	global _start

_start:

	add rax, 97        ; shift into a-z ascii
	mov [line], al     ; first byte of rax = al = 97 = 64 + 32 + 1 = 10000110
	call _printChar
	call _exit

_printChar:

	mov rax, 1
	mov rdi, 1
	mov rsi, line
	mov rdx, 2
	syscall
	ret

_exit:

	mov rax, 60 						;exit
	mov rdi, 0
	syscall
	ret