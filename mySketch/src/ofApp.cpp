#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    srand(static_cast<unsigned>(time(0))); // Seed random with current time
    mass = 1000; // Default mass
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i = 0; i < particle_list.size(); i++) {
        particle_list[i].resetForce();
    }
    
    for (int i = 0; i < particle_list.size(); i++) {
        particle_list[i].update(particle_list);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    drawBoard();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    int upper_key = toupper(key); // Standardize on upper case
    
    if (upper_key == 'A' ) {
        mass = 1;
        
    } else if (upper_key == 'S' ) {
        mass = 1000;
        
    } else if (upper_key == 'D' ) {
        mass = 10000;
        
    } else if (upper_key == 'F' ) {
        mass = 100000;
        
    } else if (upper_key == 'G' ) {
        mass = 1000000;
        
    } else if (upper_key == ' ' ) { // Clears board of particles
        mass = 1000;
        particle_list.clear();
    } 
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    x_pos = x;
    y_pos = y;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    createParticle(x_pos, y_pos, (x-x_pos)*2, (y-y_pos)*2, mass);
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

void ofApp::drawBoard() {
    for (int i = 0; i < particle_list.size(); i++) {
        particle_list[i].draw();
    }
}

void ofApp::createParticle(float x, float y, float x_vel, float y_vel, double particle_mass) {
    particle_list.push_back(Particle(x, y, x_vel, y_vel, particle_mass, particle_list.size()));
    
}
