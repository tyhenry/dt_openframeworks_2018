# Week 7

## Code Examples

 - **00_attraction-repulsion_in-class** apply attraction and repulsion forces to a grid of "Movers", in-class coding exercise
 - **01_attraction-repulsion_extra** slightly more complex version of above, with extra features (toggle forces, etc.) and comments


## Homework: Start the Midterm, due Week 9 (Oct 23)

Start by coming up with a general project concept.  What do you want to visualize or create?  What type of animation and interaction would help you achieve that goal?  Now break that idea down into classes: what are the core elements of your concept?  What attributes do those elements have (variables)?  What behaviours could they exhibit (functions)?

**You should have a concept and some rough, initial prototype code ready to share with me by next week, Tues Oct. 16th.**  We will not have class (I am in London currently) but I will schedule office hours for Skype chats this week.

### Midterm project goals

- **Code an app in C++/openFrameworks that produces an interactive animation**, and which speaks to your own artistic or design interests!

 Feel free to explore generative design, physics simulation, games, abstract composition, color, images, drawing, data or math visualizations, motion graphics, or any aesthetic direction you wish.  You should show off your own skills and unique interests.

 You are welcome to combine this project with other classwork or outside work - but you must use openFrameworks, and there must be animation and interaction elements to your application.
 
- **Be ready to demo the app on the big screen in class on Tues, Oct. 23**

- You should organize your code using classes, objects, `vector`, and any of the C++ programming techniques we've learned so far.
  
### Animation techniques you can use:

+ `glm::vec2`, velocity, forces, attraction, particles, particle systems...
+ interpolation, `ofMap()`, scale...
+ oscillation, `sin(), cos(), atan2()`, rotation, angles...
+ `ofColor(), ofNoise(), ofGetElapsedTimef()`...

+ or feel free to explore techniques of your own choosing and interpretation!
  
_PS:_ To load and draw images, check out [`ofImage()`](http://openframeworks.cc/documentation/graphics/ofImage/) in the openFrameworks docs ([further reading in ofBook](http://openframeworks.cc/ofBook/chapters/image_processing_computer_vision.html#preliminariestoimageprocessing))
    
    
### Interaction 

Focus on mouse and keyboard!  Keep it simple first...

```c++
    ofGetMouseX(); ofGetMouseY(); ofGetPreviousMouseX(); ofGetPreviousMouseY();
    
    // ofApp functions
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
```


## Class Review

### Attraction and Repulsion Forces

Attraction and repulsion are relative forces, applied between objects.  One object may be attracted to, or repulsed by, another object.  This is different than "universal" forces such as "gravity" / "wind", which apply to everything in our scene.

In general, attraction force is calculated based on the vector from an object to its target (the object it is attracted to).  That vector is calculated:

```c++
glm::vec2 vector = target.pos - object.pos;	
// this vector represents an arrow pointing from the object to its target
```

That vector represents both the direction, and the distance from the object to its target.  
We can isolate the direction of the vector (and ignore the distance) by "normalizing" the vector (assigning its length to 1).  To normalize a vector, we divide it by its length:

```c++
float distance = glm::length(distance);
if (distance != 0){
	glm::vec2 norm = vector / length;	// be careful never to divide by 0! 
}
```

Now just apply the normalized vector as a force on the object (scaling it to alter the strength of the force).
All together:

```c++
glm::vec2 vector 	= target.pos - object.pos;	
float distance 		= glm::length(distance);
if (distance != 0){
	glm::vec2 norm = vector / length;	// be careful never to divide by 0! 
	object.applyForce( norm * 0.1 );	// 0.1 is attraction force strength here
}
```

Repulsion is simply the inverse of attraction.  Just make the force negative:

```c++	
object.applyForce( -norm * 0.1 );	// move away from target
```

### Elastic Force

Elastic force is simply an attraction of an object to its original position, after it has been moved.  It bounces back to its start.
The only difference here is that the object should keep track of its original position.  The original position is its attraction "target".

```c++
// elastic force bounces back to original position

glm::vec2 vector 	= object.originalPos - object.pos;	// original position is the target
float distance 		= glm::length(distance);
if (distance != 0){
	glm::vec2 norm = vector / length;	// be careful never to divide by 0! 
	object.applyForce( norm * 0.1 );	// 0.1 is attraction force strength here
}
```



