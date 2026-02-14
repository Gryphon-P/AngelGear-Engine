#pragma once

#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

// Defines a shader
struct Shader {

	// Shader ID
	unsigned int ID;

	// Checks for errors
	static void checkShaderForErrors(unsigned int& shader);
	static void checkShaderProgramForErrors(unsigned int& program);

	// Constructor builds the shader from the filepaths
	Shader(const char* vertex_path, const char* fragment_path);

	// Use the shader
	void use();
	
	void setBool(const std::string& name, bool x) const;
	void setInt(const std::string& name, int x) const;
	void setFloat(const std::string& name, float x) const;



};
