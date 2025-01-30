# Solución

Implementa en ensamblador:

```asm
if R0 >= 0 then R1 = 1
else R1 = –1

(LOOP)
goto LOOP
```

```asm
@R0
D=M
@R1
M=1
D;JGE     // Si R0 >= 0, R1 = 1
M=-1      // Si R0 < 0, R1 = -1
```