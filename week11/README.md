# Week 11 - 3D and GUIs (ofMesh, ofNode + ofxGui, ofParameter)

## Homework

Work on a sketch of your choosing.  You could:

 - Rework an old project from your homework repo into a 3D scene
 - Prototype an idea or technique you might want to use for your final
 - Try out an [ofxAddon](https://www.ofxaddons.com)

- **For more information on 3D meshes (apart from the example projects):**
  **Read the ["Generating Meshes from Image"](http://openframeworks.cc/ofBook/chapters/generativemesh.html)** chapter of ofBook
    - this will review 3D meshes and introduces image sampling

# Apps

 - **01_plane_mesh_gui** - build a 3D plane (a grid mesh) modified by noise waves
    - uses ofxGui addon (+ ofParameter) to generate noise waves
 - **02_3d_basics** - draw a simple triangle from 3 points, and a sphere
 - **03_volcano_particles** - 3D particle system, volcano mesh and 3D lighting

# Review

# Meshes

A `mesh` is a 3D surface made of triangles `▲▼▲▼▲` ( which form polygons `◤◢ => ▢` )

ofMesh has 2 vectors for drawing points and triangles:

- `vector<glm::vec3> vertices    // 3D points`

- `vector<int> indices           // triangle connections` 

```
  indices are the vertices that form triangles -

  	e.g. triangle a,b,c  =>  vertices[a],vertices[b],vertices[c]

  	to make a mesh grid:

		1 rectangle   =>        2 triangles

         A-------B          A-------B        B
         |     / |          |     /        / |
         |   /   |    =>    |   /   +    /   |
         | /     |          | /        /     |
         C-------D          C        C-------D

	indices are grouped in threes - a,b,c - clockwise:
	e.g: 0,1,2... 3,4,5... etc  ==> [0,1,2,3,4,5...]


```


# & references

'&' is a special symbol used when declaring variables
it means they reference another variable directly.  they act like a temporary nickname:

```
float& boxSize = box.getSize();		// returns float&
boxSize += 3;						// box.size += 3
```



     
