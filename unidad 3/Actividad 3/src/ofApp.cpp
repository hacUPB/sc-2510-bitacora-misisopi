#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    ofBackground(15, 120, 34); // cambia el color en RGB, Red: 15 , Green: 120 , Blue: 34
    particleColor = ofColor::white;
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {
    for (auto& pos : particles) {
        ofSetColor(particleColor, 150); // 150 es la opacidad (0 = transparente, 255 = sólido)
        ofDrawCircle(pos.x, pos.y, ofRandom(10, 50)); // Tamaño aleatorio entre 10 y 50 píxeles
    }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {
    particles.push_back(ofVec2f(x, y));
    if (particles.size() > 10) { // Cambia el número de particulas, de 100 a 10
        particles.erase(particles.begin());
    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
    particleColor = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
}