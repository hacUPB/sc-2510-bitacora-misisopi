# Solución

### ¿Cuál es la definición de un puntero?

Un puntero es una variable que almacena la dirección de memoria de otra variable. En C++, los punteros se declaran usando el operador *.

### ¿Dónde está el puntero?

En el código, hay varios punteros, pero el más relevante es:

- `Sphere* selectedSphere;`

Este es un puntero a un objeto de la clase Sphere. También hay un vector de punteros a Sphere:

- `vector<Sphere*> spheres;`

### ¿Cómo se inicializa el puntero?

selectedSphere se inicializa en setup() como nullptr:

- `selectedSphere = nullptr;`

Los punteros dentro del vector spheres se crean con new en setup(), almacenando direcciones de objetos Sphere dinámicamente asignados:

- `spheres.push_back(new Sphere(x, y, radius));`

### ¿Para qué se está usando el puntero?

- `selectedSphere` se usa para almacenar la dirección de la esfera seleccionada cuando el usuario hace clic en ella.

- Si `selectedSphere` no es `nullptr`, su posición se actualiza para seguir la posición del mouse en `update()`.

### ¿Qué es exactamente lo que está almacenado en el puntero?

- `selectedSphere` almacena la dirección de un objeto Sphere en la memoria.

- Cada elemento en spheres es un puntero que almacena la dirección de un objeto Sphere creado con new.