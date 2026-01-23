ROSE_ENGINE / RoseEngine / rose_engine

ROSE_ENGINE is a custom game engine being created by Gryphon Picciottoli.
My intent with this project is to make a small game engine that aligns with my philosophies
in addition to allowing me greater creative freedom. If the goals of this project will change in the future, 
I am not sure. I will not be using MSVS to increase interoperability and give me greater understanding of the low-level systems at play.

The end goal is to create a git submodule such that it can be cloned and every file in the game can just do
#include "rose_engine.h". The entire engine is meant to be portable, you just clone and go, 
no downloading other programs other than say, GCC and the Python Interpreter.

PROJECT ORGANIZATION (folders):
- includes: C and C++ includes for stuff like GLFW and GLAD
    - Boost?
    - Bullet Physics?
    - Assimp
    - GLFW
    - GLAD
- imports: Same as includes but for Python 
- src: Source code for the engine, stuff I will be working on
    - rose_engine: defines the main interface with the game project and ties the entire engine together
    - ecs: Entity component system, holds the structs for all the components and the entity class
    - rendering: Includes all the structs and methods for rendering
    - input: Includes all the data for getting user input with advanced input structures
- automation_scripts: python scripts that run automated tasks and can make development easier
- test_game: test project to run the engine

Repos suggested to me:
    - https://github.com/KhronosGroup/MoltenVK
    - https://developer.mozilla.org/en-US/docs/Web/API/WebGPU_API
    - https://github.com/SanderMertens/flecs
    - https://github.com/thisistherk/fast_obj
    - https://github.com/jkuhlmann/cgltf
    - https://github.com/nothings/stb/tree/master
    - https://savas.ca/nomad


Intresting Build System: https://scons.org/

It's been suggested that I use Clang instead of GCC but SCons may abstact things so such things may be redundant.

Live Updating AngelScript and GLSL files:
https://stackoverflow.com/questions/15478046/how-to-find-out-if-a-file-was-modified#:~:text=std%3A%3Atime%5Ft%20last%5Fwrite%5Ftime%28const%20path%26%29%2E

The engine will have a debug and a release mode.
Debug mode the follwing features will be avalable:
    - imgui menu menu pulled up with " ` " (https://github.com/ocornut/imgui) the menu will have the following options:
        - Edit light color (vec3)
        - Edit light type (enum)
        - Edit light brightness (float)
        - Show collision meshes (bool)
        - Show cast lines (bool)
    - Hot reload AngelScript files on file change detected (.as)
    - Hot reload shaders on file change detected (.glsl) ()
    - Detach/attach Camera with "F1"
        - Edit entity transforms
            - G - Move
            - R - Rotate
            - S - Scale
            - X/Y/Z - Edit transform in dimention
            - Shift+(X/Y/Z) - Edit transform in other dimentions
            - F - Focus on object
            - LCLK+(W/A/S/D) - First person move
            - RCLK - Select entity
            - MCLK+Move Mouse - rotate around object
            - MCLK+Shift+Move Mouse - Pan Camera
                
    - ESC applies all changes to the source code

    
