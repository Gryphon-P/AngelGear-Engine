#pragma once
#include <glad/glad.h> // Note: GLAD has to be before GLFW for some reason
#include <GLFW/glfw3.h>

struct Time
{

	static double time;
	static double delta_time;
	static double frame_start_time;

	static inline void init() {
		time = glfwGetTime();
	}

	static inline void update() {
		time = glfwGetTime();
	}

	static inline void recordFrameStart() {
		frame_start_time = glfwGetTime();
	}

	static inline void recordFrameEnd() {
		delta_time = glfwGetTime() - frame_start_time;
	}



};