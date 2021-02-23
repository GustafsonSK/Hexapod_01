#include "Poloha.h"
class movement
{
public:

	float krok = 30;
	int doleI = -50;
	int hore = 10;

	Poloha Ciel1;
	Poloha Ciel2;
	Poloha Ciel3;
	Poloha Ciel4;
	Poloha Ciel5;
	Poloha Ciel6;

	void move1(float X, float Z);

	void move2(float X, float Z);

	void normal();

	void dole();

	movement()
	{
		normal();
	}
};

