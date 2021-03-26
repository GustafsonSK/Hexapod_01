#include <iostream>
#include<math.h>
#include "noha.h"
#include "movement.cpp"
#include "pca9685.h"
#include <wiringPi.h>
#include <vector>


using namespace std;

int map(int x, int mapMIN, int mapMAX) //Premapovanie pred pouzitim
	{
	return (x - 0) * (mapMAX - mapMIN) / (180 - 0) + mapMIN;
	}

int main()
{
	Poloha normal;
	float InputX = 0;
	float InputZ = 1;	
	
	wiringPiSetup(); // Aktivacia GPIO
	
	int servo = pca9685Setup(300, 0x40, 50);
		pca9685PWMReset(servo);
		
	int servo2 = pca9685Setup(400, 0x41, 50);
		pca9685PWMReset(servo2);
		
		

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
	// Kontajner na nohy
	vector <noha> noha;

	noha.push_back(Noha1);
	noha.push_back(Noha2);
	noha.push_back(Noha3);
	noha.push_back(Noha4);
	noha.push_back(Noha5);
	noha.push_back(Noha6);

	
	
		
	}
	

	
}
