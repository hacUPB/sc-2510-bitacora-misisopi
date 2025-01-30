# Solución

Lee lo que hay en la posición 100 de la RAM, resta 15 y guarda el resultado en la posición 100 de la RAM.

```asm
@100
D=M
@15
D=D-A
@100
M=D
```