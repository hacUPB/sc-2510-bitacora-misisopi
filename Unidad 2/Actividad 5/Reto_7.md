# Solución

```asm
// Asignación de valores iniciales
@10
D=A
@a
M=D    // a = 10

@5
D=A
@b
M=D    // b = 5

// Asignar la dirección de 'a' al puntero 'p'
@a
D=A    // D = dirección de a
@p
M=D    // p = &a

// Asignar el valor de 'a' a 'b' a través de 'p'
@p
D=M    // D = p (dirección de a)
A=D    // A = dirección de a
D=M    // D = valor de a (10)
@b
M=D    // b = *p (b = 10)

// Fin del programa
(END)
@END
0;JMP
```

# Explicación paso a paso del programa en ensamblador Hack

## 1. Inicialización de variables
- Se almacena el valor `10` en la variable `a`.
- Se almacena el valor `5` en la variable `b`.

```asm
@10
D=A
@a
M=D    // a = 10

@5
D=A
@b
M=D    // b = 5
```

## 2. Asignar la dirección de `a` al puntero `p`
- `p = &a` → `p` almacena la dirección de `a`.

```asm
@a
D=A    // D = dirección de a
@p
M=D    // p = &a
```

## 3. Asignar el valor de `a` a `b` usando `p`
- `b = *p` → Se obtiene el valor almacenado en la dirección apuntada por `p` y se asigna a `b`.

```asm
@p
D=M    // D = p (dirección de a)
A=D    // A = dirección de a
D=M    // D = valor de a (10)
@b
M=D    // b = *p (b = 10)
```

## 4. Finalización del programa
- Se crea un bucle infinito en `(END)` para evitar que el programa siga ejecutando instrucciones no deseadas.

```asm
(END)
@END
0;JMP
```

---

# Tabla de salida esperada en memoria

| Dirección | Variable | Valor    |
|-----------|----------|----------|
| `0x0010`  | `a`      | `10`     |
| `0x0011`  | `b`      | `10`     |
| `0x0012`  | `p`      | `0x0010` |