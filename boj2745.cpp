#include <iostream>
#include <string>
#include <algorithm>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;


int main(int argc, char** argv) {
	string str;
	int n;
	cin>>str>>n;
	long long sum=0;
	reverse(str.begin(),str.end());
	int mul=1;
	for(int i=0;i<str.length();i++)
	{
		if(str[i]>='0' && str[i]<='9')
		{
			sum+= (str[i]-'0')*mul;
		
		}else if(str[i]>='A' && str[i]<='Z')
		{
			sum+=   (str[i]-'A'+10)*mul;	
		}
		mul*=n;
		
	}
	cout<<sum;
	return 0;
}
