#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(int argc, char** argv) {
	vector<int> v;
	for(int i=0;i<9;i++)
	{
		int h;
		cin>>h;
		v.push_back(h);
	}
	
	do{
		int sum=0;
		for(int i=0;i<7;i++)
			sum+=v[i];
		if(sum==100)
		{
		
			break;
		}
	}while(next_permutation(v.begin(),v.end()));
	vector<int> ans;
	for(int i=0;i<7;i++)
	{
		ans.push_back(v[i]);
		
	}
	sort(ans.begin(),ans.end());
	for(int i=0;i<ans.size();i++)
		printf("%d\n",ans[i]);
	return 0;
}
