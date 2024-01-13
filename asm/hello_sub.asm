
; Printing Hello, World! to the terminal using
; a sub-routine :-)

section .data
	text db "Hello, world!",10

section .text
	global _start

_start:

	call _printHello

	mov rax, 60		; exit syscall ID
	mov rdi, 0      ; no error
	syscall

_printHello:		; a sub-routine!
	mov rax, 1      ; write syscall ID
	mov rdi, 1      ; standard write
	mov rsi, text   ; mem address of text
	mov rdx, 14     ; length of the string
	syscall
	ret