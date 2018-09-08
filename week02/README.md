# Week 2



## Apps

 - **Bouncing Square** make a Square class
 - **Bouncing Squares** make an array of Square objects
 - **Shapes** draw some simple stuff, use colors

## Homework

**Read:**
 - [OOPs!](http://openframeworks.cc/ofBook/chapters/OOPs!.html) << a deeper explanation of what we did in class

**Skim:**
 - [How OF Works](http://openframeworks.cc/ofBook/chapters/how_of_works.html)
 - [Graphics](http://openframeworks.cc/ofBook/chapters/intro_to_graphics.html)

**Sketches:**

1.	Create a simple animation using a class of your own design.  You can use the Square class as a template for your code.  
	Play with color, shape, size, movement, speed, etc.  
	  	- the class you write should contain both an update() and a draw() function  
		- try to use an array

2.  Try to make an interactive app, using mouse movement or keyboard presses.  Don't worry if you get stuck, just go as far as you can.

3.  _Extra_ Check out the examples in the 'examples' folder inside the openFrameworks directory.  

## Review from Class

### Object Oriented Programming:

 - we use **classes** to represent _types_ of things, "encapsulated" into neat packages
 - **objects** are the actual things themselves, "instances" of the class
 - classes can **inherit** from each other (we haven't seen this yet, but will cover it later)
 - we **declare** the class's functions and variables with a header (**.h** or .hpp) file - this is like a table of contents
 - we **define** the class functions and **initialize** its variables inside a **.cpp** file

### Fundamental C++

 - basic built-in types:
 	- **int**:  "integers" represent a whole number like 0, 1, 2, 3, 884675, -2075, etc.
 	- **float**:  "floats" represent numbers with decimal points like 1.0, 1.1, 1974239.08236, -300.75, etc.
 	- **bool**:  a "boolean" value can be either **true** or **false**  

 	```c++
 	int i 	= -100;
 	float f = 12345.6789;
    bool b 	= true;
 	```

 - _for_ loops run code a set number of times

	```c++
   	for (int i=0; i<10; i++) { 
   		// this will run 10 times
   	}
	```

 - _while_ loops run code until a condition is false

 	```c++
    bool runLoop = true;
 	while (runLoop){
 		// we need to set runLoop false to exit loop
 		// otherwise, we create an "infinite loop"
        runLoop = false;
 	}
 	```

 - _functions_ are blocks of code that can be _called_ later on to run
 	- functions can take _arguments_ (also called _parameters_) as input -  
 		these are values you supply the function when you _call_ it
 	- functions can also _return_ values (or not - its up to you)

 	```c++
    // examples:
    
 	// return an integer
 	int add2Plus2(){
 		return 2 + 2;
 	}
    // use parameters
    int add(int first, int second){
    	return first + second;
    }
    // return nothing
    void emptyFunction(){
    	// this function does nothing
    }
    
 	// call the functions
    int result1 = add2Plus2();
    int result2 = add(2,2);
    emptyFunction();
 	```

- we can print text to the "console" like this:  
	```c++
    cout << "hello world" << endl;
    ```
	 - we can print text ("strings") or numbers like _ints_ and _floats_ 
	 - always start with `cout << ` then the message.  
	 - ` << endl;` adds a new line at the end.  this is optional but keeps your console log legible.