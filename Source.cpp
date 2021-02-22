#include<iostream>
using namespace std;

int map(int x) {
	return (x - 0) * (500 - 120) / (180 - 0) + 120;
}
int main()
{
	cout << map(180);
}
