# Solución

Implementa en ensamblador el siguiente problema. En la posición R0 está almacenada la dirección inicial de una región de memoria. En la posición R1 está almacenado el tamaño de la región de memoria. Almacena un -1 en esa región de memoria.

```asm
@R1
D=M
@END
D;JEQ        // Si tamaño == 0, salta

@R0
A=M
M=-1         // RAM[R0] = -1

@R0
M=M+1        // Incrementa la dirección en R0

@R1
M=M-1        // Decrementa el tamaño en R1
```