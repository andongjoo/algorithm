#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int arr[26];
int main(int argc, char** argv) {

	int a,b;
	cin>>a>>b;
	
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	reverse(arr,arr+n);
	int sum=0;
	int mul=1;
	for(int i=0;i<n;i++)
	{
		sum +=  (mul*arr[i]);
		mul*=a;
	}
		
//	printf("%d",sum);
	vector<int> num;
	while(sum)
	{
		num.push_back(sum%b);
		sum/=b;
	}

	reverse(num.begin(),num.end());
	for(int i=0;i<num.size();i++)
		printf("%d ",num[i]);

	return 0;
}
