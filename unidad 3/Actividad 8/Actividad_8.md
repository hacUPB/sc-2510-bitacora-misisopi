# Solución

## ¿Cuándo Crear Objetos en el Heap y Cuándo en Memoria Global?

### Heap (Memoria Dinámica)

**Usa el heap cuando:**
- Necesitas que los objetos **persistan más allá del alcance de la función** que los creó.
- Se deben **crear y eliminar dinámicamente** en tiempo de ejecución.
- Los objetos son **grandes** y quieres evitar un **stack overflow**.
- Necesitas **controlar manualmente** su ciclo de vida con `new` y `delete`.

 **Ejemplo en el programa:**  
Cuando el usuario presiona `'h'`, se crea un nuevo objeto en el heap:
```cpp
Sphere* s = new Sphere(ofRandomWidth(), ofRandomHeight(), 30);
heapSpheres.push_back(s);
```

Los objetos en el heap **no se eliminan automáticamente**, por lo que debes liberarlos con `delete` para evitar **fugas de memoria**.
```cpp
void ofApp::exit() {
    for (Sphere* s : heapSpheres) {
        delete s;
    }
    heapSpheres.clear();
}
```

---

### Memoria Global

**Usa la memoria global cuando:**
- El objeto **debe existir durante toda la ejecución del programa**.
- Se necesita acceder desde **múltiples funciones** sin pasarlo como parámetro.
- No necesitas crear múltiples instancias dinámicamente.
- Es un objeto **pequeño** y su uso es claro.

**Ejemplo en el programa:**  
```cpp
Sphere globalSphere(300, 300, 30);
```
**Ventaja:**  
No necesitas preocuparte por liberar la memoria manualmente, ya que el sistema lo hace automáticamente al cerrar el programa.

---

### Resumen

| **Caso**            | **Usa Heap (`new`)** | **Usa Memoria Global** |
|--------------------|--------------------|--------------------|
| **Vida del objeto**  | Variable, puede liberarse en cualquier momento | Existe toda la ejecución del programa |
| **Creación**       | En tiempo de ejecución, dinámicamente | Desde el inicio del programa |
| **Control de memoria** | Necesitas usar `delete` para liberar memoria | Se gestiona automáticamente |
| **Uso recomendado**  | Cuando necesitas objetos dinámicos | Para objetos estáticos y de uso general |

**Regla general**: Usa el **heap** cuando necesites **flexibilidad**, y la **memoria global** cuando necesites **persistencia garantizada**.  

---

## Implementación en C++

### **Declaración en `ofApp.h`**
```cpp
#pragma once
#include "ofMain.h"
#include <vector>

// Clase Sphere
class Sphere {
public:
    Sphere(float x, float y, float radius);
    void draw() const;

    float x, y;
    float radius;
    ofColor color;
};

class ofApp : public ofBaseApp {
public:
    void setup();
    void update();
    void draw();
    void keyPressed(int key);
    void exit();

private:
    std::vector<Sphere*> heapSpheres; // Objetos en el heap
    void createObjectInStack();
};

// Declaración del objeto global
extern Sphere globalSphere;
```

### **Implementación en `ofApp.cpp`**
```cpp
#include "ofApp.h"

// Definición del objeto global
Sphere globalSphere(300, 300, 30);

// Implementación del constructor de Sphere
Sphere::Sphere(float x, float y, float radius) : x(x), y(y), radius(radius) {
    color = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
}

void Sphere::draw() const {
    ofSetColor(color);
    ofDra