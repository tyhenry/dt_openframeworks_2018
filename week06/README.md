# Week 6

## Example Code

### From in-class code:

- **01_particle_systems** - create particle emitters on mouse click  
- **02_attraction** - simple attraction force, follow the mouse

### More examples:

- **03_attraction_repulsion** - create a grid of Movers, apply attraction and repulsion based on mouse
- **04_attractors** - create Attractor class, model gravity (see [Reading](#gravity))
- **05_elastic** - create an elastic force, particles spring back to starting point

## Homework

### Reading: The Nature of Code

- <a name=gravity>**[The Nature of Code: Chapter 2 Section 9 "Gravitational Attraction"](http://natureofcode.com/book/chapter-2-forces/#chapter02_section9)**

- **[The Nature of Code: Chapter 4 "Particle Systems"](http://natureofcode.com/book/chapter-4-particle-systems/)**

    Remember that **The Nature of Code** is written in the Processing language (Java), but the concepts of physics-based animation are easily translated to C++/oF.


### Sketches

1. **Firework Display** 

    Using **particle systems**, create a sketch that makes colorful firework-like explosions.  The "explosions" should be composed of **_particles_** that _decay_ over time (and probably are affected by gravity, or other forces)...
    
    **Bonus:** Make an interactive firework *launcher* (for example, angle and force of launch is controlled by mouse - think *Angry Birds*...)

2. **Interstellar**

    Create a "space" scene, taking inspiration from the orbital motion of galaxies, stars, planets, moons, comets, asteroids... (... and black holes? :sweat_smile:)  
    Get creative, and don't feel limited by duplicating the _actual_ laws of physics.  You can modify physics to suit your ideas!
      
    Your objects (e.g. your stars, planets, or asteroids, etc.) should be instances of classes that you design.  They should use **forces** like **_attraction_** and **_repulsion_** (or design your own forces).
    
    Now make it interactive! :innocent:
    
    **Bonus:** Game-ify it!  Think about classic space shooters, like [Asteroids](https://www.kevs3d.co.uk/dev/asteroids/index-debug.html)...
    

## Class Review

### Normalizing Vectors

Recall that a vector has both a direction and a magnitude.  
What if we just want to know the direction, but don't care about the magnitude?  

When we **normalize** a vector, we set its magnitude to 1.0, but keep the direction.  
A vector with a magnitude of 1.0 is called a _unit vector_.
   
To **normalize**, we just divide the vector by its magnitude: 

```c++
glm::vec2 vec 	= glm::vec2(3,3);
float length 	= glm::length(vec);

glm::vec2 normVec;
if (length != 0) 	// avoid dividing by 0!!!
{
    normVec = vec / length;
}
```

Use the `glm::length(vec)` function to get the length of any vector.  

_Note: Before normalizing, check the length is not 0.  
Always avoid dividing by 0 - it will crash your app!_

### Forces: Attraction, Repulsion and Damping (a.k.a. drag)

**Attraction and repulsion** are forces that describe interaction **between** objects.  
These simple forces allow us to create complex physics systems, where multiple objects affect each other.  

Attraction is a force based on the direction of an object to a target (the "Attractor").  
To get the direction, we **normalize** the vector between the objects:

```c++
// Attraction

glm::vec2 dir 				= target.pos - mover.pos;
float distance          	= glm::length(dir);
float attractionStrength 	= 0.5; 

if (length != 0) {
	glm::vec2 attraction 	= dir/distance * attractionStrength;
	mover.applyForce(attraction);
}
```

**Repulsion** is simply the inverse of **attraction**:

```c++
// Repulsion

glm::vec2 dir 				= target.pos - mover.pos;
float distance          	= glm::length(dir);
float repulsionStrength 	= 0.5; 

if (length != 0) {
	glm::vec2 repulsion 	= dir/distance * repulsionStrength * -1;	// invert by multiplying by -1
	mover.applyForce(repulsion);
}
```
    
A **damping** force slows things down.  It's also called "drag".  
It creates the feeling of moving through fluid, where objects will eventually come to a stop.

We create a **damping** force by pushing on the object in the inverse direction of its velocity:

```c++
float speed 			= glm::vec2(mover.velocity);
if (speed != 0) {
	glm::vec2 damping 	= mover.velocity / speed * -0.01; 	// 0.01 damping
	mover.applyForce(damping);
}
```

### Particle Systems

We can think of a "particle system" as simply a class that manages a collection of particle objects.  
In our case, this collection is a `vector<Particle>`.
 
The particle system takes care of creating new particles:  

```c++
particles.push_back(Particle());
```  

and removing particles when the vector is getting too large:

```c++
// remove as many particles as needed to keep size < 1000

while (particles.size() > 1000) {			// max 1000 particles
	particles.erase(particles.begin()); 	// erase the first particle from the vector
}
```