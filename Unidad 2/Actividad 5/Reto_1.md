### Reto 1: Sumar los primeros 100 números naturales con While
``` asm
@1
D=A
@i
M=D

@0
D=A
@sum
M=D

(WHILE_LOOP)
@i
D=M
@101
D=D-A
@END_LOOP
D;JGE

@i
D=M
@sum
M=M+D

@i
M=M+1

@WHILE_LOOP
0;JMP

(END_LOOP)
@END_LOOP
0;JMP
```
