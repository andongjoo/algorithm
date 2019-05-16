/*
세로 R칸, 가로 C칸으로 나누어진 표 모양의 판이 있다. 판의 각각의 모든 칸에는 대문자 알파벳이 하나씩 적혀 있다. 좌측 상단 칸 (1행 1열) 에는 말이 놓여 있다.

말은 인접한 네 칸(상하좌우) 중의 한 칸으로 이동할 수 있다. 이때 매순간 여태 지나온 칸에 적힌 알파벳과 다른 알파벳 칸으로만 이동할 수 있다. 즉, 같은 알파벳이 적힌 칸을 두 번 지날 수 없다.

말이 가능한 많은 칸을 지나도록 할 때, 몇 칸을 이동할 수 있는지 구하는 프로그램을 작성하시오. 말이 지나는 칸은 초기에 말이 위치했던 칸도 포함된다.

 

입력
첫째 줄에 R과 C가 빈칸을 사이에 두고 주어진다. (1 ≤ R, C ≤ 20) 둘째 줄부터 R개의 줄에 걸쳐서 C개의 대문자 알파벳들이 주어진다.

 

출력
첫째 줄에 말이 이동할 수 있는 칸의 최대값을 출력한다.

 

예제 입력
2 4
JOOS
OBJS
예제 출력
3
 

출처
Croatia OI 2002 Regional Competition - Juniors 3번  
*/

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int dy[4]={1,-1,0,0};
int dx[4]={0,0,-1,1};
int r,c;
const int MAX=21;
int alpha[200]={0,};
bool check[MAX][MAX];
char letter[MAX][MAX];
  
int cnt=0;
int cnt2[MAX][MAX]={0,};

void dfs(int yy,int xx,int cc)
{
  
  cc++;
  // printf("%d %d  c: %d \n",yy,xx,c);
  // printf("%c\n",letter[yy][xx]);
  
  for(int i=0;i<4;i++)
    {
      int y=yy+dy[i];
      int x=xx+dx[i];
      if( 0<=y && y<r && 0<=x && x<c && check[y][x]==false && alpha[letter[y][x]]==0)
      {
       // cnt2[y][x]=cnt2[yy][xx]+1;
        check[y][x]=true;
        alpha[letter[y][x]]=1;
  
        dfs(y,x,cc);
        
        check[y][x]=false;
        alpha[letter[y][x]]=0;
        
      }
  }
  
  if(cc>cnt)
    cnt=cc;
  
  // printf("끝\n");
}







int main() {
  
  cin>>r>>c;
  for(int i=0;i<r;i++)
    scanf("%s",letter[i]);
  
  // printf("r:%d c:%d\n",r,c);
  check[0][0]=true;
  alpha[letter[0][0]]=1;
  dfs(0,0,0);
  


  printf("%d",cnt);
  
  return 0;
}
