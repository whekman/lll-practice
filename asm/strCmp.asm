
section .data
	str1 db "Hello",10,0
	str2 db "Hello",10,0

	out0 db "0",10
	out1 db "1",10

section .text
	global _start

_start:
	
	push str1    ; put the two arguments on the stack
	push str2

_strCmp:
	
	pop rbx  ; pop 2nd arg into rax (address of byte 1 of str2)
	pop rax  ; pop 1st arg into rax	

_cmpLoop:

	mov cl, [rax]
	mov dl, [rbx]
	cmp cl, dl ; a == b?
	jne _printOut0

	inc rax       ; move char pointer to next char
	inc rbx       ; ''

	cmp cl, 0
	jne _cmpLoop ; if a != 0 repeat

	; if a == 0
	je _printOut1

_printOut0:

	mov rax, 1
	mov rdi, 1
	mov rsi, out0
	mov rdx, 2
	syscall

	mov rax, 60 						;exit
	mov rdi, 0
	syscall

_printOut1:

	mov rax, 1
	mov rdi, 1
	mov rsi, out1
	mov rdx, 2
	syscall

	mov rax, 60 						;exit
	mov rdi, 0
	syscall