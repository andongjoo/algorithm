#include <iostream>
using namespace std;

int main(int argc, char** argv) {
	int n;
	cin>>n;
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(i%5==0)
		 cnt++;
		
		if(i%25==0)
			cnt++;
		if(i%125==0)
			cnt++;
	}
	cout<<cnt;
	return 0;
}
//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//int main(int argc, char** argv) {
//	int n;
//	cin>>n;
//	int cnt5=0;
//	int cnt2=0;
//	for(int i=5;i<=500;i*=5)
//	{
//		if(n%i==0)
//		cnt5+=n/5;
//	}
//	for(int i=2;i<=500;i*=2)
//	{
//		if(n%i==0)
//		cnt2+=n/2;
//	}
//	cout<<min(cnt5,cnt2);
//	return 0;
//}
