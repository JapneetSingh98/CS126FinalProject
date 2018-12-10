#pragma once

#include "ofMain.h"
#include "particles.hpp"
#include "SimpleButton.h"

class ofApp : public ofBaseApp{
private:
    std::vector<Particle::Particle> particle_list;
    std::vector<Particle::Particle> particles_to_keep;
public:
    ofApp() {
        
    }
    int count;
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    void display_num_particles();
    void make_grid();
    
    float x_pos;
    float y_pos;
    double mass;
    
    //double velocity;
    //double gravity = 9.81;
    
    void createParticle(float x, float y, float x_vel, float y_vel, double mass);
    void drawBoard();
    
    //std::vector<Particle> get_particle_list();
    
    SimpleButton Small = SimpleButton("Small", 10,ofGetWindowHeight() - 45);
    SimpleButton Medium = SimpleButton("Medium", 115,ofGetWindowHeight() - 45);
    SimpleButton Large = SimpleButton("Large", 220,ofGetWindowHeight() - 45);
    SimpleButton WTF = SimpleButton("WTF", 325,ofGetWindowHeight() - 45);
    
		
};
