#include <iostream>
#include <ctime>
using namespace std;

int random(void)
{
	int i;
	i=rand()%10;
	return i;
}

int main(int argc, char** argv) {

	srand(time(NULL));
	for(int i=0;i<4;i++)
	{
		printf("%3d",random());
	}printf("\n");
	
	return 0;
}
