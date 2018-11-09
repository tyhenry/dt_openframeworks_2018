# Week 11 - 3D Meshes, ofNode, ofParameter, ofxGui

# Apps

 - **01_plane_mesh_gui** - build a 3D plane (a grid mesh) modified by noise waves
    - uses ofxGui addon (+ ofParameter) to generate noise waves

# Review

# Meshes

A `mesh` is a 3D surface made of triangles `▲▼▲▼▲` ( which form polygons `▢ = ◤◢` )

ofMesh has 2 vectors for drawing points and triangles:

- `vector<glm::vec3> vertices    // 3D points`

- `vector<int> indices           // triangle connections` 

```
  indices are the vertex indices that form triangles
	      b
	    ◢			i.e. index = a, vertices[a]
	  a   c

	         A-------B          A-------B        B
             |     / |          |     /        / |
             |   /   |    =>    |   /   +    /   |
             | /     |          | /        /     |
             C-------D          C        C-------D

	grouped in threes - a,b,c - clockwise:
	e.g: 0,1,2... 3,4,5... etc  ==> [0,1,2,3,4,5...]
```


# & references

'&' is a special symbol used when declaring variables
it means they reference another variable directly.  they act like a temporary nickname:

```
float& boxSize = box.getSize();		// returns float&
boxSize += 3;						// box.size += 3
```



     
