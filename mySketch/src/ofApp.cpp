#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    srand(static_cast<unsigned>(time(0))); // Seed random with current time
    size = 10;
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
        size = 1;
        
    } else if (upper_key == 'S' ) {
        size = 10;
        
    } else if (upper_key == 'D' ) {
        size = 100;
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
    createParticle(x_pos, y_pos, (x-x_pos)*2, (y-y_pos)*2, size);
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

void ofApp::createParticle(float x, float y, float x_vel, float y_vel, double size) {
    particle_list.push_back(Particle(x, y, x_vel, y_vel, size, particle_list.size()));
    
    //.push_back(createParticle(x, y, x_vel, y_vel, size));
}

//std::vector<Particle> ofApp::get_particle_list() {
//    return particle_list;
//}

