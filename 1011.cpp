#include <iostream>
#include <cmath>
using namespace std;

int n;



int main(int argc, char** argv) {

	int t;
	cin>>t;
	
	while(t--)
	{
		int x,y;
		cin>>x>>y;
		long long l=y-x;
		
		long long jump=1;
		
		
		for(;; jump++)
			if(jump*jump>l)
				break;
		
		jump--;
		
		long long left = l-(jump*jump);
		
		left = (long long )ceil( (double)left/(double)index);
		
		printf("%d\n",jump*2-1+left);
		
		
		
	}


	return 0;
}
