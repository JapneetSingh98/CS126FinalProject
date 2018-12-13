# FinalProject
This is a gravity simulator that allows the user to create particles on the screen and see how they interact with one another gravitationally. This simulator allows the user to choose the mass of the particles, the location at which they are placed, and their initial velocity. It also allows them to adjust the Big G constant and place pre-set patterns of particles. 

# Reasoning
I created this project because I really enjoy seeing how things interact in the physical world. As a someone who really enjoys space, I thought that this project would be a fun way to combine space related simulations with CS. I spend a lot of time messing around with another simulator (http://www.nowykurier.com/toys/gravity/gravity.html) so that is what I based my project off of visually.

# Mechanics
Users can use the on screen buttons and sliders to controll the mass of the particles that they are about to place down, as well as the value of Big G. The "Grid" and "Random" buttons allow the user to add in 100 particles, either in a 10x10 grid with no initial velocity, or with random locations and random initial velocities. The "Sun" button adds an attraction point at the center of the screen which has a mass of 2500. This "Sun" in stationary and doesn't appear on screen. The "Damppen" button reduces the velocity of the particles by 1% between each frame, and acts as a sort of friction in the field. The "Increase Particle Size" button increases the radius of the particles in order to make them appear bigger on screen. This was in response to my classmates not being able to see some of the smaller particles in during code reviews. 

For a user to place a particle, they simply move their mouse to a desired location and click. In order to give the particle initial velocity, the user can drag the mouse before releasing. 

Particles are automatically removed from the simulation after they move a certain distance (850) from the center. This is to prevent the computer from constantly trying to render them when they are not of interest anymore. 

# Developers
This code uses openFrameworks and was written on Xcode. I use the ofxGui and ofxButtons, which also requires ofxXmlSettings.
