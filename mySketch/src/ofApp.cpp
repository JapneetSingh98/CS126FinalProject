#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    srand(static_cast<unsigned>(time(0))); // Seed random with current time
    mass = 1000; // Default mass
    //button = SimpleButton("test", ofGetWindowWidth()/2,ofGetWindowHeight()/2);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    for (int i = 0; i < particle_list.size(); i++) {
        particle_list[i].resetForce();
    }
    
    for (int i = 0; i < particle_list.size(); i++) {
        particle_list[i].updateForces(particle_list);
    }
    
    for (int i = 0; i < particle_list.size(); i++) {
        particle_list[i].updateVelPos();
    }
    
    // Getting rid of far away particles
    for (int i = 0; i < particle_list.size(); i++) {
        if (particle_list[i].dist_from_center() < 850) {
            particles_to_keep.push_back(Particle(particle_list[i].get_x_pos(), particle_list[i].get_y_pos(), particle_list[i].get_x_vel(), particle_list[i].get_y_vel(), particle_list[i].get_mass(), particles_to_keep.size()));
        }
    }
    particle_list.clear();
    for (int i = 0; i < particles_to_keep.size(); i++) {
        particle_list.push_back(Particle(particles_to_keep[i].get_x_pos(), particles_to_keep[i].get_y_pos(), particles_to_keep[i].get_x_vel(), particles_to_keep[i].get_y_vel(), particles_to_keep[i].get_mass(), particle_list.size()));
    }
    particles_to_keep.clear();
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    drawBoard();
    Small.visible = true;
    Medium.visible = true;
    Large.visible = true;
    WTF.visible = true;
    Small.draw();
    Medium.draw();
    Large.draw();
    WTF.draw();
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
        
    } else if (upper_key == ' ' ) { // Clears board of particles
        mass = 1000;
        particle_list.clear();
        
    } else if (upper_key == 'Z' ) {
        make_grid();
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
    if (Small.checkClick(x, y)) {
        mass = 1;
        
    } else if (Medium.checkClick(x, y)) {
        mass = 1000;
        
    } else if (Large.checkClick(x, y)) {
        mass = 10000;
        
    } else if (WTF.checkClick(x, y)) {
        mass = 100000;
        
    } else {
        createParticle(x_pos, y_pos, (x-x_pos)*2, (y-y_pos)*2, mass);
    }
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
    display_num_particles();
}

void ofApp::createParticle(float x, float y, float x_vel, float y_vel, double particle_mass) {
    particle_list.push_back(Particle(x, y, x_vel, y_vel, particle_mass, particle_list.size()));
    
}

void ofApp::display_num_particles() {
    
    string message = "Particles in field: ";
    message += to_string(particle_list.size());
    
    ofSetColor(0, 0, 0);
    ofDrawBitmapString(message, 10, 15);
    
}

void ofApp::make_grid() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            createParticle(i * (ofGetWindowWidth()/9), j * (ofGetWindowHeight()/9), 0, 0, mass);
        }
    }
}
