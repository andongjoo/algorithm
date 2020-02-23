#include <iostream>
#include <algorithm>
using namespace std;
const int MAX=501;
int arr[MAX][MAX]={0};
int dp[MAX][MAX]={0,};

int main(int argc, char** argv) {
	
	cin>>n;
	
	
	for(int i=0;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		
		arr[a][b]=1;
		arr[b][a]=1;
		
	}
	
	
	
	return 0;
}
