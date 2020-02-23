#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int INF=999999;
const int SWITCH=10;
const int CLOCK=16;
int linked[SWITCH][CLOCK] = {

        {1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1},
        {1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
        {0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1},
        {0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0}

};

bool areAligned(const vector<int> & clocks){
	
	for(int i=0;i<CLOCK;i++)
	{
		if(clocks[i]!=12)
			return false;
	}
	return true;
}

void push(vector<int>& clocks,int swtch)
{
	for(int clock=0;clock<CLOCK;clock++)
	{
		if(linked[swtch][clock]==1)
		{
			clocks[clock]+=3;
			if(clocks[clock]==15)
				clocks[clock]=3;
		}
	}
}

int solve(vector<int>& clocks,int swtch)
{
	if(swtch==SWITCH)
		return areAligned(clocks) ? 0:INF;
	int ret=INF;
	for(int cnt=0;cnt<4;cnt++)
	{
		ret=min(ret,cnt+solve(clocks,swtch+1));
		push(clocks,swtch);
	}
	return ret;
}


int main(int argc, char** argv) {
	int test;
	cin>>test;
	vector<int> clocks(CLOCK);
	for(int t=0;t<test;t++)
	{
		for(int i=0;i<CLOCK;i++)
			cin>>clocks[i];
		int answer=solve(clocks,0);
		
		if(answer==INF)
			printf("-1\n");
		else
			printf("%d\n",answer);		


	}

	return 0;
}
