#   Solución

## Análisis del Código Original

Cuando presionas la tecla `'c'`, se llama a la función `createObjectInStack()`. En la versión original del código, el problema radica en que la esfera se está creando como una variable local dentro de esta función:

```cpp
Sphere localSphere(ofRandomWidth(), ofRandomHeight(), 30);
globalVector.push_back(&localSphere);
```

El objeto `localSphere` se almacena en el **stack**, lo que significa que cuando la función termina su ejecución, la memoria de `localSphere` se libera automáticamente. Sin embargo, el puntero a este objeto (`&localSphere`) se almacena en `globalVector`, lo que provoca que `globalVector` contenga una referencia a una dirección de memoria inválida (**dangling pointer**). Cuando el programa intenta acceder a esta dirección más tarde (por ejemplo, al intentar dibujar la esfera en `draw()`), puede causar un comportamiento inesperado, como:

- **Crash**: Acceder a memoria liberada es un comportamiento indefinido.
- **Datos corruptos**: La memoria puede haber sido sobrescrita por otra función.
- **Resultados inesperados**: A veces, el programa puede seguir funcionando erróneamente hasta que otra parte del código sobrescriba esa memoria.

---

## En la versión corregida

```cpp
Sphere* heapSphere = new Sphere(ofRandomWidth(), ofRandomHeight(), 30);
globalVector.push_back(heapSphere);
```

Aquí, el objeto `Sphere` se aloja en el **heap** usando `new`. Esto significa que la memoria del objeto **no** se liberará automáticamente cuando termine la función, sino que permanecerá disponible hasta que el programa explícitamente la libere con `delete`.

Cuando presionas `'c'` ahora:
1. Se crea una nueva esfera en el heap.
2. Se almacena un puntero válido en `globalVector`.
3. El objeto no desaparece cuando `createObjectInStack()` termina.
4. La esfera se puede dibujar sin problemas.


