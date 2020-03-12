#include <iostream>


using namespace std;
const int N=27;
struct tree{
	
	char left;
	char right;
	
};

tree array[N];

void preorder(char node)
{
	if(node=='.')
	{
		return;
	}
	else 
	{
		printf("%c",node);
		
		preorder(array[node].left);
		preorder(array[node].right);
	}
	
}

void inorder(char node)
{
	if(node=='.')
	{
		return;
	}else{
		inorder(array[node].left);
		printf("%c",node);
		inorder(array[node].right);
	}
	
}

void postorder(char node)
{
	
	if(node=='.')
	{
		return;
	}else{
		postorder(array[node].left);
		postorder(array[node].right);
		printf("%c",node);
	}
}
int main(int argc, char** argv) {

	
	int m;
	cin>>m;

	for(int i=0;i<m;i++)
	{
		char a,b,c;
		cin>>a>>b>>c;
		array[a].left=b;
		array[a].right=c;
	}
	
	preorder('A');
	printf("\n");
	inorder('A');
	printf("\n");
	postorder('A');
	return 0;
}
