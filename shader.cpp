#include "shader.h"


// Constructor builds the shader from the filepaths
Shader::Shader(const char* vertex_path_, const char* fragment_path_)
{
	init(vertex_path_, fragment_path_);
}

void Shader::init(const char* vertex_path_, const char* fragment_path_)
{

	// Saves the path names for later
	vertex_path = vertex_path_;
	fragment_path = fragment_path_;

	// --- READING THE SHADER FILES ---

	// Strings that will hold the shader file data
	std::string vertex_source_string;
	std::string fragment_source_string;

	// File handlers for each shader
	std::ifstream vertex_filehandler;
	std::ifstream fragment_filehandler;

	// Ensures that the filehandlers can throw errors
	vertex_filehandler.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	fragment_filehandler.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	// Opens and reads the shader files
	try {

		// Opens the files
		vertex_filehandler.open(vertex_path_);
		fragment_filehandler.open(fragment_path_);

		// Creates string streams
		std::stringstream vertex_string_stream;
		std::stringstream fragment_string_stream;

		// Reads the file contents into the string streams
		vertex_string_stream << vertex_filehandler.rdbuf();
		fragment_string_stream << fragment_filehandler.rdbuf();

		// Closes the filehandlers
		vertex_filehandler.close();
		fragment_filehandler.close();

		// Convert to string
		vertex_source_string = vertex_string_stream.str();
		fragment_source_string = fragment_string_stream.str();
	}
	catch (std::ifstream::failure e)
	{
		std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
	}

	// Converts to C strings
	const char* vertex_code = vertex_source_string.c_str();
	const char* fragment_code = fragment_source_string.c_str();


	// --- COMPILING THE SHADERS ---

	unsigned int vertex;
	unsigned int fragment;
	int success;
	char info_log[512];

	// Compiles the vertex shader
	vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex, 1, &vertex_code, NULL);
	glCompileShader(vertex);
	checkShaderForErrors(vertex);

	// Compiles the fragment shader
	fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment, 1, &fragment_code, NULL);
	glCompileShader(fragment);
	checkShaderForErrors(fragment);

	// Links the shader program
	ID = glCreateProgram();
	glAttachShader(ID, vertex);
	glAttachShader(ID, fragment);
	glLinkProgram(ID);
	checkShaderProgramForErrors(ID);

	// Deletes the shaders
	glDeleteShader(vertex);
	glDeleteShader(fragment);

}

void Shader::checkShaderForErrors(unsigned int& shader)
{
	int  success;
	char infoLog[512];
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		glGetShaderInfoLog(shader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::COMPILATION_FAILED\n" << infoLog << std::endl;
	}
}

void Shader::checkShaderProgramForErrors(unsigned int& program)
{
	int  success;
	char infoLog[512];
	glGetProgramiv(program, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(program, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::COMPILATION_FAILED\n" << infoLog << std::endl;
	}
}

void Shader::hotReload()
{
	std::filesystem::path vertex_filesystem_path = std::filesystem::path(vertex_path);
	std::filesystem::path fragment_filesystem_path = std::filesystem::path(fragment_path);

	// Checks if the files have changed
	if (
		std::filesystem::last_write_time(vertex_filesystem_path) != vertex_time_last_saved
		|| 
		std::filesystem::last_write_time(fragment_filesystem_path) != fragment_time_last_saved
	) 
	{
		// Recompiles the shader
		init(vertex_path, fragment_path);
		use();

		// Reassigns the last saved time
		vertex_time_last_saved = std::filesystem::last_write_time(vertex_filesystem_path);
		fragment_time_last_saved = std::filesystem::last_write_time(fragment_filesystem_path);
	}



}

void Shader::use()
{
	glUseProgram(ID);
}

void Shader::setBool(const std::string& name, bool x) const
{
	glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)x);
}

void Shader::setInt(const std::string& name, int x) const
{
	glUniform1i(glGetUniformLocation(ID, name.c_str()), x);
}

void Shader::setFloat(const std::string& name, float x) const
{
	glUniform1f(glGetUniformLocation(ID, name.c_str()), x);
}
