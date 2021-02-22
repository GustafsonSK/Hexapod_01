#include "movement.h"



void movement::move1(float X, float Z)
{
	Ciel1.x -= X * krok;
	Ciel1.z -= Z * krok;
	Ciel1.y = 0;

	Ciel2.x += X * krok;
	Ciel2.z += Z * krok;
	Ciel2.y = 10;

	Ciel3.x += X * krok;
	Ciel3.z += Z * krok;
	Ciel3.y = 10;

	Ciel4.x -= X * krok;
	Ciel4.z -= Z * krok;
	Ciel4.y = 0;

	Ciel5.x -= X * krok;
	Ciel5.z -= Z * krok;
	Ciel5.y = 0;

	Ciel6.x += X * krok;
	Ciel6.z += Z * krok;
	Ciel6.y = 10;

}

void movement::move2(float X, float Z)
{
	Ciel1.x += X * krok;
	Ciel1.z += Z * krok;
	Ciel1.y = 10;

	Ciel2.x -= X * krok;
	Ciel2.z -= Z * krok;
	Ciel2.y = 0;

	Ciel3.x -= X * krok;
	Ciel3.z -= Z * krok;
	Ciel3.y = 0;

	Ciel4.x += X * krok;
	Ciel4.z += Z * krok;
	Ciel4.y = 10;

	Ciel5.x += X * krok;
	Ciel5.z += Z * krok;
	Ciel5.y = 10;

	Ciel6.x -= X * krok;
	Ciel6.z -= Z * krok;
	Ciel6.y = 0;

};

void movement::normal()
{
	Ciel1.x = -111.64;
	Ciel1.z = 156.14;
	Ciel1.y = 0;

	Ciel2.x = 111.64;
	Ciel2.z = 156.14;
	Ciel2.y = 0;

	Ciel3.x = -165.3;
	Ciel3.z = 0;
	Ciel3.y = 0;

	Ciel4.x = 165.3;
	Ciel4.z = 0;
	Ciel4.y = 0;

	Ciel5.x = -111.64;
	Ciel5.z = -156.14;
	Ciel5.y = 0;

	Ciel6.x = 111.64;
	Ciel6.z = -156.14;
	Ciel6.y = 0;
};

void movement::dole()
{
	Ciel1.y = 0;
	Ciel2.y = 0;
	Ciel3.y = 0;
	Ciel4.y = 0;
	Ciel5.y = 0;
	Ciel6.y = 0;
};