#include "movement.h"
#include <vector>


void movement::move1(float X, float Z)
{
	ciel[0].x -= X * krok;
	ciel[0].z -= Z * krok;
	ciel[0].y = doleI;

	ciel[1].x += X * krok;
	ciel[1].z += Z * krok;
	ciel[1].y = hore;

	ciel[2].x += X * krok;
	ciel[2].z += Z * krok;
	ciel[2].y = hore;

	ciel[3].x -= X * krok;
	ciel[3].z -= Z * krok;
	ciel[3].y = doleI;

	ciel[4].x -= X * krok;
	ciel[4].z -= Z * krok;
	ciel[4].y = doleI;

	ciel[5].x += X * krok;
	ciel[5].z += Z * krok;
	ciel[5].y = hore;

};

void movement::move2(float X, float Z)
{
	ciel[0].x += X * krok;
	ciel[0].z += Z * krok;
	ciel[0].y = hore;

	ciel[1].x -= X * krok;
	ciel[1].z -= Z * krok;
	ciel[1].y = doleI;

	ciel[2].x -= X * krok;
	ciel[2].z -= Z * krok;
	ciel[2].y = doleI;

	ciel[3].x += X * krok;
	ciel[3].z += Z * krok;
	ciel[3].y = hore;

	ciel[4].x += X * krok;
	ciel[4].z += Z * krok;
	ciel[4].y = hore;

	ciel[5].x -= X * krok;
	ciel[5].z -= Z * krok;
	ciel[5].y = doleI;

};

void movement::normal()
{
	ciel[0].x = -111.64;
	ciel[0].z = 156.14;
	ciel[0].y = doleI;

	ciel[1].x = 111.64;
	ciel[1].z = 156.14;
	ciel[1].y = doleI;

	ciel[2].x = -165.3;
	ciel[2].z = 0;
	ciel[2].y = doleI;

	ciel[3].x = 165.3;
	ciel[3].z = 0;
	ciel[3].y = doleI;

	ciel[4].x = -111.64;
	ciel[4].z = -156.14;
	ciel[4].y = doleI;

	ciel[5].x = 111.64;
	ciel[5].z = -156.14;
	ciel[5].y = doleI;
};

void movement::dole()
{
	ciel[0].y = doleI;
	ciel[1].y = doleI;
	ciel[2].y = doleI;
	ciel[3].y = doleI;
	ciel[4].y = doleI;
	ciel[5].y = doleI;
};
