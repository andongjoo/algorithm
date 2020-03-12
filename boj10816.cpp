#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int n,m;

vector<int> card;


int main(int argc, char** argv) {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
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
		int start=0;
		int end=card.size()-1;
		printf("%d ",upper_bound(card.begin(),card.end(),number)-
					 lower_bound(card.begin(),card.end(),number));	
	}
	
	
	
	return 0;
}
