#pragma once
#include "raymath.h"
 

struct Entity
{
	Matrix transform = MatrixIdentity();
	bool active = true;

	void _init();
	void _tick();
	void _render();
	void _destroy();

	





};

