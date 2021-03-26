#include "Poloha.h"
#include <vector>
class movement
{
public:

	float krok = 30;
	int doleI = -50;
	int hore = 10;

	Poloha Ciel;
	static vector <Poloha> ciel;


	void move1(float X, float Z);

	void move2(float X, float Z);

	void normal();

	void dole();

	movement()
	{
		ciel.push_back(Ciel);
		ciel.push_back(Ciel);
		ciel.push_back(Ciel);
		ciel.push_back(Ciel);
		ciel.push_back(Ciel);
		ciel.push_back(Ciel);
		normal();
	}
};

