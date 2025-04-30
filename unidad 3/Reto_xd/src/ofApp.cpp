#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    cam.setupPerspective(); //trate de configurar la camara con perspectiva
    distDiv = 50.0; //distancia en funcion de coseno
    amplitud = 150.0; //amplitud del relieve (?) en z
    step = 15; // espaciado entre esferas
    generateGrid(); // llama a la funcion q genera la esfera
}

//--------------------------------------------------------------
void ofApp::update() {} //nadita 

//--------------------------------------------------------------
void ofApp::draw() {
    ofBackground(200); //fondo gris
    cam.begin(); //activa la camara

    for (auto& pos : spherePositions) {
        // Color varía con la profundidad Z (de rojo oscuro a claro)
        ofSetColor(ofMap(pos.z, -amplitud, amplitud, 0, 255), 255, 0);
        ofDrawSphere(pos, 3); //dibuja una esfera pequeña
    }

    cam.end(); // finaliza la vista de camara

    string info = "FPS: " + ofToString(ofGetFrameRate()) + "\n";  //ofGetFrameRate() devuelve los fotogramas por segundo actuales (rendimiento). ofToString(...) convierte ese número en texto.
    info += "Step: " + ofToString(step) + "\n"; // Agrega a la cadena el valor de step, que indica la distancia entre esferas en el grind
    info += "DistDiv: " + ofToString(distDiv) + "\n"; //Muestra el valor de distDiv, que controla la frecuencia de la onda en el grnd (entre más alto, más plana se ve)
    info += "Amplitud: " + ofToString(amplitud) + "\n"; // Muestra el valor de amplitud, que indica la altura máxima de las ondas en z.
    ofDrawBitmapString(info, 20, 20); //Dibuja la cadena info como texto 2D en la pantalla. (20, 20) es la posición en píxeles desde la esquina superior izquierda.


}

//--------------------------------------------------------------
void ofApp::generateGrid() { 
    spherePositions.clear(); // Limpia las posiciones anteriores
    for (int x = -ofGetWidth() / 2; x < ofGetWidth() / 2; x += step) {
        for (int y = -ofGetHeight() / 2; y < ofGetHeight() / 2; y += step) {
            float z = cos(ofDist(x, y, 0, 0) / distDiv) * amplitud;
            spherePositions.push_back(glm::vec3(x, y, z)); // Añade cada esfera con una Z modulada
        }
    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
    glm::vec3 rayStart, rayEnd;
    convertMouseToRay(x, y, rayStart, rayEnd); // Convierte clic en un rayo

    for (auto& pos : spherePositions) {
        glm::vec3 intersectionPoint;
        if (rayIntersectsSphere(rayStart, rayEnd - rayStart, pos, 5.0, intersectionPoint)) {
            selectedSphere = pos; // Guarda la esfera seleccionada
            break;
        }
    }
}

//--------------------------------------------------------------
void ofApp::convertMouseToRay(int x, int y, glm::vec3& rayStart, glm::vec3& rayEnd) {
    glm::vec3 mouse(x, y, 0.0f);
    rayStart = cam.getPosition(); // Origen del rayo: posición de la cámara
    rayEnd = cam.screenToWorld(mouse); // Punto al que apunta el rayo en el mundo 3D
}

//--------------------------------------------------------------
bool ofApp::rayIntersectsSphere(const glm::vec3& rayStart, const glm::vec3& rayDir,
    const glm::vec3& sphereCenter, float sphereRadius,
    glm::vec3& intersectionPoint) {

    glm::vec3 oc = rayStart - sphereCenter; // Vector desde el centro de la esfera al inicio del rayo

    float a = glm::dot(rayDir, rayDir);     // a = |rayDir|^2 (producto punto consigo mismo)
    float b = 2.0f * glm::dot(oc, rayDir);  // b = 2 * (oc • rayDir), producto punto entre oc y la dirección
    float c = glm::dot(oc, oc) - sphereRadius * sphereRadius; // c = |oc|^2 - r^2

    float discriminant = b * b - 4 * a * c; // Fórmula cuadrática: determina si hay intersección

    if (discriminant < 0) {
        return false; // No intersección
    }

    float t = (-b - sqrt(discriminant)) / (2.0f * a);
    intersectionPoint = rayStart + t * rayDir;
    return true; // Hay intersección
}
