#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX=100;
vector<int> list[MAX];
vector<int> rlist[MAX];
int t[MAX];
int clk=1;
bool check[MAX];
bool check2[MAX];
int order[MAX],order_len=0;
int group[MAX],group_cnt=1;

void get_time(int node)
{//노드부터 dfs를 하면서 빠져나오는 순서대로 시간을 기록
  
  check[node]=true;
  for(int i=0;i<list[node].size();i++)
  {
    int node2=list[node][i];
    
    if(!check[node2])
      get_time(node2);
  }
  
  t[node]=clk++;
  order[order_len++]=node;
}

void get_my_group(int node)
{
  check2[node]=true;
  group[node]=group_cnt;
  for(int i=0;i<rlist[node].size();i++)
  {
    int node2=rlist[node][i];
      if(!check2[node2])
      {
        get_my_group(node2);
        
      }
  }
  
  
}

int n,m;

int main()
{
  cin>>n>>m;
  for(int i=0;i<m;i++)
  {
    int a,b;
    cin>>a>>b;
    list[a].push_back(b);
    rlist[b].push_back(a);
    
    
    
  }
  
  for(int i=1;i<n;i++)
  {
    if(!check[i])
    {
      get_time(i);
    }
    
  }
  
  for(int i=order_len-1;i>=0;i--)
  {
    int node = order[i];
    if (!check2[node])
    {
      get_my_group(node);
      group_cnt++;
      
    }
  }

  for(int i=1;i<=n;i++)
  
    printf("group[%d]:%d\n",i,group[i]);
  return 0;  
}

































// #include <iostream>
// #include <vector>
// #include <algorithm>
// const int MAX=100;
// using namespace std;
// vector <int> list[MAX];
// vector <int> rlist[MAX];
// int t[MAX];
// int clk=1;

// bool check[MAX],check2[MAX];
// int order[MAX], order_len=0;
// int group[MAX],group_cnt=1;; //group[i]:정점 i가 속한 그룹번호
// int n,m;

// //노드부터 시작하여 dfs를 하면서 빠져나오는 순서대로 시간을 기록
// void get_time(int node)
// {
//   check[node]=true;
  
//   for(int i=0;i<list[node].size();i++)
//   {
//     int node2=list[node][i];
//     if(!check[node2])
//       get_time(node2);
    
//   }
//   t[node]=clk++;
//   order[order_len++]=node;
// }

// void get_my_group(int node)
// {
//   //노드부터 dfs하는데 거꾸로된 그래프로
//   check2[node]=true;
//   group[node]=group_cnt;
//   for(int i=0;i<rlist[node].size();i++)
//   {
//       int node2=rlist[node][i];
//       if(!check2[node2])
//       {
//         get_my_group(node2);
//       }
//   }
  
// }

// int main() {
//   cin>>n>>m;
//   for(int i=0;i<m;i++)
//   {
//     int a,b;
//     cin>>a>>b;
//     list[a].push_back(b);
//     rlist[b].push_back(a);
    
//   }
  
//   for(int i=1;i<=n;i++)
//   {
    
//     if(!check[i])
//     {
//       get_time(i);
//     }
    
//   } //빠져나오는 순서대로 시간을 기록했다.
  
//   //뒤집은 그래프에 대해서, 빠져나오는 시간이 큰 노드부터 순순서대로
//   // 이때 만나는 노드들이 모두 같은 그룹이다.
//   for(int i=order_len-1;i>=0;i--)
//   {
//     int node =order[i];
//     if(!check2[node])
//       {get_my_group(node);
//         group_cnt++;
        
//       }
//   }
  
//   printf("group_cnt:%d\n",group_cnt-1);
//   for(int i=1;i<=n;i++)
//   {
//       printf("%d : %d\n",i,group[i]);
//   }
//   return 0;
// }

/* 
12 18
1 2
2 3
2 4
3 1
3 7
3 9
4 6
4 11
5 4
6 5 
7 8  
7 9 
8 10
8 12
9 10 
10 7
11 12
12 11
*/
