# Solución

Implementa en lenguaje ensamblador:

```c++
if ( (D - 7) == 0) goto a la instrucción en ROM[69]
```

```asm
@D
D=M
@7
D=D-A
@69
D;JEQ
```