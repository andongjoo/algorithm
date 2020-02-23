#include <iostream>
#include <algorithm>
#include <string.h>
#include <utility>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

typedef struct shark{
	int r;
	int c;
	int size;
	int eat;
	int t;	
};

bool cmp(shark a,shark b) {

    if (a.t <= b.t) {
        if (a.t == b.t) {
            if (a.r <= b.r) {
                if (a.r == b.r) {
                    if (a.c < b.c) {
                        return true;
                    }
                    return false;
                }
                return true;
            }
            return false;
        }
        return true;
    }
    return false;
}

int map[22][22]={0};
int cnt[22][22]={0};
int check[22][22]={0};
int dy[]={-1,0,0,1};
int dx[]={0,-1,1,0};

int n;

queue <shark> q;
vector <shark> v;	

int ans=0;

int main(int argc, char** argv) {
	shark s;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>map[i][j];
			if(map[i][j]==9)
				{
					map[i][j]=0;
					s = {i,j,2,0,0};
				
				}
				
		}	
	}
	
	while(1)
	{
		v.clear();
		memset(check,0,sizeof(check));
		check[s.r][s.c]=1;
		q.push(s);		
	
//		printf("%d %d  size:%d eat:%d  t:%d \n",s.r,s.c,s.size,s.eat,s.t);
		while(!q.empty())
		{
			
			int r=q.front().r;
			int c=q.front().c;
			int eat=q.front().eat;
			int t=q.front().t;
			int size=q.front().size;
			q.pop();
			
			for(int i=0;i<4;i++)
			{
				int nr=r+dy[i];
				int nc=c+dx[i];
				
				if(0<=nr && 0<=nc && nr<n && nc<n)
				{
					if(!check[nr][nc])
					{
					
						if (map[nr][nc]==0 || map[nr][nc]==size)
						{
							q.push({nr,nc,size,eat,t+1});
							check[nr][nc]=1;
						}
						else if(map[nr][nc]<size)	
						{
							v.push_back({nr,nc,size,eat+1,t+1});
							check[nr][nc]=1;
						} 
						
					}
					
				}
				
				
			}
	}		
			if(v.size()==0)
				break;
			
			
			sort(v.begin(),v.end(),cmp);
			
			if(v[0].size == v[0].eat)
				{
					v[0].size=v[0].size+1;
					v[0].eat=0;
				}
			
			map[v[0].r][v[0].c]=0;
			ans+=v[0].t;
			s={v[0].r,v[0].c,v[0].size,v[0].eat,0};
			
//			printf("\n");
//			for(int i=0;i<n;i++)
//			{
//				for(int j=0;j<n;j++)
//				{
//					printf("%d ",map[i][j]);
//				}printf("\n");
//			}printf("\n");
			
			
		}



	



	
	printf("%d\n",ans);	

	return 0;
}
