//
//  ParticleSystem.cpp
//  wk06_particle_system
//
//  Created by Tyler Henry on 10/2/18.
//

#include "ParticleSystem.hpp"

ParticleSystem::ParticleSystem(){
    
}

ParticleSystem::ParticleSystem(glm::vec2 _pos)
{
    pos = _pos;
}

void ParticleSystem::update(glm::vec2 force)
{
    int numNewParticles = 10;
    for (int i=0; i<numNewParticles; i++)
    {
        glm::vec2 vel = glm::vec2(ofRandom(-1,1), ofRandom(-1,-3));
        float mass = ofRandom(.1, 5);
        Particle particle = Particle(pos,vel,mass);
        particles.push_back(particle);
    }
    
    for (int i=0; i<particles.size(); i++)
    {
        particles[i].addForce(force);
        particles[i].update();
    }
    
    while (particles.size() > 1000)
    {
        // particles.erase(particles[2]);
        particles.erase(particles.begin()+2);
    }
    
    cout << "num particles: " << particles.size() << endl;
}

void ParticleSystem::draw()
{
    for (int i=0; i<particles.size(); i++)
    {
        particles[i].draw();
    }
}

