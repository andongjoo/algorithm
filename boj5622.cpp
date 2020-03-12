#include <iostream>
#include <string>
using namespace std;

int main(int argc, char** argv) {
	string s;
	cin>>s;
	int sum=0; 
	for(int i=0;i<s.size();i++)
	{
		char temp=s[i];
		
		if(temp<='C')
		{
			sum+=3;
		}else if (temp>='D' && temp<='F'){
			
			sum+=4;
		}else if (temp>='G' && temp<='I'){
			
			sum+=5;
		}else if (temp>='J' && temp<='L'){
			
			sum+=6;
		}else if (temp>='M' && temp<='O'){
			
			sum+=7;
		}else if (temp>='P' && temp<='S'){
			
			sum+=8;
		}else if (temp>='T' && temp<='V'){
			
			sum+=9;
		}else if (temp>='W' && temp<='Z'){
			
			sum+=10;
		}
		
	}
		printf("%d",sum);
	return 0;
}
