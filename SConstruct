"""
SCons file for creating various rose_engine builds.
https://scons.org/doc/production/PDF/scons-user.pdf
Build type types:
    - Hot reloading
    - Scene editor
    - Simple build (also to be used for release)
"""

import sys
import subprocess

# Creates the SCons env
env = Environment(tools=['default', 'msvc'])
# To link together all compiled DLLs: env.Program(target='program', source=['main.c'], LIBS=dll_targets, LIBPATH=['.'])
# A build system may be unnecacary due to cr.h or at the very least could be slimmed down drasticlly due to it not having to handle
# hot reloading logic.


STANDARD_BUILD_KEYWORDS = ["standard", "st", "std"]
HOT_RELOAD_BUILD_KEYWORDS = ["hot-reload", "hr"]
SCENE_EDITOR_BUILD_KEYWORDS = ["scene-editor", "se"]



# Gets the type of build we will be doing
build_type_keyword = ARGUMENTS.get("bt", "standard")
if (build_type_keyword in STANDARD_BUILD_KEYWORDS):
    """
    STANDARD BUILD
    """
    print("Starting Build...\n\n")


    # Sets the platform #define flags for each platform
    if sys.platform == "linux" or sys.platform == "linux2":
        env.Append(CPPDEFINES = ['GLFW_BUILD_LINUX_JOYSTICK'])
    elif sys.platform == "win32":
        env.Append(CPPDEFINES = ['_GLFW_WIN32'])
        
    


    env.Library('./libs/glfw3', Glob('./GLFW/*.c'))
    env.Library('./libs/glad', ['./includes/glad.c'])

    subprocess.call(['g++', './test_game/main.cpp', '-L', 'libs', '-I' 'includes', '-lglfw3', '-lglad', '-lopengl32'])
    
    # env.Program('test_game/main.cpp', LIBS=['glad', 'glfw3', 'gdi32'], LIBPATH='./libs')




elif (build_type_keyword in HOT_RELOAD_BUILD_KEYWORDS):
    """
    HOT RELOAD BUILD
    """
    print("Starting Hot Reloading...\n\n")

elif (build_type_keyword in SCENE_EDITOR_BUILD_KEYWORDS):
    """
    SCENE EDITOR BUILD
    """
    print("Starting Scene Editor...\n\n")
else:
    raise Exception(
    "\nInvalid build type keyword. Valid build keywords are: \n" \
    "Build Project: 'standard' / 'st' / 'std'\n" \
    "Start Hot Reloading: 'hot-reload' / 'hr'\n" \
    "Open Scene Ediotor: 'scene-editor' / 'se'\n\n" \
    "Example: scons bt=hot-reload"
    )






