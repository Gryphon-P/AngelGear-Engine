#pragma once
#include <string>
#include <vector>

#define RENDER_SHADOWS false
#define RENDER_PBR false
#define RENDER_DEPTH_BUFFER false
#define RENDER_NORMALS false
#define OPEN_SCENE_EDITOR false
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define LOOP_TIME false
	#if LOOP_TIME
	#define LOOP_TIME_START // 3.f
	#define LOOP_TIME END // 9.f
	#endif // LOOP_TIME
static const std::vector<std::string> SHADER_STACK = {
	//"vertex_shader.glsl",
	//"fragment_shader.glsl"
};


