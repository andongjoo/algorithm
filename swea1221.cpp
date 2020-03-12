#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
int ans;
int tc;
int main(int argc, char** argv) {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	
	cin>>tc;
	
	for(int t=1;t<=tc;t++)
	{
		v.clear();
		string str;
		cin>>str;
		int n;
		cin>>n;
		for(int j=0;j<n;j++)
		{
			string s="";
			cin>>s;
			
			if(s=="ZRO")
			{
				v.push_back(0);
			}else if (s=="ONE")	
			{
				v.push_back(1);
			}else if (s=="TWO")	
			{
				v.push_back(2);
			}else if (s=="THR")	
			{
				v.push_back(3);
			}else if (s=="FOR")	
			{
				v.push_back(4);
			}else if (s=="FIV")	
			{
				v.push_back(5);
			}else if (s=="SIX")	
			{
				v.push_back(6);
			}else if (s=="SVN")	
			{
				v.push_back(7);
			}else if (s=="EGT")	
			{
				v.push_back(8);
			}else if (s=="NIN")	
			{
				v.push_back(9);
			}
			
		}
		sort(v.begin(),v.end());
		
		printf("#%d\n",t);
//		cout<<str<<"\n";
		
		for(int i=0;i<v.size();i++)
		{
			if(v[i]==0)
			{
				printf("ZRO ");
			}else if (v[i]==1)
			{
				printf("ONE ");
			}else if (v[i]==2)
			{
				printf("TWO ");
			}else if (v[i]==3)
			{
				printf("THR ");
			}else if (v[i]==4)
			{
				printf("FOR ");
			}else if (v[i]==5)
			{
				printf("FIV ");
			}else if (v[i]==6)
			{
				printf("SIX ");
			}else if (v[i]==7)
			{
				printf("SVN ");
			}else if (v[i]==8)
			{
				printf("EGT ");
			}else if (v[i]==9)
			{
				printf("NIN ");
			}
			
		}		
		printf("\n");
		
		
	}
	

	return 0;
}
