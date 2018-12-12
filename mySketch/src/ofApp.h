#pragma once

#include "ofMain.h"
#include "particles.hpp"
#include "SimpleButton.h"
#include <cstdlib>
#include <ctime>
#include "ofxGui.h"

class ofApp : public ofBaseApp{
private:
    std::vector<Particle::Particle> particle_list;
    std::vector<Particle::Particle> particles_to_keep;
    
    const int TINY_MASS = 1;
    const int SMALL_MASS = 100;
    const int MED_MASS = 1000;
    const int LARGE_MASS = 9000;
    const int WTF_MASS = 100000;
    
    const int KILL_RADIUS = 850;
    
    const int MIN_RAND_VEL = -50;
    const int MAX_RAND_VEL = 50;
public:
    ofApp() {
        
    }
    int count;
    bool enlarge;
    bool sun_active;
    bool damppen;
    
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
    void display_stats();
    void display_welcome();
    void make_grid();
    void make_random();
    
    float x_pos;
    float y_pos;
    double mass;
    int total_mass;
    
    //double velocity;
    //double gravity = 9.81;
    
    void createParticle(float x, float y, float x_vel, float y_vel, double mass);
    void drawBoard();
    
    //std::vector<Particle> get_particle_list();
    
    SimpleButton Tiny = SimpleButton("Tiny", 10,ofGetWindowHeight() - 45);
    SimpleButton Small = SimpleButton("Small", 115,ofGetWindowHeight() - 45);
    SimpleButton Medium = SimpleButton("Medium", 220,ofGetWindowHeight() - 45);
    SimpleButton Large = SimpleButton("Large", 325,ofGetWindowHeight() - 45);
    SimpleButton WTF = SimpleButton("WTF", 430,ofGetWindowHeight() - 45);
    
    SimpleButton random = SimpleButton("Random", ofGetWindowWidth() - 449,ofGetWindowHeight() - 45);
    SimpleButton grid = SimpleButton("Grid", ofGetWindowWidth() - 344,ofGetWindowHeight() - 45);
    SimpleButton Sun = SimpleButton("Turn Sun On", ofGetWindowWidth() - 239,ofGetWindowHeight() - 45);
    SimpleButton Damppen = SimpleButton("Turn Damppen On", ofGetWindowWidth() - 134,ofGetWindowHeight() - 45);
    
    SimpleButton view = SimpleButton("Increase Particle Size", ofGetWindowWidth() - 190,10);
    
    ofxFloatSlider big_g;
    
    
    
};
