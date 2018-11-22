#pragma once

#include "ofMain.h"
#include "particles.hpp"

class ofApp : public ofBaseApp{
private:
    std::vector<Particle::Particle> particle_list; 
public:
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
    
    float x_pos;
    float y_pos;
    double size;
    
    //double velocity;
    //double gravity = 9.81;
    
    void createParticle(float x, float y, float x_vel, float y_vel, double mass);
    void drawBoard();
    
    //std::vector<Particle> get_particle_list();
		
};
