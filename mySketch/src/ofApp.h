#pragma once

#include "ofMain.h"
#include "particles.hpp"

class ofApp : public ofBaseApp{
private:
    std::vector<Particle> particle_list;
public:
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
    
    //std::vector<Particle> get_particle_list();
    
    int x_pos;
    int y_pos;
    int size;
    
    double velocity;
    double gravity = 9.81;
    
    void createParticle(int x, int y, int x_vel, int y_vel);
    void drawBoard();
		
};
