#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(char a,char b)
{
	return a>b;
}

int main(int argc, char** argv) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout.tie(0);
	
	string num;
	cin>>num;
	
	long long sum=0;
	bool zero=false;
	
	for(int i=0;i<num.size();i++)
	{
		int item=num[i]-'0';
		sum+= (item);
		
		if(!item)
			zero=true;
	}
	
	
	
	if( sum%3 || !zero)
		printf("-1");
	else{
		sort(num.begin(),num.end(),cmp);
		cout<<num;
	}
	return 0;
}
