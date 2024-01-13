
section .data
	line db 0, 10; 2 characters 0 \n

section .text
	global _start

_start:
	

	push 1

	sub rsp, 8             ; move to next stack address (8 bytes down in mem)
						   ; eg from 0000 4008 to 0000 4000
						   ; (each byte is a addressable but we want to point to next QWORD)
						    
	mov QWORD [rsp], 2     ; put 2 at new stack adress

	mov rdx, 0
	pop rcx
	add rdx, rcx
	pop rcx
	add rdx, rcx	

	mov rbx, rdx

	call _printRBX

	call _exit

_printRBX: ; print the digit stored in RBX

	mov rax, rbx       ;
	add rax, 48        ; 0 = 48 (ascii)
	mov [line], al     ; first byte of rax
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