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
	
	for(int i = 0; i<10;i++)
	{
		cout<<i<<endl;
		delay(100);
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
			delay(100);
			cout<<"Noha1: "<<Noha1.uhol1<<" "<<Noha1.uhol2<<" "<<Noha1.uhol3<<endl;
			pwmWrite(300+Noha3.pin,map(Noha3.uhol1,500,120));
			pwmWrite(300+Noha3.pin+1,map(Noha3.uhol2,500,120));
			pwmWrite(300+Noha3.pin+2,map(Noha3.uhol3,500,120));
			delay(100);
			cout<<"Noha2: "<<Noha2.uhol1<<" "<<Noha2.uhol2<<" "<<Noha2.uhol3<<endl;
			pwmWrite(300+Noha5.pin,map(Noha5.uhol1,500,120));
			pwmWrite(300+Noha5.pin+1,map(Noha5.uhol2,500,120)+20);
			pwmWrite(300+Noha5.pin+2,map(Noha5.uhol3,500,120));
			delay(100);
			cout<<"Noha3: "<<Noha3.uhol1<<" "<<Noha3.uhol2<<" "<<Noha3.uhol3<<endl;
			pwmWrite(400+Noha2.pin,map(Noha2.uhol1,120,500));
			pwmWrite(400+Noha2.pin+1,map(Noha2.uhol2,120,500));
			pwmWrite(400+Noha2.pin+2,map(Noha2.uhol3,120,500));
			delay(100);
			cout<<"Noha4: "<<Noha4.uhol1<<" "<<Noha4.uhol2<<" "<<Noha4.uhol3<<endl;
			pwmWrite(400+Noha4.pin,map(Noha4.uhol1,120,500));
			pwmWrite(400+Noha4.pin+1,map(Noha4.uhol2,120,500));
			pwmWrite(400+Noha4.pin+2,map(Noha4.uhol3,120,500));
			delay(100);
			cout<<"Noha5: "<<Noha5.uhol1<<" "<<Noha5.uhol2<<" "<<Noha5.uhol3<<endl;
			pwmWrite(400+Noha6.pin+2,map(Noha6.uhol1,120,500));
			pwmWrite(400+Noha6.pin+1,map(Noha6.uhol2,120,500));
			pwmWrite(400+Noha6.pin,map(Noha6.uhol3,120,500));
			delay(100);
			cout<<"Noha6: "<<Noha6.uhol1<<" "<<Noha6.uhol2<<" "<<Noha6.uhol3<<endl;
			cout<<"normal\n";
			delay(500);
			
		Move.doleI -=10;
		cout<<"Dole: "<<Move.doleI<<endl;
			
			
		/*Move.move1(0,1);
		Noha2.pohyb(Move.Ciel2);
		Noha3.pohyb(Move.Ciel3);
		Noha6.pohyb(Move.Ciel6);
		Noha1.pohyb(Move.Ciel1);
		Noha4.pohyb(Move.Ciel4);
		Noha5.pohyb(Move.Ciel5);
		
		
			pwmWrite(300+Noha1.pin,map(Noha1.uhol1,500,120));
			pwmWrite(300+Noha1.pin+1,map(Noha1.uhol2,500,120));
			pwmWrite(300+Noha1.pin+2,map(Noha1.uhol3,500,120));
			delay(1000);
			pwmWrite(300+Noha3.pin,map(Noha3.uhol1,500,120));
			pwmWrite(300+Noha3.pin+1,map(Noha3.uhol2,500,120));
			pwmWrite(300+Noha3.pin+2,map(Noha3.uhol3,500,120));
			delay(1000);
			pwmWrite(300+Noha5.pin,map(Noha5.uhol1,500,120));
			pwmWrite(300+Noha5.pin+1,map(Noha5.uhol2,500,120));
			pwmWrite(300+Noha5.pin+2,map(Noha5.uhol3,500,120));
			cout<<"move1\n";
			delay(3000);*/
			
			
	}
	

	
}
