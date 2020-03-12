#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int main(int argc, char** argv) {

	int a,b;
	
	cin>>a>>b;
	vector<int> v;
	while(a)
	{
		int r= a%b;
		int temp;
		if(r>=10)
		{
			temp= 'A'+r-10;
			v.push_back(temp);
		}else
		{
			temp='0'+r;
			v.push_back(temp);
		}	

		a/=b;
		
	}
	reverse(v.begin(),v.end());
	for(int i=0;i<v.size();i++)
		printf("%c",v[i]);
	return 0;
}
