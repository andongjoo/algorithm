#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N,M,K;
int Answer;
const int MAX=100;
typedef struct
{
    int x;
    int y;
    int Num;
    int Dir;
    bool State;
}Bug;


vector<Bug> V;
vector<int> MAP[MAX][MAX];
 
int dx[] = { 0, -1, 1, 0, 0 };
int dy[] = { 0, 0, 0, -1, 1 };


void Initialize()
{
    Answer = 0;
    V.clear();
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            MAP[i][j].clear();
        }
    }
}



void Input()
{
	cin>>N>>M>>K;
	int x,y,n,d;

	for(int i=0;i<K;i++)
	{
		cin>>x>>y>>n>>d;
		Bug temp;
		temp.x=x;
		temp.y=y;
		temp.Num=n;
		temp.Dir=d;
		temp.State=true;
		V.push_back(temp);
		MAP[x][y].push_back(i);
	}
}



void Move()
{
    for (int i = 0; i < V.size(); i++)
    {
        if (V[i].State == false) continue;
 
        MAP[V[i].x][V[i].y].clear();
    }
 
    for (int i = 0; i < V.size(); i++)
    {
        if (V[i].State == false) continue;
 
        V[i].x = V[i].x + dx[V[i].Dir];
        V[i].y = V[i].y + dy[V[i].Dir];
        MAP[V[i].x][V[i].y].push_back(i);
    }
}



int Change_Direction(int Cur_D)
{
    if (Cur_D == 1) return 2;
    else if (Cur_D == 2) return 1;
    else if (Cur_D == 3) return 4;
    else if (Cur_D == 4) return 3;
}



void Merge()
{
	
	for(int i=0;i<V.size();i++)
	{
		if(V[i].State==false)
			continue;
		
		int x=V[i].x;
		int y=V[i].y;
		int d=V[i].Dir;
		
		if(x==0 || y==0 || x==N-1 || y==N-1)
		{
			V[i].Num=V[i].Num/2;
			V[i].Dir=Change_Direction(d);
		}
		
		if(V[i].Num==0)
		{
			V[i].State=false;
			
		}		
	}
	
	for(int i=0;i<V.size();i++)
	{
		if(V[i].State==false)
			continue;
		
		int x=V[i].x;
		int y=V[i].y;
		
		if(MAP[x][y].size()>1)
		{
			int Sum=0;
			int Biggest_Num=0;
			int Select_Dir=0;
			int Select_Idx=0;
			
			for(int j=0;j<MAP[x][y].size();j++)
			{
				Sum= Sum+V[MAP[x][y][j]].Num;
				
				if(V[MAP[x][y][j]].Num>Biggest_Num)
				{
					Biggest_Num=V[MAP[x][y][j]].Num;
					Select_Dir=V[MAP[x][y][j]].Dir;
					Select_Idx=MAP[x][y][j];
				}
				V[MAP[x][y][j]].State=false;
				
			}
			V[Select_Idx].Dir=Select_Dir;
			V[Select_Idx].Num=Sum;
			V[Select_Idx].State=true;
			MAP[x][y].clear();
			MAP[x][y].push_back(Select_Idx);
			
			
		}
			

	}
	
}

int calc()
{
	int sum=0;
	for(int i=0;i<V.size();i++)
	{
		if(V[i].State==false)
			continue;
			
		sum+=V[i].Num;
	}
	return sum;
}

void Solution()
{
    for (int i = 0; i < M; i++)
    {
        Move();
        Merge();
    }
 
    Answer = calc();
}

void Solve()
{
	int tc;
	cin>>tc;
	for(int t=1;t<=tc;t++)
	{
		Initialize();
        Input();
        Solution();
 		cout << "#" << t << " " << Answer<<"\n";
    }
}
int main(int argc, char** argv) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout.tie(0);
	

	Solve();


	return 0;
}
