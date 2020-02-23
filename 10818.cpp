#include <iostream>
#include <algorithm>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n;
	cin>>n;
	int a=-99999999;
	int b=99999999;
	int *arr=new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		a=max(a,arr[i]);
		b=min(b,arr[i]);
	}
	cout<<b<<" "<<a<<endl;
	return 0;
}
