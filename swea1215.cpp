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
		cin>>l;
		for(int i=0;i<8;i++)
			for(int j=0;j<8;j++)
				cin>>a[i][j];
		
	ans=0;	
	for(int k=0;k<8;k++)
	{
		for(int j=0;j<8+1-l;j++)
		{
			string s="";
			for(int i=j;i<j+l;i++)
			{
				s+=a[k][i];
			}
			
			if(palinedrome(0,l-1,s))
			{
				ans++;
			}
		}
	
		for(int j=0;j<8+1-l;j++)
		{
			string s="";
			for(int i=j;i<j+l;i++)
			{
				s+=a[i][k];
			}
			if(palinedrome(0,l-1,s))
			{
				ans++;
			}
			
			
		}
	}
	
		printf("#%d %d\n",t,ans);
	}

	return 0;
}
