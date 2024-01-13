
FLAG register = bunch of bits, each bit is a flag
                CF, PF, ZF, SF, OF, AF, IF
                --> Carry, Parity, Zero, Sign, etc.

POINTER register = mem address; points to some data (eg value / addr)

    x64 x32 x16
    -------------
    rip (eip, ip) = index pointer / program counter
    rsp (esp, sp) = top stack pointer
    rbp (ebp, bp) = base stack pointer

    Stack:
    ----- <- rsp = -16(rbp) (2 x 64 bits = 2 x 8 bytes away from rbp)
    -----
    ----- <- rbp

JUMPS

jmp label <--- loads the mem value of the "label" section in the rip register

COMPARISON

Comparison is done on registers or register/immediate:

cmp rax, rbx <- rax = rbx ?
cmp rax, 42 <- rax == 42?

Flags will be set: a == b -> ZF = 1
                    a != b -> ZF = 0
                    a > b -> SF = MSB(a-b)

Note: MSB = most significant bit

CONDITIONAL JUMP

Jump if flag = ....

je : a == b
jne : a != b
jg  : a > b
jge : a >= b
jl : a < b
jle : a <= b
jz : a == 0
jnz : a != 0

Example:

cmp rax, 23     ; rax == 23 ?
je _mySection   ; jumps to my section given ZF

cmp rax, rbx    ; rax > rbx ?
jg _mySection   ; jumps to my section given SF 

POINTERS ctd

If rax = mem addr
then [rax] = value @ location rax
eg

mov rax, [rbx]  ; loads value @ location rbx into rax

CALLS

A call is a special kind of JUMP.
At a call the IP is stored.
After the call, ret sets the IP to the original IP.

SUBROUTINE

Calling a section is called calling a subroutine. 

DEBUGGING

Compile using:

E.g. for the program greet.asm:

nasm -f elf64 -F dwarf -g greet.asm -o greet.o
ld greet.o -o greet
gdb ./greet
break _start
run
lay next
ref

MATH OPS

add a, b ; a = a + b eg add rax, rbx

mul c ; rax = rax * c eg mul rbx (unsigned)
imul c ; rax = rax * c eg imul rbx (signed)
div
idiv
neg a ; a = -a
inc a ; a += 1
dec a ; a -= 1
adc a, b ; a = a + b (CF = 1)

ASCII

7 - bit codes; extended ASCII : 8-bit codes...
0 - 127...
48 = 0
65 = A
97 = a

EQU

We can write labelled constants using equ eg:

SYS_EXIT equ 60

and then use

mov rax, SYS_EXIT

instead of

mov rax, 60

---> makes code more readable.

MACROs

Macros are expanded out by preprocessor.

Macro with 0 arguments:

%macro exit 0
    mov rax, SYS_EXIT
    mov rdi, 0
    syscall
%endmacro

_start:
    
    exit

With 1 argument

%macro printDigit 1
    mov rax, %1
    call _printRAXDigit
%endmacro

We can make macros that define a label.

%macro freeze 0
_loop:
    jmp _loop
%endmacro

_start:
    freeze
    freeze
    exit

will not compile as we have two label definitions:

_loop:
    jmp _loop
_loop:
    jmp _loop

Can be solved using

%macro freeze 0
%%_loop:
    jmp %%_loop
%endmacro

which will compile symbolically to

_1loop:
    jmp _1loop
_2loop:
    jmp _2loop

INCLUDE

We can include external files code using eg

%include "macros.asm"

and then

%include "macros.asm"

section .data
    text db "hello world!",10,0
....
_start:
    print text
    exit

will run.

----










