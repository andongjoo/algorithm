#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX=10001;
int t;
vector<int> prime;
int cnt[MAX]={0,};

int main() {
	for(int i=1000;i<10000;i++)
  {
	int flag=0;
    for(int j=2;j<i;j++)
    {
		if(i%j==0) flag=1;
      
    }
    if(flag==0)
      prime.push_back(i);
  	}
  	
  cin>>t;
   for(int test=0;test<t;test++)
   {
  
  
  // 	printf("%d\n",prime.size());
  
  // for(int i=0;i<t;i++)
  // {
    
    int check[MAX]={0,};
    int a,b;
    cin>>a>>b;
    queue <int> qu;
    int src=a;
    int dest=b;
    
    //시작숫자 쪼갠거 
    int aa,bb,cc,dd;
    aa=a/1000;
    a%=1000;
    bb=a/100;
    a%=100;
    cc=a/10;
    a%=10;
    dd=a;
    
    // printf("start %d %d %d %d\n",aa,bb,cc,dd); 
    // printf("last %d\n",dest);

    
	qu.push(src);
	
	
 
    while(!qu.empty())
    {
      
    int x = qu.front();
    qu.pop();
    
    // printf("%d ",x);
    //큐에있는거 쪼갠거 
    int ee,ff,gg,hh;
    ee=x/1000;
    x%=1000;
    ff=x/100;
    x%=100;
    gg=x/10;
    x%=10;
    hh=x;
    x=ee*1000+ff*100+gg*10+hh;
    	 //printf("%d %d \n",x,dest);
  // printf("큐 : %d %d %d %d\n",ee,ff,gg,hh); 
// 	printf("%d\n",x);
	
//	 printf("%d %d \n",x,dest);
    
    if( x==dest)
    {
      printf("%d\n",cnt[x]);
      break;
    }
    
   
      check[x]=true;
      
      for(int i=0;i<prime.size();i++)
      {
        if(check[prime[i]]==false)
        {
          int p=prime[i];
          //소수배열에서 쪼갠거 
          int q=p/1000;
          int w=(p-q*1000)/100;
          int e= (p-q*1000-w*100)/10;
          int r=(p-q*1000 -w*100 -e*10);
          // printf("%d ",prime[i]);
          // printf("%d %d %d %d\n",q,w,e,r);
          int count=0;
          if( ee==q)
            count++;
          if(ff==w)
            count++;
          if(gg==e)
            count++;
          if(hh==r)
            count++;
            
          if(count==3 )
           {
            qu.push(p);
			      cnt[p]= cnt[x]+1;
			      check[prime[i]]=true;
          }
      
        }
        } 
    
      
     }
    
    for(int i=1000;i<10000;i++)
    {  check[i]=false;
        cnt[i]=0;
      
    }
  
   }
  return 0;
}
