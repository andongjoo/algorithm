#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int tc,ans;
int m,a;
int chargeA,chargeB;
int dy[]={0,-1,0,1,0};
int dx[]={0,0,1,0,-1};
int user[2][101];
typedef struct {
	int x,y,c,p;	
}BC;
vector<BC> bc;
int ax,ay,bx,by;

int solve()
{
	
		chargeA=0,chargeB=0;
		ax=ay=1,bx=by=10;
		for(int k=0;k<=m;k++)
		{
			vector<int> a,b;
			for(int i=0;i<bc.size();i++)
			{
				if(abs(ax-bc[i].x)+abs(ay-bc[i].y)<=bc[i].c)
					a.push_back(i);
				if (abs(bx - bc[i].x) + abs(by - bc[i].y) <= bc[i].c) 
                	b.push_back(i);
        	}
			
		int pA=0,pB=0,sum=0;
		if(!a.empty() && b.empty())
		{
			for(int i=0;i<a.size();i++)
			{
				
				int tmpA=bc[a[i]].p;
				if(sum<tmpA){
					sum=tmpA;
					pA=tmpA;
				}
				
			}
		}
			
		else if(a.empty() && !b.empty())
		{
			for(int i=0;i<b.size();i++)
			{
				
				int tmpB=bc[b[i]].p;
				if(sum<tmpB){
					sum=tmpB;
					pB=tmpB;
				}
				
			}
			
			
		}else{
			for(int i=0;i<a.size();i++)
			{
				for(int j=0;j<b.size();j++)
				{
					int tmpA=bc[a[i]].p;
					int tmpB=bc[b[j]].p;
					if(a[i]==b[j]){
						tmpA/=2;
						tmpB/=2;
					}
					if(sum<tmpA+tmpB){
						sum=tmpA+tmpB;
						pA=tmpA;
						pB=tmpB;
					}
				}
			}
		}
			ax+=dx[user[0][k]];
			ay+=dy[user[0][k]];
			bx+=dx[user[1][k]];
			by+=dy[user[1][k]];
			chargeA+=pA;
			chargeB+=pB;
			
		}
		return chargeA+chargeB;
}


int main(int argc, char** argv) {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	cin>>tc;
	for(int t=1;t<=tc;t++)
	{
		bc.clear();
		cin>>m>>a;
		for(int i=0;i<m;i++) 
			cin>>user[0][i];
		for(int i=0;i<m;i++) 
			cin>>user[1][i];
	
		for(int i=0;i<a;i++)
		{
			int x,y,c,p;
			cin>>x>>y>>c>>p;
			bc.push_back(BC{x,y,c,p});
		}
		ans=solve();
		printf("#%d %d\n",t,ans);
	}
	return 0;
}
