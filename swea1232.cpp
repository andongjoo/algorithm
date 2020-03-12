#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
using namespace std;

#define MAX_NODE_NUM 1000
#define MAX_CHILD_NUM 2

stack <double> s;
queue <double> q;

int ans;
int n;
typedef struct{
	
	int parent;
	int child[MAX_CHILD_NUM];
	double data;
	char op;
	
}treenode;

treenode tree[MAX_NODE_NUM];


void initTree(void)
{
    int i;
    int j;
    for (i = 0; i <= n; i++)
    {
        tree[i].parent = -1;
        for (j = 0; j < MAX_CHILD_NUM; j++)
        {
            tree[i].child[j] = -1;
        }
        tree[i].data = 0;
        tree[i].op = 0;
    }
}

void addchild(int parent,int child)
{
	int i;
	for(i=0;i< MAX_CHILD_NUM ;i++)
	{
		if(tree[parent].child[i]==-1)
		{
			break;
		}
	}
	tree[parent].child[i]=child;
	tree[child].parent=parent;
}

void postorder(int x)
{
	 int child;
    for (int i = 0; i < MAX_CHILD_NUM; i++)
    {
        child = tree[x].child[i];
        if (child != -1)
        {
            postorder(child);
        }
    }
    if (tree[x].data == 0) {
        q.push(tree[x].op*(-1));
    }
    else q.push(tree[x].data);
}

int calc()
{
	 while (!q.empty()) {//calc
        double op1, op2;
        if (q.front() == ((int)'+'*(-1)) || q.front() == ((int)'-'*(-1)) || q.front() == ((int)'*'*(-1)) || q.front() == ((int)'/'*(-1))) {
            if (q.front() == ((int)'+'*(-1))) {
                q.pop();
                op1 = s.top();
                s.pop();
                op2 = s.top();
                s.pop();
                s.push(op2 + op1);
            }
            else if (q.front() == ((int)'-'*(-1))) {
                q.pop();
                op1 = s.top();
                s.pop();
                op2 = s.top();
                s.pop();
                s.push(op2 - op1);
            }
            else if (q.front() == ((int)'*'*(-1))) {
                q.pop();
                op1 = s.top();
                s.pop();
                op2 = s.top();
                s.pop();
                s.push(op2 * op1);
            }
            else if (q.front() == ((int)'/'*(-1))) {
                q.pop();
                op1 = s.top();
                s.pop();
                op2 = s.top();
                s.pop();
                s.push(op2 / op1);
            }
        }
        else {
            s.push(q.front());
            q.pop();
        }
    }
    int answer = s.top();
    return answer;
	
}


int main(int argc, char** argv) {
	
	for(int t=1;t<=10;t++)
	{
		ans=0;
		cin>>n;
		initTree();
		for(int i=1;i<=n;i++)
		{
			int node;
			cin>>node;
			string str;
			cin>>str;
			if(str[0]=='+' || str[0]=='-'|| str[i]=='*' || str[i]=='/')
			{
				int l,r;
				cin>>l>>r;
				addchild(i,l);
				addchild(i,r);
				tree[i].op=str.front();
			}
			else
			{
				double x=stoi(str);
				tree[i].data=x;
			}
			
		}
		postorder(1);
		ans=calc();
		
				
		printf("#%d %d\n",t,ans);
		
		while (!q.empty())q.pop();
        while (!s.empty())s.pop();
		
	}

	return 0;
}
