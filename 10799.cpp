#include <iostream>
#include <stack>
#include <string>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	string str;
	cin>>str;
	int op=0;
	int ans=0;
	for(int i=0;i<str.length();i++)
	{
		if(str[i]=='(')
			op++;
		else if(str[i]==')')
		{
			op--;
			if(str[i-1]=='(')
				ans+=op;
			else
				ans+=1;
			
		}
		
		printf("index :%d ans : %d\n",i,ans);
		
	}
	
	printf("%d\n",ans);
	
	return 0;
}
