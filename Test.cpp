#include <iostream>
#include<math.h>
#include "noha.h"
#include "movement.h"

using namespace std;

int main()
{
	Poloha normal;
	movement Move;
	float InputX = 0;
	float InputZ = 1;	

/// Nohy	
	normal.x = 1;
	normal.z = 1;
	noha Noha1(-48, 92.5, normal,0,0x40);

	normal.x = -1;
	normal.z = 1;
	noha Noha2(48, 92.5, normal,12,0x41);

	normal.x = 0;
	normal.z = 1;
	noha Noha3(-75.3, 0, normal,4,0x40);

	normal.x = 0;
	normal.z = 1;
	noha Noha4(73.3, 0, normal,8,0x41);

	normal.x = -1;
	normal.z = 1;
	noha Noha5(-48, -92.5, normal,12,0x40);

	normal.x = 1;
	normal.z = 1;
	noha Noha6(48, -92.5, normal,0,0x41);
///
	
	
	while (true)
	{
		Move.move1(InputX, InputZ);
			Noha2.pohyb(Move.Ciel2);
			Noha3.pohyb(Move.Ciel3);
			Noha6.pohyb(Move.Ciel6);
			Noha1.pohyb(Move.Ciel1);
			Noha4.pohyb(Move.Ciel4);
			Noha5.pohyb(Move.Ciel5);
			cout << Noha1.uhol1<<endl;
			cout << Noha1.uhol2 << endl;
			cout << Noha1.uhol3 << endl;
			cout <<"1---------\n"<< endl;

		Move.dole();
			Noha2.pohyb(Move.Ciel2);
			Noha3.pohyb(Move.Ciel3);
			Noha6.pohyb(Move.Ciel6);
		Move.move2(InputX, InputZ);
		Move.move2(InputX, InputZ);
			Noha1.pohyb(Move.Ciel1);
			Noha4.pohyb(Move.Ciel4);
			Noha5.pohyb(Move.Ciel5);
			Noha2.pohyb(Move.Ciel2);
			Noha3.pohyb(Move.Ciel3);
			Noha6.pohyb(Move.Ciel6);
			cout << Noha1.uhol1 << endl;
			cout << Noha1.uhol2 << endl;
			cout << Noha1.uhol3 << endl;
			cout << "2---------\n" << endl;
		Move.dole();
			Noha1.pohyb(Move.Ciel1);
			Noha4.pohyb(Move.Ciel4);
			Noha5.pohyb(Move.Ciel5);
		Move.normal();
		Noha2.pohyb(Move.Ciel2);
		Noha3.pohyb(Move.Ciel3);
		Noha6.pohyb(Move.Ciel6);
		Noha1.pohyb(Move.Ciel1);
		Noha4.pohyb(Move.Ciel4);
		Noha5.pohyb(Move.Ciel5);
		
	}
	

	
}
