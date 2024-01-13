


section .data                           ; data section: where all raw data goes
	text db "Hello, World!", 10 		; define bytes: ""
										; each character is a byte
										; e.g
										; H  : 72 = 0x48 = 0b01001000
										; "  : 34 = 0x22 = 0b00100010
										; /n : 10 = 0x0A = 0b00001010

										; text : mem address

; section bss							; mem alloc section: here not used

section .text                           ; text section: where the code goes
	global _start

_start:									; OS starts here
										; linker finds this label and make the obj code

										; set-up syscall: write(standard output,
										;						mem addr of string,
										;						length of string)

	mov rax, 1                          ; rax = ID = 1 : syscall = write
	mov rdi, 1                          ; rdi = arg1 = 1 : standard output
	mov rsi, text                       ; rsi = arg2 = mem addr of string (start thereof)
	mov rdx, 14                         ; rdx = arg3 = length of the string

	syscall								; ask the kernel to do a system call
										; use as arguments what is stored in

										; rax = ID <-- type of call (function)

										; rdi = arg1
										; rsi = arg2
										; rdx = arg3
										; r10 = arg4,
										; r8 = arg5
										; r9 = arg6

										; ID

										; 0 = sys_read (filedescriptor, &buffer, count)
										; 1 = sys_write (filedescriptor, &buffer, count)
										;		write to screen!
										;			descriptor: 0 (standard input)
										;						1 (standard output)
										;			&buffer: address of start of string
										;			count: length of string (n of bytes)
										; 2 = sys_open (&filename, flags, mode)
										; 3 = sys_close (filedescriptor)
										; 60 = sys_exit (error_code)
										; 328 = ...

	mov rax, 60							; ID = 60 : system exit
	mov rdi, 0                          ; arg1 = 0 : no error code
	syscall                             ; exit the program
