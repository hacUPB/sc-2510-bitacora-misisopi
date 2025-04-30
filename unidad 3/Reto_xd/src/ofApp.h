#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp {
public:
    void setup();
    void update();
    void draw();
    void mousePressed(int x, int y, int button); // Evento al presionar el mouse

private:
    void generateGrid(); // Genera la grilla de esferas en 3D
    void convertMouseToRay(int x, int y, glm::vec3& rayStart, glm::vec3& rayEnd); // Convierte el clic del mouse en un rayo 3D
    bool rayIntersectsSphere(const glm::vec3& rayStart, const glm::vec3& rayDir,
        const glm::vec3& sphereCenter, float sphereRadius,
        glm::vec3& intersectionPoint); // Detecta colisión entre un rayo y una esfera

    /*rayStart: el origen del rayo (desde dónde sale).

     rayDir: la dirección del rayo (normalmente es rayEnd - rayStart).

     sphereCenter: el centro de la esfera.

     sphereRadius: el radio de la esfera.

     intersectionPoint: si hay colisión, aquí se guarda el punto exacto donde el rayo toca la esfera.*/

    ofEasyCam cam; //camara interactiva 
    std::vector<glm::vec3> spherePositions; // las posiciones de todas las esferas 
    glm::vec3 selectedSphere; // la esfera seleccionada intersectada 
    float distDiv, amplitud, step; //los parametros q calculan el grind
};
