#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    srand(static_cast<unsigned>(time(0))); // Seed random with current time
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    drawBoard();
    ofSetColor(0, 0, 0);
    ofDrawCircle(ofGetWindowWidth() / 2, ofGetWindowHeight() / 2, 15);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    int upper_key = toupper(key);
    if (upper_key == 'W') {
        ofSetColor(0, 0, 0);
        ofDrawCircle(ofGetWindowWidth() / 2, ofGetWindowHeight() / 2, 10);
    }
    update();
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
    //    std::cout << "mousePressed" << std::endl;
    //    ofDrawCircle(x, y, 3);
    //    update();
    x_pos = x; 
    y_pos = y;
    size = 20;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    createParticle(x_pos, y_pos, x - x_pos, y - y_pos);
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



void ofApp::createParticle(int x, int y, int x_vel, int y_vel) {
    particle_list.push_back(Particle(x, y, x_vel, y_vel));
}
