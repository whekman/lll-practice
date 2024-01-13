
; prints hello using ASCII

section .data
	line db 0, 10; 2 characters: 0 \n

section .text
	global _start

_start:

	mov rbx, 97        ; a
	add rbx, 7
	call _printRBX

	dec rbx            ;
	dec rbx            ;
	dec rbx            ;
	call _printRBX

	add rbx, 7        ;
	call _printRBX
	call _printRBX

	add rbx, 3         ;
	call _printRBX

	call _exit

_printRBX:

	mov rax, rbx       ; a
	mov [line], al     ; first byte of rax = al = 97 = 64 + 32 + 1 = 10000110
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