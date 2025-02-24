### Reto 2: Implementar con For en vez de While
 ```asm
@0
D=A
@sum
M=D

@1
D=A
@i
M=D

(FOR_LOOP)
@i
D=M
@101
D=D-A
@END_FOR
D;JGE

@i
D=M
@sum
M=M+D

@i
M=M+1

@FOR_LOOP
0;JMP

(END_FOR)
@END_FOR
0;JMP
```
