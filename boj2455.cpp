#include <iostream>
#include <algorithm>
using namespace std;
int ans;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int n,m;
int main(int argc, char** argv) {
	int cur=0;
	while(1)
	{
		
		cin>>n>>m;
		
		cur+=m;
		cur-=n;
		
		ans=max(ans,cur);
		
		
		if(!m)
			break;
	}
	cout<<ans;
	return 0;
}
