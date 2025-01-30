```asm
@R1
D=M
@END
D;JEQ        // Si tamaño == 0, salir

@R0
A=M
M=-1         // RAM[R0] = -1

@R0
M=M+1        // Incrementa la dirección en R0

@R1
M=M-1        // Decrementa el tamaño en R1
```