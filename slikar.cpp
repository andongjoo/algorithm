/*
사악한 암흑의 군주 임정택은 드디어 원하던 마법 구슬을 손에 넣었고, 알랩숲에 홍수를 일으켰다! 이 숲에 살고 있는 고슴도치는 지금 당장 비버의 굴로 가능한 빨리 돌아가 홍수를 피하려고 한다.

알랩숲의 지도는 R행 C열로 구성되어 있다. 비어있는 곳은 '.'로 나타나 있고, 물이 차있는 지역은 '*', 돌은 'X'로 표현되어 있다. 추가적으로, 비버의 굴은 'D'로, 고슴도치의 위치는 'S'로 표시되어 있다.

매 분마다 고슴도치는 현재 있는 칸과 인접한 네 칸 중 하나로 이동할 수 있다. (위, 아래, 오른쪽, 왼쪽) 물은 매 분마다 물이 있는 칸과 적어도 한 변을 공유하는 비어있는 모든 칸에 물이 차게 된다. 물과 고슴도치는 돌을 통과할 수 없다. 또, 고슴도치는 물로 차있는 구역으로 이동할 수 없고, 물은 비버의 소굴로 이동할 수 없다.

알랩숲의 지도가 주어졌을 때, 고슴도치가 안전하게 비버의 굴로 도달하기 위해 필요한 최소 시간을 구하는 프로그램을 작성하시오.

고슴도치는 물이 찰 예정인 칸으로 이동할 수 없음에 주의한다.

 

입력
첫째 줄에 50보다 작거나 같은 자연수 R과 C가 주어진다.

다음 R개 줄에 걸쳐 C개의 문자가 주어진다.('.', '*', 'X', 'D' or 'S') 'D'와 'S'는 하나씩만 주어진다.

 

출력
첫째 줄에 고슴도치가 비버의 굴로 도달할 수 있는 가장 빠른 시간을 출력한다. 만약, 안전하게 비버의 굴로 이동할 수 없을 경우, "KAKTUS"를 출력한다.

 

예제 입력 1
3 3
D.*
...
.S.
예제 출력 1
3
예제 입력 2
3 3
D.*
...
..S
예제 출력 2
KAKTUS
예제 입력 3
3 6
D...*.
.X.X..
....S.
예제 출력 3
6
예제 입력 4
5 4
.D.*
....
..X.
S.*.
....
예제 출력 4
4
 

출처
COCI 2006/2007, Contest #1 4번  */


#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

queue<int> q;
queue<int> q2;
const int MAX=51;
char g[MAX][MAX];
bool check[MAX][MAX];
bool check2[MAX][MAX];
bool flag2[MAX][MAX];
bool flag[MAX][MAX];
int r,c;
int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};
int cnt[MAX][MAX]={0,};
int cnt2[MAX][MAX]={0,};

void bfs()
{

  while(!q.empty())
    {
       int  wy=q.front(); q.pop();
      int wx=q.front(); q.pop();
      check[wy][wx]=true;
    
      
    for(int i=0;i<4;i++)
    { 
        
        if ( 0<=wx+dx[i] && wx+dx[i]<c && 0<=wy+dy[i] && wy+dy[i]<r && check[wy+dy[i]][wx+dx[i]]==false
         && g[wy+dy[i]][wx+dx[i]]!='X' && g[wy+dy[i]][wx+dx[i]]!='D' && g[wy+dy[i]][wx+dx[i]]!='*')
      {
          
          
          q.push(wy+dy[i]);
          q.push(wx+dx[i]);
          // if (g[wy+dy[i]][wx+dx[i]]!='D')
          //   g[wy+dy[i]][wx+dx[i]]='*';
          
            cnt[wy+dy[i]][wx+dx[i]]=cnt[wy][wx]+1;
          
          
      }
        else if (0<=wx+dx[i] && wx+dx[i]<c && 0<=wy+dy[i] && wy+dy[i]<r && g[wy+dy[i]][wx+dx[i]]=='D' &&check[wy+dy[i]][wx+dx[i]]==false)
          {
            flag2[wy+dy[i]][wx+dx[i]]=true;
            check[wy+dy[i]][wx+dx[i]]=true;
        }
        
      
    }
      // for(int i=0;i<r;i++)
      // {
      //   for(int j=0;j<c;j++)
      //     printf("%c ",g[i][j]);
      // printf("\n"); 
      // }printf("\n");
    
      
    }
  
  
  
  
}

