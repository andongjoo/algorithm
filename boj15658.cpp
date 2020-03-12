#include <iostream>
#include <vector>
using namespace std;
const int MAX=101;
int n;
int a[MAX];
int op[4];
int h=-987987987,l=987987987;
void go(int index,int cnt,int sum)
{
//	printf("%d %d %d\n",index,cnt,sum);
	if(cnt==n)
	{
//			printf("%d\n",sum);
			h=max(h,sum);
			l=min(l,sum);
			return;
	}
	
	if(index==n)	
	{
		return;
	}
	
	

		if(op[0])
		{
				op[0]--;
				go(index+1,cnt+1,sum+a[index]);
				op[0]++;
		}
		if(op[1])
		{
			op[1]--;
			go(index+1,cnt+1,sum-a[index]);
			op[1]++;	
		}
		if (op[2])
		{
			op[2]--;
			go(index+1,cnt+1,sum*a[index]);
			op[2]++;
		}
		if(op[3]){
			op[3]--;
			go(index+1,cnt+1,sum/a[index]);
			op[3]++;
		}
			
			
		
		
	
	
}

int main(int argc, char** argv) {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);	
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<4;i++)
	{
		cin>>op[i];
	}

	go(1,1,a[0]);
	printf("%d\n%d\n",h,l);

	return 0;
}
