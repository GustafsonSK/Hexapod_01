#include <iostream>
#include<math.h>
#include "noha.h"
#include "movement.cpp"
#include "pca9685.h"
#include <wiringPi.h>


using namespace std;

int map(int x, int mapMIN, int mapMAX) //Premapovanie pred pouzitim
	{
	return (x - 0) * (mapMAX - mapMIN) / (180 - 0) + mapMIN;
	}

int main()
{
	Poloha normal;
	movement Move;
	float InputX = 0;
	float InputZ = 1;	
	
	wiringPiSetup(); // Aktivacia GPIO
	
	int servo = pca9685Setup(300, 0x40, 50);
		pca9685PWMReset(servo);
		
	int servo2 = pca9685Setup(400, 0x41, 50);
		pca9685PWMReset(servo2);
	pwmWrite(304,380);

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
	
	for(int i = 0; i<10;i++)
	{
		cout<<i<<endl;
		delay(500);
	}
	while (true)
	{
		
		Move.normal();
		Noha2.pohyb(Move.Ciel2);
		Noha3.pohyb(Move.Ciel3);
		Noha6.pohyb(Move.Ciel6);
		Noha1.pohyb(Move.Ciel1);
		Noha4.pohyb(Move.Ciel4);
		Noha5.pohyb(Move.Ciel5);
		
		
			pwmWrite(300+Noha1.pin,map(Noha1.uhol1,500,120));
			pwmWrite(300+Noha1.pin+1,map(Noha1.uhol2,500,120));
			pwmWrite(300+Noha1.pin+2,map(Noha1.uhol3,500,120));
			delay(10);
			pwmWrite(300+Noha3.pin,map(Noha3.uhol1,500,120));
			pwmWrite(300+Noha3.pin+1,map(Noha3.uhol2,500,120));
			pwmWrite(300+Noha3.pin+2,map(Noha3.uhol3,500,120));
			delay(10);
			pwmWrite(300+Noha5.pin,map(Noha5.uhol1,500,120));
			pwmWrite(300+Noha5.pin+1,map(Noha5.uhol2,500,120));
			pwmWrite(300+Noha5.pin+2,map(Noha5.uhol3,500,120));
			delay(10);
			pwmWrite(400+Noha2.pin,map(Noha2.uhol1,120,500));
			pwmWrite(400+Noha2.pin+1,map(Noha2.uhol2,120,500));
			pwmWrite(400+Noha2.pin+2,map(Noha2.uhol3,120,500));
			delay(10);
			pwmWrite(400+Noha4.pin,map(Noha4.uhol1,120,500));
			pwmWrite(400+Noha4.pin+1,map(Noha4.uhol2,120,500));
			pwmWrite(400+Noha4.pin+2,map(Noha4.uhol3,120,500));
			delay(10);
			pwmWrite(400+Noha6.pin,map(Noha6.uhol1,120,500));
			pwmWrite(400+Noha6.pin+1,map(Noha6.uhol2,120,500));
			pwmWrite(400+Noha6.pin+2,map(Noha6.uhol3,120,500));
			
			cout<<"normal"<<endl;
			delay(500);
			
		Move.move1(InputX, InputZ);
			Noha2.pohyb(Move.Ciel2);
			Noha3.pohyb(Move.Ciel3);
			Noha6.pohyb(Move.Ciel6);
			Noha1.pohyb(Move.Ciel1);
			Noha4.pohyb(Move.Ciel4);
			Noha5.pohyb(Move.Ciel5);
			pwmWrite(300+Noha1.pin,map(Noha1.uhol1,500,120));
			pwmWrite(300+Noha1.pin+1,map(Noha1.uhol2,500,120));
			pwmWrite(300+Noha1.pin+2,map(Noha1.uhol3,500,120));
			delay(10);
			pwmWrite(300+Noha3.pin,map(Noha3.uhol1,500,120));
			pwmWrite(300+Noha3.pin+1,map(Noha3.uhol2,500,120));
			pwmWrite(300+Noha3.pin+2,map(Noha3.uhol3,500,120));
			delay(10);
			pwmWrite(300+Noha5.pin,map(Noha5.uhol1,500,120));
			pwmWrite(300+Noha5.pin+1,map(Noha5.uhol2,500,120));
			pwmWrite(300+Noha5.pin+2,map(Noha5.uhol3,500,120));
			delay(10);
			pwmWrite(400+Noha2.pin,map(Noha2.uhol1,120,500));
			pwmWrite(400+Noha2.pin+1,map(Noha2.uhol2,120,500));
			pwmWrite(400+Noha2.pin+2,map(Noha2.uhol3,120,500));
			delay(10);
			pwmWrite(400+Noha4.pin,map(Noha4.uhol1,120,500));
			pwmWrite(400+Noha4.pin+1,map(Noha4.uhol2,120,500));
			pwmWrite(400+Noha4.pin+2,map(Noha4.uhol3,120,500));
			delay(10);
			pwmWrite(400+Noha6.pin,map(Noha6.uhol1,120,500));
			pwmWrite(400+Noha6.pin+1,map(Noha6.uhol2,120,500));
			pwmWrite(400+Noha6.pin+2,map(Noha6.uhol3,120,500));
			cout<<"move1"<<endl;
			delay(500);
	
		Move.dole();
			Noha2.pohyb(Move.Ciel2);
			Noha3.pohyb(Move.Ciel3);
			Noha6.pohyb(Move.Ciel6);
			pwmWrite(300+Noha1.pin,map(Noha1.uhol1,500,120));
			pwmWrite(300+Noha1.pin+1,map(Noha1.uhol2,500,120));
			pwmWrite(300+Noha1.pin+2,map(Noha1.uhol3,500,120));
			delay(10);
			pwmWrite(300+Noha3.pin,map(Noha3.uhol1,500,120));
			pwmWrite(300+Noha3.pin+1,map(Noha3.uhol2,500,120));
			pwmWrite(300+Noha3.pin+2,map(Noha3.uhol3,500,120));
			delay(10);
			pwmWrite(300+Noha5.pin,map(Noha5.uhol1,500,120));
			pwmWrite(300+Noha5.pin+1,map(Noha5.uhol2,500,120));
			pwmWrite(300+Noha5.pin+2,map(Noha5.uhol3,500,120));
			delay(10);
			pwmWrite(400+Noha2.pin,map(Noha2.uhol1,120,500));
			pwmWrite(400+Noha2.pin+1,map(Noha2.uhol2,120,500));
			pwmWrite(400+Noha2.pin+2,map(Noha2.uhol3,120,500));
			delay(10);
			pwmWrite(400+Noha4.pin,map(Noha4.uhol1,120,500));
			pwmWrite(400+Noha4.pin+1,map(Noha4.uhol2,120,500));
			pwmWrite(400+Noha4.pin+2,map(Noha4.uhol3,120,500));
			delay(10);
			pwmWrite(400+Noha6.pin,map(Noha6.uhol1,120,500));
			pwmWrite(400+Noha6.pin+1,map(Noha6.uhol2,120,500));
			pwmWrite(400+Noha6.pin+2,map(Noha6.uhol3,120,500));
			cout<<"dole"<<endl;
			delay(500);
			
			
		Move.move2(InputX, InputZ);
		Move.move2(InputX, InputZ);
			Noha1.pohyb(Move.Ciel1);
			Noha4.pohyb(Move.Ciel4);
			Noha5.pohyb(Move.Ciel5);
			Noha2.pohyb(Move.Ciel2);
			Noha3.pohyb(Move.Ciel3);
			Noha6.pohyb(Move.Ciel6);

			pwmWrite(300+Noha1.pin,map(Noha1.uhol1,500,120));
			pwmWrite(300+Noha1.pin+1,map(Noha1.uhol2,500,120));
			pwmWrite(300+Noha1.pin+2,map(Noha1.uhol3,500,120));
			delay(10);
			pwmWrite(300+Noha3.pin,map(Noha3.uhol1,500,120));
			pwmWrite(300+Noha3.pin+1,map(Noha3.uhol2,500,120));
			pwmWrite(300+Noha3.pin+2,map(Noha3.uhol3,500,120));
			delay(10);
			pwmWrite(300+Noha5.pin,map(Noha5.uhol1,500,120));
			pwmWrite(300+Noha5.pin+1,map(Noha5.uhol2,500,120));
			pwmWrite(300+Noha5.pin+2,map(Noha5.uhol3,500,120));
			delay(10);
			pwmWrite(400+Noha2.pin,map(Noha2.uhol1,120,500));
			pwmWrite(400+Noha2.pin+1,map(Noha2.uhol2,120,500));
			pwmWrite(400+Noha2.pin+2,map(Noha2.uhol3,120,500));
			delay(10);
			pwmWrite(400+Noha4.pin,map(Noha4.uhol1,120,500));
			pwmWrite(400+Noha4.pin+1,map(Noha4.uhol2,120,500));
			pwmWrite(400+Noha4.pin+2,map(Noha4.uhol3,120,500));
			delay(10);
			pwmWrite(400+Noha6.pin,map(Noha6.uhol1,120,500));
			pwmWrite(400+Noha6.pin+1,map(Noha6.uhol2,120,500));
			pwmWrite(400+Noha6.pin+2,map(Noha6.uhol3,120,500));
			cout<<"move2"<<endl;
			delay(500);
			
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
			pwmWrite(300+Noha1.pin,map(Noha1.uhol1,500,120));
			pwmWrite(300+Noha1.pin+1,map(Noha1.uhol2,500,120));
			pwmWrite(300+Noha1.pin+2,map(Noha1.uhol3,500,120));
			delay(10);
			pwmWrite(300+Noha3.pin,map(Noha3.uhol1,500,120));
			pwmWrite(300+Noha3.pin+1,map(Noha3.uhol2,500,120));
			pwmWrite(300+Noha3.pin+2,map(Noha3.uhol3,500,120));
			delay(10);
			pwmWrite(300+Noha5.pin,map(Noha5.uhol1,500,120));
			pwmWrite(300+Noha5.pin+1,map(Noha5.uhol2,500,120));
			pwmWrite(300+Noha5.pin+2,map(Noha5.uhol3,500,120));
			delay(10);
			pwmWrite(400+Noha2.pin,map(Noha2.uhol1,120,500));
			pwmWrite(400+Noha2.pin+1,map(Noha2.uhol2,120,500));
			pwmWrite(400+Noha2.pin+2,map(Noha2.uhol3,120,500));
			delay(10);
			pwmWrite(400+Noha4.pin,map(Noha4.uhol1,120,500));
			pwmWrite(400+Noha4.pin+1,map(Noha4.uhol2,120,500));
			pwmWrite(400+Noha4.pin+2,map(Noha4.uhol3,120,500));
			delay(10);
			pwmWrite(400+Noha6.pin,map(Noha6.uhol1,120,500));
			pwmWrite(400+Noha6.pin+1,map(Noha6.uhol2,120,500));
			pwmWrite(400+Noha6.pin+2,map(Noha6.uhol3,120,500));
			cout<<"servo normal"<<endl;
			delay(500);
		
	}
	

	
}

