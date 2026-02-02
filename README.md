ROSE\_ENGINE / RoseEngine / rose\_engine





### Philosophy

The main philosophy of Rose Engine can be summarized in a handful aphorisms, some of which borrowed from other systems like Python.

* Modular is better than monolithic.
* Simple is better than complex.
* Complex is better than complicated.
* Conventional is better than cutting edge or strange.
* Verbose and readable is better than consise and illegible.
* Errors should never pass silently.
* Changes should be seen as soon as possible.
* Systems should be pre-built.
* Assume the developer knows nothing.
* Clarity and development speed is more important than game performance.
* A grey boxed game should take no more than a couple hours.
* The developer should not have to reinvent the wheel but not be afraid to.
* Code scripting is better than visual scripting.


Rose Engine grew out of a frustration with the unintuitiveness of Unreal Engine and Godot as well as the greed of Unity. Rose Engine aims to maximize developer productivity through modular parts, immediate feedback, and advanced debugging. While also allowing the developer to edit every single aspect of the game to allow for fine-grained control and novel mechanics and creativity.




### Programming Style Guide

###### Functions


```
void myFunction(int x) 

{

...

}
```





###### Variables



int my\_variable;





###### Classes and Structs



class MyClass 

{

public:

...

private:

...

}



struct MyStruct

{

...

}



###### Enums



enum EMyEnum 

{

...

}



###### Macros



\#define MY\_MACRO ...

\#define MY\_MACRO(x) ...



###### Namespaces



namespace re\* 

{

...

}



for example: remath, reaudio, retime, reecs, regraphics.

Not sure if I'd like to organise things in namespaces or have everthing running free.



###### Comments



Use "//" comments as you wish, use them to help explain code. At the top of each file use multiline comments to describe the purpose of the file and how it contributes to the project as a whole.







### A High Level Look

Rose Engine is composed of three components:

* Engine Runtime Program
* Engine Bindings
* Game-Specific Code and files



###### Engine Runtime Program

The engine runtime program / engine runtime / ERP is a program that is running constantly in the background and provides a number of tools that are meant to increase development speed. It is theoretically possible to create a Rose Engine game without the ERP (this is the plan anyway) but it is not recommended. The ERP's features include:

* Hot reloading C++ and shader source code files from the engine bindings and the game-specific code (done through .dll/.so reloading and checking files for edits).
* Running the scene editor such that one can change the transforms of entities and create new ones.
* Running the game as a development build, allowing the dev to edit the game as it is running.
* Hot reloads .blend files whenever they change in order to create a seamless 3D modelling experince.
* Printing logs to the UI and rendering debug gizmos.
* Rapidly greyboxing levels through specialized tools.



###### Engine Bindings

The engine bindings are the main chunk of the game engine and make the engine what it is. It creates a high-level C++ interface that interacts with lower-level systems that are too verbose to be used effectively in their ordinary forms. It also includes the Rose Engine entity component system. The main loop function also runs here. Some of the feaures that will be in the engines bindings are as follows:

* Playing 2D and 3D audio
* Creating entities
* Attaching components to entities
* Manipulating and loading meshes
* AI systems
* Creating shaders (compute, surface, light, volume, postprocess, etc...)
* Editing the render pipeline of the engine itself
* High level shader functions and objects
* Charachter controllers
* Camera controllers
* Creating Cameras
* Damage and attack systems
* Held and worn item inventory systems
* Dialogue systems
* Physics systems
* Running and loading animations
* Managing animation states
* Managing entity transforms
* Creating UI elements and binding them to events
* Creating and editing lights
* Creating save files
* Running coroutines
* Creating events and callbacks??
* Doing high-level maths
* Managing scenes
* Running sensing casts

 	- Raycasts

 	- Collisions

 	- Triggers

 	- Spherecasts

* Printing logs
* Creating debug gizmos

 	- Spheres

 	- Boxes

 	- Lines

* Sensing input as well as creating and sensing input actions
* Procedural terrain generation
* Particle systems
* Veichle body
* Tilemaps
* Sprites and sprite animation
* etc...



###### Game-Specific Code and Files

* .blend and .fbx 3D models
* start.scene.h // First scene that is opened in the game
* .scene.h files // the ".scene" is just convention for scene files. All scenes must be of type "Scene" and the name for the starting scene must be "start".
* settings.h // Holds game-specific settings
* Shader files
* Scripting files
* Scenes contain Entities
* All of the shader files that make up the game's render pipline are in the game specific code for easy extensibility and manipulation.





### Game Genres

###### Third Person RPG

* Player Controller
* AI Systems
* Animations
* Level Greyboxing
* Combat Systems
* Inventory Systems

###### Turn Based Combat

###### Visual Novel

###### Racing Game

###### FPS

###### 2D Platformer

###### 2D Fighting Game

###### Rhythm Games

###### Programming Game

*Very* complex to make a DSL but might be neat.



