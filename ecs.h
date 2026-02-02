	#pragma once
#include "raymath.h"
#include <vector>
#include <string>


struct Entity
{

	std::string name = "Default Entity Name";
	Matrix transform = MatrixIdentity();
	bool active = true;

	void _init();
	void _tick();
	void _render();
	void _destroy();

};




struct Scene {


	std::vector<Entity> entities;

	// Creates and registers an entity as well as returns the entity's pointer
	Entity* _generate_entity(
		std::string name = "Default Entity Name",
		Matrix transform = MatrixIdentity(),
		bool active = true);





};

