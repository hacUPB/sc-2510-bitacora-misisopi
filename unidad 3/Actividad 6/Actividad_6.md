# Solución

- Cuando se presiona el botón izquierdo del mouse (`mousePressed`), se selecciona la esfera más cercana.

- Mientras el botón esté presionado (`update`), la esfera seleccionada sigue la posición del mouse.

- Cuando se suelta el botón (`mouseReleased`), selectedSphere se establece en `nullptr`, lo que detiene el movimiento.

### Modificación en `ofApp.h`

```c++
void mouseReleased(int x, int y, int button);
```

### Modificación en `ofApp.cpp`

```c++
void ofApp::mouseReleased(int x, int y, int button){
    if (button == OF_MOUSE_BUTTON_LEFT) {
        selectedSphere = nullptr; // Sulta la esfera cuando se suelta el botón
    }
}
```