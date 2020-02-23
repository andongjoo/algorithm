#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int n;
int num[20]={0};
char oper[20];
int num_cnt,oper_cnt;
long long answer=-LLONG_MAX;
void input(){
	
	num_cnt=0,oper_cnt=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		if(i%2==0)
			cin>>num[num_cnt++];
		else
			cin>>oper[oper_cnt++];
		
	}	
	
	
}



long long calc(long long a,long long b,char op)
{
	long long  result=0;
	switch(op)
	{
		case '+':
			result=a+b;
			break;
		case '-':
			result=a-b;
			break;
		case '*':
			result=a*b;
			break;
		
		
	}
	return result;
	
	
}


void dfs(long long result,int index){
	
	int now=0,next=0;
	if(index>=oper_cnt){
		
		answer=max(result,answer);
		
		return;
	}
	
	now=calc(result,num[index+1],oper[index]);
	dfs(now,index+1);
	
	if(index+2<num_cnt){
		
		
		next=calc(num[index+1],num[index+2],oper[index+1]);
		now=calc(result,next,oper[index]);
		dfs(now,index+2);
	}
	
	
	
}
int main(int argc, char** argv) {

	input();
	dfs(num[0],0);
	printf("%d\n",answer);

	return 0;
}
