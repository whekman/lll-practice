
; print a string using a subroutine

section .data
	text db "Just a string... of some length",10,0

section .text
	global _start

_start:
	mov rax, text
	call _print

	mov rax, 60 						;exit
	mov rdi, 0
	syscall

_print:
	push rax      ; push arg1 (address to text)

	mov rbx, 0    ; counter

_printLoop:

	inc rax       ; move char pointer to next char
	inc rbx       ; increment the counter

	mov cl, [rax] ; load byte at rax pointer
	cmp cl, 0     ; character == 0?
	jne _printLoop

	; sysout syscall routine
	mov rax, 1
	mov rdi, 1
	pop rsi       ; pops off arg1 (address to text)
	mov rdx, rbx  ; loads the string length
	syscall

	ret