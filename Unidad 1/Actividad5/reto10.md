# Solución

Las posiciones de memoria RAM de 0 a 15 tienen los nombres simbólico R0 a R15. Escribe un programa en lenguaje ensamblador que guarde en R1 la operación 2 * R0.

```asm
@R0
D=M
D=D+M
@R1
M=D
```