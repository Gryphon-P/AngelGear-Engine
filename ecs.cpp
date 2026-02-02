#include "ecs.h"

Entity* Scene::_generate_entity(std::string name, Matrix transform, bool active)
{
	// Creates entity
	Entity working_entity;
	working_entity.name = name;
	working_entity.transform = transform;
	working_entity.active = active;

	// Registers entity in scene
	entities.push_back(working_entity);

	// Returns ptr
	return &working_entity;
}
