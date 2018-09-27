# Week 5 Homework

## Homework


### Sketches:

1. ### **Catch up** 

    on sketches from Week 3 if you are behind!  

2. ### **Act Natural**

    For this sketch, you will create an animation that mimics some natural motion.  
    
    **First, choose your movement:**
    
    Observe the motion of the world around you - notice leaves blowing in the wind, or a cat wagging its tail. Find or shoot a quick video of the motion you want to simulate for reference.  On paper, draw the course of the motion over time.
    
    [Watch this short video for reference/inspiration.](https://www.youtube.com/watch?v=yzJk6ww3LD0)  
    
    **Then, model the motion in code:**
      
    In oF, create a scene, and animate an object or shape (or a group of them!) based on your motion.
    
    To achieve the animation, you should use functions like `sin()`, `cos()`, `ofNoise()`, `atan2()`, interpolation, `ofGetElapsedTimef()`, or other techniques of your choosing.  
    (Check out [Robert Penner](http://robertpenner.com/easing/)'s or [Golan Levin](http://www.flong.com/texts/code/shapers_exp/)'s [easing equations](http://easings.net/) for many more.)
      
    It may help to break down your motion into elements:
    
    - Are there aspects of the motion that oscillate (repeat)?
    `sin()` is a good choice for modelling the oscillating parts (`ball.x = sin(time)`)
     
    - Or maybe there are parts that are more unpredictable?  
    `ofNoise()` is a good choice for smoothly random behavior.
    
    
    **Make it interactive:**  
    Add an element of interactivity:  
    Perhaps mouse position affects the speed, or mouse click restarts the animation... get creative!


### Reading

- Re-read **[ofBook: Simulation chapter](http://openframeworks.cc/ofBook/chapters/animation.html#simulation)**
    
## Code Examples

1. **`vector_of_balls`** - use `vector` container instead of array
2. **`mass`** - bouncing balls using mass: `Force = Mass x Acceleration`
3. **`noisy_followers`** - create a swarm of followers with noise-based positions
4. **`oscillation`** - draw [lissajous](https://en.wikipedia.org/wiki/Lissajous_curve)-like curves using `sin()` and `cos()`
5. **`atan2`** - calculate angle using `atan2(y,x)` function
6. **`signal_plot`** - plot `sin()` curves, modulating amplitude and frequency over time

## Review

### `vector`

In C++, we typically use `vector` containers instead of arrays to store groups of objects.  
A vector container is like an array, but doesn't have a fixed size.  You must declare the vector with a `<type>` - e.g. if you want a container of floats:  

`vector<float> vectorOfFloats;`

_note: Don't confuse this `vector` container with geometric vectors like `glm::vec2`!  They have the same name, but are very different._  

To add an element to a vector, we use the `vector::push_back(element)` function.  We can get the current size of the vector using `vector::size()`:

```c++
vector<float> myVector;
myVector.push_back(1.0);
myVector.push_back(2.5);
myVector.push_back(2897.7943);

// print the vector size and elements:

cout << "myVector.size(): " << myVector.size() << endl;
for (int i=0; i < myVector.size(); i++){
	cout << "myVector[" << i << "]: " << myVector[i] << endl;
}

/* prints:
   myVector.size(): 3
   myVector[0]: 1.0
   myVector[1]: 2.5
   myVector[2]: 2897.7943
*/
```

### `ofNoise()`: Order in Chaos

<img src="readme/3dnoise.gif" style="width:400px; height: 200px"/>

**Noise** is a way of **smoothly randomizing** things.  
You can think of "noise" as a cloudy "space", full of values ranging from 0.0 to 1.0.

You can access these values by inputting a set of "coordinates" in 1D, 2D, or 3D:

```c++
float x = ofGetElapsedTimef();  	// 1D noise
float noiseVal = ofNoise(x); 		// returns 0.0 - 1.0

// note: 
// you can also get "2D" or "3D" noise
// this still outputs a single float value
// but takes in multiple "coordinates" (x,y,z):

float y = ofGetElapsedTimef() + 1000;	// time offset
float noiseVal2D = ofNoise(x,y);    	// 2D noise --> returns float 0.0 - 1.0

// note 2: 
// if we need to get values from -1 to 1 (instead of 0 to 1)
// we can use ofSignedNoise():

float signedNoiseVal = ofSignedNoise(x,y); 	// returns -1.0 - 1.0
```

Under the hood, `ofNoise()` uses [Perlin noise](https://thebookofshaders.com/11/), a special noise function originally developed by Ken Perlin for CGI animation in the 1982 film _Tron_ (he won an Oscar for this algorithm!).

![Tron](https://thebookofshaders.com/11/tron.jpg)


### Oscillation: `sin()` and `cos()`

When we want to model oscillating motion, we often use the C++ sine and cosine functions:  

```c++
float sine = sin(theta);
float cosine = cos(theta);
// theta is a float in radians, which wrap around at 0 and 2*PI (0º - 360º)
```

As `theta` increases, the return values smoothly oscillate between -1.0 and 1.0.  
In the diagram below, `theta` is shown in yellow.  

![sin & cosine](https://camo.githubusercontent.com/c0d42e2cebc25083886eaa77d7618325c6db1faa/687474703a2f2f692e696d6775722e636f6d2f63427a654c4f6f2e676966)

Note that the cosine wave is just the sine wave with an offset.

## Going further:

### Angles and rotation: `atan2` (arctangent)

Recall that a vector has both a direction (**angle** of vector) and a magnitude (length of vector).  
We can calculate the **angle** of a vector using the C++ `atan2(y,x)` function.  
_Note that `atan2(y,x)` takes Y before X!_

```c++
glm::vec2 vec = glm::vec2(1,2);
float angleRadians = atan2(vec.y, vec.x);   // note that y comes before x!
float angleDegrees = ofRadToDeg(angleRadians);	// convert radians to degrees
```
![atan2 diagram](readme/atan2.jpg)

This allows us to model the angular rotation of objects, given a direction vector:

```c++
glm::vec2 vel = glm::vec2(3,2);    		// our velocity
float rotation = atan2(vel.y, vel.x);   // direction angle
ofRotateDeg(ofRadToDeg(rotation));     	// ofRotateDeg() takes angle in degrees
```




