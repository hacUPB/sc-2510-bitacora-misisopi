# Solución 

Suma el contenido de la posición 0 de la RAM, el contenido de la posición 1 de la RAM y con la constante 69. Guarda el resultado en la posición 2 de la RAM.

```asm
@0
D=M
@1
D=D+M
@69
D=D+A
@2
M=D
```