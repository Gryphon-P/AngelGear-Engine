#pragma once
#include <glad/glad.h> // Note: GLAD has to be before GLFW for some reason
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <iostream>


#pragma region input macros


#define K_SPACE         GLFW_KEY_SPACE        
#define K_APOSTROPHE    GLFW_KEY_APOSTROPHE   
#define K_COMMA         GLFW_KEY_COMMA        
#define K_MINUS         GLFW_KEY_MINUS        
#define K_PERIOD        GLFW_KEY_PERIOD       
#define K_SLASH         GLFW_KEY_SLASH        
#define K_0             GLFW_KEY_0            
#define K_1             GLFW_KEY_1            
#define K_2             GLFW_KEY_2            
#define K_3             GLFW_KEY_3            
#define K_4             GLFW_KEY_4            
#define K_5             GLFW_KEY_5            
#define K_6             GLFW_KEY_6            
#define K_7             GLFW_KEY_7            
#define K_8             GLFW_KEY_8            
#define K_9             GLFW_KEY_9            
#define K_SEMICOLON     GLFW_KEY_SEMICOLON    
#define K_EQUAL         GLFW_KEY_EQUAL        
#define K_A             GLFW_KEY_A            
#define K_B             GLFW_KEY_B            
#define K_C             GLFW_KEY_C            
#define K_D             GLFW_KEY_D            
#define K_E             GLFW_KEY_E            
#define K_F             GLFW_KEY_F            
#define K_G             GLFW_KEY_G            
#define K_H             GLFW_KEY_H            
#define K_I             GLFW_KEY_I            
#define K_J             GLFW_KEY_J            
#define K_K             GLFW_KEY_K            
#define K_L             GLFW_KEY_L            
#define K_M             GLFW_KEY_M            
#define K_N             GLFW_KEY_N            
#define K_O             GLFW_KEY_O            
#define K_P             GLFW_KEY_P            
#define K_Q             GLFW_KEY_Q            
#define K_R             GLFW_KEY_R            
#define K_S             GLFW_KEY_S            
#define K_T             GLFW_KEY_T            
#define K_U             GLFW_KEY_U            
#define K_V             GLFW_KEY_V            
#define K_W             GLFW_KEY_W            
#define K_X             GLFW_KEY_X            
#define K_Y             GLFW_KEY_Y            
#define K_Z             GLFW_KEY_Z            
#define K_LEFT_BRACKET  GLFW_KEY_LEFT_BRACKET 
#define K_BACKSLASH     GLFW_KEY_BACKSLASH    
#define K_RIGHT_BRACKET GLFW_KEY_RIGHT_BRACKET
#define K_GRAVE_ACCENT  GLFW_KEY_GRAVE_ACCENT 
#define K_WORLD_1       GLFW_KEY_WORLD_1      
#define K_WORLD_2       GLFW_KEY_WORLD_2      
#define K_ESCAPE        GLFW_KEY_ESCAPE       
#define K_ENTER         GLFW_KEY_ENTER        
#define K_TAB           GLFW_KEY_TAB          
#define K_BACKSPACE     GLFW_KEY_BACKSPACE    
#define K_INSERT        GLFW_KEY_INSERT       
#define K_DELETE        GLFW_KEY_DELETE       
#define K_RIGHT         GLFW_KEY_RIGHT        
#define K_LEFT          GLFW_KEY_LEFT         
#define K_DOWN          GLFW_KEY_DOWN         
#define K_UP            GLFW_KEY_UP           
#define K_PAGE_UP       GLFW_KEY_PAGE_UP      
#define K_PAGE_DOWN     GLFW_KEY_PAGE_DOWN    
#define K_HOME          GLFW_KEY_HOME         
#define K_END           GLFW_KEY_END          
#define K_CAPS_LOCK     GLFW_KEY_CAPS_LOCK    
#define K_SCROLL_LOCK   GLFW_KEY_SCROLL_LOCK  
#define K_NUM_LOCK      GLFW_KEY_NUM_LOCK     
#define K_PRINT_SCREEN  GLFW_KEY_PRINT_SCREEN 
#define K_PAUSE         GLFW_KEY_PAUSE        
#define K_F1            GLFW_KEY_F1           
#define K_F2            GLFW_KEY_F2           
#define K_F3            GLFW_KEY_F3           
#define K_F4            GLFW_KEY_F4           
#define K_F5            GLFW_KEY_F5           
#define K_F6            GLFW_KEY_F6           
#define K_F7            GLFW_KEY_F7           
#define K_F8            GLFW_KEY_F8           
#define K_F9            GLFW_KEY_F9           
#define K_F10           GLFW_KEY_F10          
#define K_F11           GLFW_KEY_F11          
#define K_F12           GLFW_KEY_F12          
#define K_F13           GLFW_KEY_F13          
#define K_F14           GLFW_KEY_F14          
#define K_F15           GLFW_KEY_F15          
#define K_F16           GLFW_KEY_F16          
#define K_F17           GLFW_KEY_F17          
#define K_F18           GLFW_KEY_F18          
#define K_F19           GLFW_KEY_F19          
#define K_F20           GLFW_KEY_F20          
#define K_F21           GLFW_KEY_F21          
#define K_F22           GLFW_KEY_F22          
#define K_F23           GLFW_KEY_F23          
#define K_F24           GLFW_KEY_F24          
#define K_F25           GLFW_KEY_F25          
#define K_KP_0          GLFW_KEY_KP_0         
#define K_KP_1          GLFW_KEY_KP_1         
#define K_KP_2          GLFW_KEY_KP_2         
#define K_KP_3          GLFW_KEY_KP_3         
#define K_KP_4          GLFW_KEY_KP_4         
#define K_KP_5          GLFW_KEY_KP_5         
#define K_KP_6          GLFW_KEY_KP_6         
#define K_KP_7          GLFW_KEY_KP_7         
#define K_KP_8          GLFW_KEY_KP_8         
#define K_KP_9          GLFW_KEY_KP_9         
#define K_KP_DECIMAL    GLFW_KEY_KP_DECIMAL   
#define K_KP_DIVIDE     GLFW_KEY_KP_DIVIDE    
#define K_KP_MULTIPLY   GLFW_KEY_KP_MULTIPLY  
#define K_KP_SUBTRACT   GLFW_KEY_KP_SUBTRACT  
#define K_KP_ADD        GLFW_KEY_KP_ADD       
#define K_KP_ENTER      GLFW_KEY_KP_ENTER     
#define K_KP_EQUAL      GLFW_KEY_KP_EQUAL     
#define K_LEFT_SHIFT    GLFW_KEY_LEFT_SHIFT   
#define K_LEFT_CONTROL  GLFW_KEY_LEFT_CONTROL 
#define K_LEFT_ALT      GLFW_KEY_LEFT_ALT     
#define K_LEFT_SUPER    GLFW_KEY_LEFT_SUPER   
#define K_RIGHT_SHIFT   GLFW_KEY_RIGHT_SHIFT  
#define K_RIGHT_CONTROL GLFW_KEY_RIGHT_CONTROL
#define K_RIGHT_ALT     GLFW_KEY_RIGHT_ALT    
#define K_RIGHT_SUPER   GLFW_KEY_RIGHT_SUPER  
#define K_MENU          GLFW_KEY_MENU         

#pragma endregion

inline bool is_key_pressed(GLFWwindow* window, int key) {
	if (glfwGetKey(window, key) == GLFW_PRESS) {
		return true;
	}
	else {
		return false;
	}
}