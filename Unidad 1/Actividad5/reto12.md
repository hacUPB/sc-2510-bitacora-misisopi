# Solución

Implemente en ensamblador:

```asm
R4 = R1 + R2 + 69
```


```asm
@R1
D=M
@R2
D=D+M
@69
D=D+A
@R4
M=D
```