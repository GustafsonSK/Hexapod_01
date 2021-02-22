#include <math.h>
#include <iostream>
#include "Poloha.h"
//#include "pca9685.h"

/// BORIS JA VIEM ZE NA TO ZABUDNES TAK TI PRIPOMINAM...NA POHYB MAS FUNKCIU pohyb ///
///                             DAKUJEM, S LASKOU BORIS                            ///



using namespace std;

class noha
{
public:
	int uhol1;
	int uhol2;
	int uhol3;

	float dlzka1 = 60;
	float dlzka2 = 100;

	Poloha start;

	Poloha normalServa;

	Poloha point1;

	Poloha point2;

	Poloha ciel;

	Poloha vektor;

	Poloha nula;

	Poloha hore;

	int adresa;
	int pin;
	


	struct Poloha normal(struct Poloha Vektor)
	{
		float x = fabs(Vektor.x);
		float y = fabs(Vektor.y);

		Vektor.x /= sqrtf(x * x + y * y);
		Vektor.y /= sqrtf(x * x + y * y);

		return Vektor;
	}
	float magnitude(struct Poloha Start, struct Poloha End)
	{
		float x = fabs(End.x - Start.x);
		float y = fabs(End.y - Start.y);
		float z = fabs(End.z - Start.z);

		
		
		return sqrtf(x*x + y*y + z*z);
	}
	
	void pohyb(struct Poloha Ciel) ////// TOTO JE HLAVNE
	{
		//cout <<"OFA"<< magnitude(start,Ciel)<<endl;
		ciel = Ciel;
		Ciel.x = sqrtf(powf(magnitude(start,Ciel),2)-powf(fabs(Ciel.y-start.y),2)); ///nove X pre 2D
		Ciel.z = 0;
		point1.x = 50;
		point1.y = 70;
		point2.x = 100;
		point2.y = -50;
		int iteracia = 0;
		/// FABRIK
		while (magnitude(Ciel, point2)>0.05f && iteracia <= 20)
		{
			point1 = fabrik(point1, Ciel, dlzka2);
			point1 = fabrik(point1, nula, dlzka1);
			point2 = fabrik(Ciel, point1, dlzka2);
			iteracia++;
		}
		
		//cout << "\nChyba: " << magnitude(Ciel, point2)<<endl;
		uhly();
		
	}
	struct Poloha fabrik(struct Poloha Start, struct Poloha End, float Dlzka) /// start je hodnota ktora sa pocita
	{
		vektor.x = Start.x - End.x;
		vektor.y = Start.y - End.y;

		/// normal vektoru
		vektor = normal(vektor);

		vektor.x = (vektor.x * Dlzka) + End.x;
		vektor.y = (vektor.y * Dlzka) + End.y;

		

		return vektor;
	}
	void uhly()
	{
		uhol1 = rotacia(normalServa, start, ciel);
		uhol2 = uhol(hore,nula,point1);
		uhol3 = uhol(nula,point1,point2);
	}

	int rotacia(struct Poloha Start, struct Poloha Stred, struct Poloha End)
	{
		End.x -= Stred.x;
		End.z -= Stred.z;
		return (acosf((Start.x * End.x + Start.z * End.z) / (sqrtf(powf(Start.x, 2) + powf(Start.z, 2)) *
			sqrtf(powf(End.x, 2) + powf(End.z, 2)))) * 180 / 3.14);
	}
	int uhol(struct Poloha Start, struct Poloha Stred, struct Poloha End)
	{
		Start.x -= Stred.x;
		Start.y -= Stred.y;
		End.x -= Stred.x;
		End.y -= Stred.y;
		return (acosf((Start.x * End.x + Start.y * End.y) / (sqrtf(powf(Start.x, 2) + powf(Start.y, 2)) *
												sqrtf(powf(End.x, 2) + powf(End.y, 2))))*180/3.14);
	}
	noha();
	noha(float StartX, float StartZ, struct Poloha NormalServa, int Pin, int Adresa)
	{
		pin = pin;
		start.x = StartX;
		start.z = StartZ;
		start.y = 50;
		normalServa = NormalServa;
		hore.y = 1;

		//int servo = pca9685Setup(300, Adresa, 50);

	}



};
