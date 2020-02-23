#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring> 
#include <string.h>
#include <utility>
#include <queue>
using namespace std;
const int MAX=1001;
int t,w,h;
char map[MAX][MAX]={0};
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int check[MAX][MAX]={0};
int cnt[MAX][MAX]={0};
struct person
{
	int r,c,t;
};

queue<pair<int,int> > q;
pair<int,int> start;
int main(int argc, char** argv) {

	cin>>t;
	
	
	
	while(t--)
	{	person p;
		queue <person> qq;
		int ans=987654321;
		cin>>w>>h;
		for(int i=0;i<h;i++)
		{
			scanf("%s",map[i]);
		}
		
		memset(check,0,sizeof(check));
		memset(cnt,0,sizeof(cnt));
		
		while (!q.empty())
		{
				q.pop();
		}
		
		for(int i=0;i<h;i++)
		{
			for(int j=0;j<w;j++)
			{
				if(map[i][j]=='@')
				{
						qq.push({i,j,0});
						
				}
				
				if(map[i][j]=='*')
				{
						q.push({i,j});
				}
				
				
			}
		}
		
		
		while(!q.empty())
		{
			int r=q.front().first;
			int c=q.front().second;
			check[r][c]=1;
			q.pop();
			for(int i=0;i<4;i++)
			{
				int ny=r+dy[i];
				int nx=c+dx[i];
				
				if(0<=ny && 0<=nx && ny<h && nx<w && map[ny][nx]!='#'&& check[ny][nx]==0)
				{
					check[ny][nx]=1;
//					printf("%d %d %c\n",ny,nx,map[ny][nx]);
					cnt[ny][nx]=cnt[r][c]+1;
					q.push({ny,nx});
				}
				
				
			}
		}
		
	
		
		memset(check,0,sizeof(check));
		
//		printf("사람 : %d %d",p.r,p.c);
		while(!qq.empty())
		{
			int r=qq.front().r;
			int c=qq.front().c;
			int t=qq.front().t;
			check[r][c]=1;
			qq.pop();
			
				if(r==0 || c==0|| r==h-1||w-1==c && map[r][c]!='#')
				{
//					printf("탈출한다 %d %d\n",r,c);


					if(cnt[r][c]==0 && t!=0)
						ans=min(t+1,ans);	

					if(cnt[r][c]!=0 && t!=0 && cnt[r][c]>t)
					{
							ans=min(t+1,ans);
					}
					
					if(t==0)
					{
							ans=1;
					}
					
//					printf(" 결과 : %d %d %d  r:%d c: %d ::: %d %d ans:%d\n",cnt[r][c]>cnt2[r][c],cnt[r][c]!=0,cnt2[r][c]!=0,r,c,cnt[r][c],cnt2[r][c],ans);

				}
				
//			printf("sibla %d %d\n",r,c);
			for(int i=0;i<4;i++)
			{
				int ny=r+dy[i];
				int nx=c+dx[i];
	

				
				if(0<=ny && 0<=nx && ny<h && nx<w  && check[ny][nx]==0 && map[ny][nx]!='#')
				{
					if(!check[ny][nx]&& map[ny][nx]!='*'&& cnt[ny][nx]>t+1&& cnt[ny][nx]!=0)
					{
						qq.push({ny,nx,t+1});
					}
					else if (!check[ny][nx]&& map[ny][nx]!='*' && cnt[ny][nx]==0)
					{
						qq.push({ny,nx,t+1});
					}
//					printf("여기다 %d %d \n",ny,nx);
//					q.push({ny,nx});
//					cnt2[ny][nx]=cnt2[r][c]+1;
				}
				
			

			}
			
			
		}
		
		
//		for(int i=0;i<h;i++)
//		{
//			for(int j=0;j<w;j++)
//			{
//				printf("%c ",map[i][j]);
//			}printf("\n");
//		}printf("\n");
		
		
//		for(int i=0;i<h;i++)
//		{
//			for(int j=0;j<w;j++)
//			{
//				printf("%d ",cnt[i][j]);
//			}printf("\n");
//		}printf("\n");
//		
//		for(int i=0;i<h;i++)
//		{
//			for(int j=0;j<w;j++)
//			{
//				printf("%d ",cnt2[i][j]);
//			}printf("\n");
//		}printf("\n");
//		
		
		if(ans==987654321)
			printf("IMPOSSIBLE\n");
		else
			printf("%d\n",ans);
	
	
		
	}


	return 0;
}
