#include <iostream>
#include <algorithm>
using namespace std;
int tc,ans;
int p,q,r,s,w;
int main(int argc, char** argv) {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	cin>>tc;
	for(int t=1;t<=tc;t++)
	{
		cin>>p>>q>>r>>s>>w;
		int a=0;
		int b=0;
		ans=0;
		if(w<=r)
		{
			b=q;
		}else{
			b=q+s*(w-r);
		}
		
		a=p*w;
		ans=min(a,b);
		
		cout<<"#"<<t<<" "<<ans<<"\n";
	}
	
	
	
	return 0;
}
