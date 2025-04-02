#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp {
public:
    void setup();
    void update();
    void draw();
    void mousePressed(int x, int y, int button);

private:
    void generateGrid();
    void convertMouseToRay(int x, int y, glm::vec3& rayStart, glm::vec3& rayEnd);
    bool rayIntersectsSphere(const glm::vec3& rayStart, const glm::vec3& rayDir,
        const glm::vec3& sphereCenter, float sphereRadius,
        glm::vec3& intersectionPoint);

    ofEasyCam cam;
    std::vector<glm::vec3> spherePositions;
    glm::vec3 selectedSphere;
    float distDiv, amplitud, step;
};