void bfs2(int y,int x)
{
  q2.push(y);
  q2.push(x);
  
    while(!q2.empty())
    {

    int  yy=q2.front(); q2.pop();
    int xx=q2.front(); q2.pop();
      check2[yy][xx]=true;
      if (g[yy][xx]=='D')
          {
       
            flag[yy][xx]=true;
          }
    
    for(int i=0;i<4;i++)
    { 
        
        if ( 0<=xx+dx[i] && xx+dx[i]<c && 0<=yy+dy[i] && yy+dy[i]<r && check2[yy+dy[i]][xx+dx[i]]==false
         && g[yy+dy[i]][xx+dx[i]]!='X' && g[yy+dy[i]][xx+dx[i]]!='*')
      {
          
          q2.push(yy+dy[i]);
          q2.push(xx+dx[i]);
           cnt2[yy+dy[i]][xx+dx[i]]=cnt2[yy][xx]+1;
          // printf("%d %d\n",yy+dy[i],xx+dx[i]);
          
        }
      }
    }
  
}


int main() {
  cin>>r>>c;
  for(int i=0;i<r;i++)
      scanf("%s",g[i]);
      
  // for(int i=0;i<r;i++)
  // {  for(int j=0;j<c;j++)
  //     {
  //       printf("%c",g[i][j]);
  //     }printf("\n");    
    
  // }printf("\n");
  
  
  
  for(int i=0;i<r;i++)
  {  for(int j=0;j<c;j++)
      {
        if(g[i][j]=='*')
           {
             q.push(i);
             q.push(j);
           }
            
        if(check2[i][j]==false && g[i][j]=='S')
            bfs2(i,j);
            
      }
  }
  
 bfs();
  
  
  // for(int i=0;i<r;i++)
  // {  for(int j=0;j<c;j++)
  //     {
  //       printf("%d ",cnt[i][j]);
		// }printf("\n");
            
  //     }printf("\n");
  
  //   for(int i=0;i<r;i++)
  // {  for(int j=0;j<c;j++)
  //     {
  //       printf("%d ",cnt2[i][j]);
		// }printf("\n");
            
  //     }printf("\n");
  

  
	for(int i=0;i<r;i++)
	{
	  for(int j=0;j<c;j++)
	  {
	    if (flag[i][j]==true )
	    {
	      
	      for(int k=0;k<4;k++)
	      {
	      
	        
	      
	         // printf("%d %d\n",cnt2[i+dy[k]][j+dx[k]],cnt[i+dy[k]][j+dx[k]]);
	          if( 0<=i+dy[k] && i+dy[k]<r && 0<=j+dx[k] && j+dx[k]<c && cnt2[i+dy[k]][j+dx[k]]!=0 &&cnt2[i+dy[i]][j+dx[k]]< cnt[i+dy[k]][j+dx[k]] && flag[i][j]==true && flag2[i][j]==true )
	            {
	             
	             if( cnt2[i+dy[k]][j+dx[k]]<cnt[i+dy[k]][j+dx[k]] )   
	             { printf("%d ",cnt2[i][j]);
	              return 0;
	             }
	             
	            }
	           else if ( 0<=i+dy[k] && i+dy[k]<r && 0<=j+dx[k] && j+dx[k]<c && flag[i][j]==true && flag2[i][j]==false && cnt2[i][j]> cnt[i][j]  )
	            {
	              printf("%d ",cnt2[i][j]);
	              return 0;
	            }
	       
	      }
	      
	      
	    }
	    
	  }
	}

	
	printf("KAKTUS");
            
  
  return 0;
}
