#include <iostream>
#include <string>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int a[129];
int main(int argc, char** argv) {
	string s;
	cin>>s;
	int d='a'-'A';
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='a' && s[i]<='z')
		{
			a[s[i]-d]++;
		}else
			a[s[i]]++;
	}
	int index=0;
	int ans=0;
	for(int i=0;i<129;i++)
	{
		if(a[i]>ans)
		{
			ans=a[i];
			index=i;
		}
	}
	int cnt=0;
	for(int i=0;i<129;i++)
	{
		if(a[i]==ans)
			cnt++;
	}
	if(cnt==1)
	printf("%c",index);
	else
	printf("?");
	return 0;
}
