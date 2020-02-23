#include <iostream>
using namespace std;

int main(int argc, char** argv) {

	int e,s,m;
	cin>>e>>s>>m;
	int t=0;
	
	int q=1,w=1,r=1;
	while(++t)
	{
//		printf("ÇöÀç %d %d %d \n",q,w,r);
		if(e==q && w==s && m==r)
		{
//			printf("%d %d %d  ::: %d %d %d\n",e,s,m,q,w,r);
			
				printf("%d",t);
				break;
		}
		
		q+=1;
		w+=1;
		r+=1;
		
		if(q%16==0)
			q=1;
		if(w%29==0)
			w=1;
		if(r%20==0)
			r=1;
			
			
	}
	return 0;
}
