#pragma once

#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <filesystem>
#include <system_error>


// Defines a shader
struct Shader {
	
	// Constructor builds the shader from the filepaths
	Shader(const char* vertex_path_, const char* fragment_path_);

	// Builds the shader, constructor calls this
	void init(const char* vertex_path_, const char* fragment_path_);

	// Shader ID
	unsigned int ID;

	// Shader file directories
	const char* vertex_path;
	const char* fragment_path;

	// Last times files were modified
	// (std::filesystem reqires C++17 or higher)
	std::filesystem::file_time_type vertex_time_last_saved;
	std::filesystem::file_time_type fragment_time_last_saved;

	// Checks for errors
	static void checkShaderForErrors(unsigned int& shader);
	static void checkShaderProgramForErrors(unsigned int& program);

	// Hot reloads the shaders if they change, to be called once every frame or every few frames
	void hotReload();

	// Use the shader
	void use();
	
	void setBool(const std::string& name, bool x) const;
	void setInt(const std::string& name, int x) const;
	void setFloat(const std::string& name, float x) const;



};
