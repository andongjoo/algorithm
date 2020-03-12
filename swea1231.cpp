#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct{
	
	char ch;
	int left,right;
}nod;

nod node[120];
int n;
vector<char> v;
bool check[120];
void inorder(int order)
{
//	cout<<order<<" ";

	if(node[order].left!=-1)
		inorder(node[order].left);
	v.push_back(node[order].ch);
	if(node[order].right!=-1)
		inorder(node[order].right);
	
}


int main(int argc, char** argv) {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	
	
	for(int t=1;t<=10;t++){

		cin>>n;
		v.clear();
		for(int i=0;i<110;i++)
			check[i]=false;
			
		for(int i=1;i<=n;i++)
		{
			int num;
			cin>>num;
			char ch;
			cin>>ch;
			int l,r;
			node[num].ch=ch;
			node[num].left=-1;
			node[num].right=-1;
			
			if(n%2==0 && n/2>i || n%2==1 &&n/2>=i)
			{
				cin>>l>>r;
				node[num].left=l;
				node[num].right=r;
			}else if (n%2==0 && n/2==i)
			{
				cin>>l;
				node[num].left=l;
			}
			
			
		}				
		printf("#%d ",t);
		
		inorder(1);
		for(int i=0;i<v.size();i++)
			printf("%c",v[i]);
		printf("\n");

		
	}
	

	return 0;
}
