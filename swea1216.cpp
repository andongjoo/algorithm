#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;
int ans;
int l;
char a[100][100];
bool palinedrome(int s,int e,string str)
{
	if(s==e)
	{
		return true;
	}else if (s+1==e)
	{
		if(str[s]==str[e])
			return true;
		else
			false;
	}else{
		if(str[s]==str[e])
			return palinedrome(s+1,e-1,str);
		else
			return false;
	}
}



int main(int argc, char** argv) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout.tie(0);
	
	for(int t=1;t<=10;t++)
	{
		int tn;
		cin>>tn;
		int l=2;
		for(int i=0;i<100;i++)
			for(int j=0;j<100;j++)
				cin>>a[i][j];
		
	ans=0;	
	for(int k=0;k<100;k++)
	{
		for(int j=0;j<100;j++)
		{
			for(int l=2;l<100;l++)
			{
				if(j+l>100)
					continue;
				string s="";
		
				for(int i=j;i<j+l;i++)
				{
					s+=a[k][i];
				}
			
				if(palinedrome(0,l-1,s))
				{
					ans=max(ans,l);
				}
			}
		}
	
		for(int j=0;j<100;j++)
		{
			
			for(int l=2;l<100;l++)
			{
				
				if(j+l>100)
					continue;
				string s="";
		
				for(int i=j;i<j+l;i++)
				{
					s+=a[i][k];
				}
			
				if(palinedrome(0,l-1,s))
				{
					ans=max(ans,l);
				}
				
			}
			
			
		}
	}
	
		printf("#%d %d\n",tn,ans);
	}

	return 0;
}
