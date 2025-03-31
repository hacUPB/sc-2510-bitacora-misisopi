#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    cam.setupPerspective();
    distDiv = 50.0;
    amplitud = 150.0;
    step = 15;
    generateGrid();
}

//--------------------------------------------------------------
void ofApp::update() {}

//--------------------------------------------------------------
void ofApp::draw() {
    ofBackground(200);
    cam.begin();

    for (auto& pos : spherePositions) {
        ofSetColor(ofMap(pos.z, -amplitud, amplitud, 0, 255), 255, 0);
        ofDrawSphere(pos, 3);
    }

    cam.end();

    string info = "FPS: " + ofToString(ofGetFrameRate()) + "\n";
    info += "Step: " + ofToString(step) + "\n";
    info += "DistDiv: " + ofToString(distDiv) + "\n";
    info += "Amplitud: " + ofToString(amplitud) + "\n";
    ofDrawBitmapString(info, 20, 20);
}

//--------------------------------------------------------------
void ofApp::generateGrid() {
    spherePositions.clear();
    for (int x = -ofGetWidth() / 2; x < ofGetWidth() / 2; x += step) {
        for (int y = -ofGetHeight() / 2; y < ofGetHeight() / 2; y += step) {
            float z = cos(ofDist(x, y, 0, 0) / distDiv) * amplitud;
            spherePositions.push_back(glm::vec3(x, y, z));
        }
    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
    glm::vec3 rayStart, rayEnd;
    convertMouseToRay(x, y, rayStart, rayEnd);

    for (auto& pos : spherePositions) {
        glm::vec3 intersectionPoint;
        if (rayIntersectsSphere(rayStart, rayEnd - rayStart, pos, 5.0, intersectionPoint)) {
            selectedSphere = pos;
            break;
        }
    }
}

//--------------------------------------------------------------
void ofApp::convertMouseToRay(int x, int y, glm::vec3& rayStart, glm::vec3& rayEnd) {
    glm::vec3 mouse(x, y, 0.0f);
    rayStart = cam.getPosition();
    rayEnd = cam.screenToWorld(mouse);
}

//--------------------------------------------------------------
bool ofApp::rayIntersectsSphere(const glm::vec3& rayStart, const glm::vec3& rayDir,
    const glm::vec3& sphereCenter, float sphereRadius,
    glm::vec3& intersectionPoint) {
    glm::vec3 oc = rayStart - sphereCenter;
    float a = glm::dot(rayDir, rayDir);
    float b = 2.0f * glm::dot(oc, rayDir);
    float c = glm::dot(oc, oc) - sphereRadius * sphereRadius;
    float discriminant = b * b - 4 * a * c;

    if (discriminant < 0) {
        return false;
    }

    float t = (-b - sqrt(discriminant)) / (2.0f * a);
    intersectionPoint = rayStart + t * rayDir;
    return true;
}
