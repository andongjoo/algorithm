#include <iostream>
#include <vector>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
const int MAX=500001;
int n;
int a[MAX];
int b[MAX];

long long ans=0;
void merge(int s,int mid,int e)
{
	int i=s,j=mid+1;
	int idx=s;
	int cnt=0;
	while(i<=mid || j<=e)
	{
		if(i> mid)
		{
			b[idx++]=a[j++];
			cnt++;
		}else if (j>e)
		{
			b[idx++]=a[i++];
			ans+=(long long)cnt;
		}else if(a[i]<=a[j])
		{
			b[idx++]=a[i++];
			ans+=(long long )cnt;
		}else {
			b[idx++]=a[j++];
			cnt++;
		}
	}
	for(int i=s;i<=e;i++)
	{
		a[i]=b[i];
	}
	
}

void mergesort(int s,int e)
{
	int mid=(s+e)/2;
	if(s<e)
	{
		mergesort(s,mid);
		mergesort(mid+1,e);
		merge(s,mid,e);
	}
}


int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	
	mergesort(0,n-1);
	cout<<ans;

	return 0;
}
