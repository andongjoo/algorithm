#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;
void prime(int n,int m) {

    int *a=new int[m+1];
	for(int i=0;i<=m;i++)
		a[i]=i;
    
	
	for(int i=2;i<=m;i++){
		if(a[i]!=0)
		{
		
		if((unsigned int)pow(i,2)>1000001)
			break;
		else{
		
			for(int j=i+i;j<=m;j+=i)
				a[j]=0;

			}
		}
	}
	
	if(n==1)
		n++;

    for (int i=n; i<=m; i++) {

        if (a[i] != 0)   
			printf("%d\n",a[i]);
    }

}



int main(void) {

    int n,m;
    cin>>n>>m;
    prime(n,m);


}



