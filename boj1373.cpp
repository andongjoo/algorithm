#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


int main(int argc, char** argv) {
	string str;
	cin>>str;
	
	reverse(str.begin(),str.end());
	string sum="";
	int mul=1;
	for(int i=0;i<str.size();i+=3)
	{
		int a=0;
		int m=1;
		for(int j=i;j<str.length()&& j<i+3;j++)
		{
			if(str[j]=='1')
			{
				a += m;		
			}
			m*=2;
		}
//		printf("%d\n",a);
		sum +=(a+'0');
		
	}
	reverse(sum.begin(),sum.end());
	cout<<sum;
	return 0;
}
