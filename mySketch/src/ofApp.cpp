#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    srand(static_cast<unsigned>(time(0))); // Seed random with current time
    total_mass = 0;
    mass = MED_MASS; // Default mass
    enlarge = false;
    sun_active = false;
    damppen = false;
    
    Tiny.visible = true;
    Small.visible = true;
    Medium.visible = true;
    Large.visible = true;
    WTF.visible = true;
    
    random.visible = true;
    grid.visible = true;
    view.visible = true;
    Sun.visible = true;
    Damppen.visible = true;
    
    big_g.setup("Big G", 150, -200, 500);
    big_g.setPosition(535, ofGetWindowHeight() - 45);
    big_g.setSize(random.xpos - 540, 38);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    for (int i = 0; i < particle_list.size(); i++) {
        particle_list[i].resetForce();
    }
    
    for (int i = 0; i < particle_list.size(); i++) {
        particle_list[i].updateForces(particle_list, sun_active, damppen, big_g);
    }
    
    for (int i = 0; i < particle_list.size(); i++) {
        particle_list[i].updateVelPos();
    }
    
    // Getting rid of far away particles
    for (int i = 0; i < particle_list.size(); i++) {
        if (particle_list[i].dist_from_center() < KILL_RADIUS) {
            particles_to_keep.push_back(Particle(particle_list[i].get_x_pos(), particle_list[i].get_y_pos(), particle_list[i].get_x_vel(), particle_list[i].get_y_vel(), particle_list[i].get_mass(), particles_to_keep.size()));
        }
    }
    particle_list.clear();
    total_mass = 0;
    for (int i = 0; i < particles_to_keep.size(); i++) {
        particle_list.push_back(Particle(particles_to_keep[i].get_x_pos(), particles_to_keep[i].get_y_pos(), particles_to_keep[i].get_x_vel(), particles_to_keep[i].get_y_vel(), particles_to_keep[i].get_mass(), particle_list.size()));
        
        total_mass += particles_to_keep[i].get_mass();
    }
    particles_to_keep.clear();
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    drawBoard();
    
    Tiny.draw();
    Small.draw();
    Medium.draw();
    Large.draw();
    WTF.draw();
    
    random.draw();
    grid.draw();
    view.draw();
    Sun.draw();
    Damppen.draw();
    
    big_g.draw();
    //.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    int upper_key = toupper(key); // Standardize on upper case
    
    if (upper_key == 'A' ) {
        mass = TINY_MASS;
        
    } else if (upper_key == 'S' ) {
        mass = SMALL_MASS;
        
    } else if (upper_key == 'D' ) {
        mass = MED_MASS;
        
    } else if (upper_key == 'F' ) {
        mass = LARGE_MASS;
        
    } else if (upper_key == 'G' ) {
        mass = WTF_MASS;
        
    } else if (upper_key == ' ' ) { // Clears board of particles
        mass = MED_MASS;
        particle_list.clear();
        big_g = 150;
        
    } else if (upper_key == '1' ) {
        big_g = 150;
        
    } else if (upper_key == '0' ) {
        big_g = 0;
        
    } else if (upper_key == 'Z' ) {
        make_grid();
    
    } else if (upper_key == 'X' ) {
        make_random();
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
    if (Tiny.checkClick(x,y)) {
        mass = TINY_MASS;
        
    } else if (Small.checkClick(x, y)) {
        mass = SMALL_MASS;
        
    } else if (Medium.checkClick(x, y)) {
        mass = MED_MASS;
        
    } else if (Large.checkClick(x, y)) {
        mass = LARGE_MASS;
        
    } else if (WTF.checkClick(x, y)) {
        mass = WTF_MASS;
        
    } else if (random.checkClick(x, y)) {
        make_random();
    
    } else if (grid.checkClick(x, y)) {
        make_grid();
        
    } else if (view.checkClick(x, y)) {
        enlarge = !enlarge;
        if (enlarge) {
            view.title = "Decrease Particle Size";
        } else {
            view.title = "Increase Particle Size";
        }
        
    } else if (Sun.checkClick(x, y)) {
        sun_active = !sun_active;
        if (sun_active) {
            Sun.title = "Turn Sun Off";
        } else {
            Sun.title = "Turn Sun On";
        }
        
    } else if (Damppen.checkClick(x, y)) {
        damppen = !damppen;
        if (damppen) {
            Damppen.title = "Turn Damppen Off";
        } else {
            Damppen.title = "Turn Damppen On";
        }
        
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
        particle_list[i].draw(enlarge);
    }
    display_welcome();
    display_stats();
}

void ofApp::createParticle(float x, float y, float x_vel, float y_vel, double particle_mass) {
    particle_list.push_back(Particle(x, y, x_vel, y_vel, particle_mass, particle_list.size()));
    total_mass += mass;
}

void ofApp::display_stats() {
    
    string message = "Particles in field:  ";
    message += to_string(particle_list.size());
    ofSetColor(0, 0, 0);
    ofDrawBitmapString(message, 10, 75);
    
    message = "Total mass in field: ";
    message += to_string(total_mass);
    ofDrawBitmapString(message, 10, 90);
    
    message = "Selected mass:       ";
    message += to_string((int) mass);
    ofDrawBitmapString(message, 10, 105);
    
}

void ofApp::display_welcome() {
    string message = "Welcome to Gravity Simulator!";
    ofSetColor(0,0,0);
    ofDrawBitmapString(message, 10, 15);
    
    message = "Click and release to create a particle.\nDrag to give the particle initial velocity.\nPress Space to clear board.";
    ofSetColor(0,0,0);
    ofDrawBitmapString(message, 10, 30);
}

void ofApp::make_grid() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            createParticle(i * (ofGetWindowWidth()/9), j * (ofGetWindowHeight()/9), 0, 0, mass);
        }
    }
}

void ofApp::make_random() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            float rand_x = static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(ofGetWindowWidth())));
            float rand_y = static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(ofGetWindowHeight())));
            
            float rand_x_vel = MIN_RAND_VEL + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(MAX_RAND_VEL - MIN_RAND_VEL)));
            float rand_y_vel = MIN_RAND_VEL + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(MAX_RAND_VEL - MIN_RAND_VEL)));
            
            createParticle(rand_x, rand_y, rand_x_vel, rand_y_vel, mass);
        }
    }
}
