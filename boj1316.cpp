#include <iostream>
#include <string>
using namespace std;
int n;
bool check[130];
int main(int argc, char** argv) {
	cin>>n;
	int ret=0;
	for(int i=0;i<n;i++)
	{
		string s;
		cin>>s;
		for(int j=0;j<130;j++)
			check[j]=0;
			
		int index=0;
		while(s[index]!='\0')
		{
			if(!check[s[index]])
			{
				check[s[index]]=1;
				char temp=s[index];
				for(int k=index;s[k]==temp;k++)
				{
					index++;
				}
			}else if (check[s[index]])
			{
				ret-=1;
				break;
			}			
						
		}
			ret++;
		
		
		
	}printf("%d",ret);
	
	return 0;
}
