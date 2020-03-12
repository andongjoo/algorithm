#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n,m;

bool binarysearch(vector<int> &v,int number)
{
	int start=0;
	int end=v.size()-1;
	
	int mid;
	
	while(start<=end)
	{
		mid=(start+end)/2;
		
		if(v[mid]<number)
		{
			start=mid+1;
		}else{
			
			if(v[mid]==number)
				return true;
			end=mid-1;
		}
	}
	return false;
}

int main(int argc, char** argv) {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	vector<int> card;
	
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		int number;
		cin>>number;
		card.push_back(number);
	}
	
	sort(card.begin(),card.end());
	
	
	cin>>m;
	for(int i=0;i<m;i++)
	{
		int number;
		cin>>number;
		
		printf("%d ",binarysearch(card,number));
		
	}
	
	
	
	return 0;
}
