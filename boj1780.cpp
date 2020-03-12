#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > v;
int minus_=0,zero_=0,plus_=0;

void paper(int ly,int lx,int size)
{
	if(size==1)
	{
		if(v[ly][lx]==-1)
			minus_++;
		else if(v[ly][lx]==0)
			zero_++;
		else if(v[ly][lx]==1)
			plus_++;
	
			return;
	}
	
	int temp=v[ly][lx];
	
	for(int i=ly;i<ly+size;i++)
	{
		for(int j=lx;j<lx+size;j++)
		{
			if(temp!=v[i][j])
			{
				for(int k=0;k<3;k++)
					for(int z=0;z<3;z++)
						paper(ly+(size/3)*k,lx+(size/3)*z,size/3);
				
				return;
			}
		}
	}
	
		if(v[ly][lx]==-1)
			minus_++;
		else if(v[ly][lx]==0)
			zero_++;
		else if(v[ly][lx]==1)
			plus_++;
		else
			return;
}

int main(int argc, char** argv) {

	int n;
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		v.push_back(vector<int>());
		for(int j=0;j<n;j++)
		{
			int num;
			cin>>num;
			v.at(i).push_back(num);
		}
	}
	
	
		paper(0,0,n);
	
	printf("%d\n%d\n%d\n",minus_,zero_,plus_);
	
	return 0;
}
