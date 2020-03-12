#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
const int MAX=9;

int map[MAX][MAX];
int n,m;
int cnt=0;
vector<int> cctv;
vector<pair<int,int> > cctvs;

int dx[]={0,1,0,-1};
int dy[]={-1,0,1,0};
#define U (1<<0)
#define R (1<<1)
#define D (1<<2)
#define L (1<<3)
int direct[10];   
vector<int> moving[5] = {
    {U, R, D, L},
    {U|D, R|L},
    {U|R, U|L, D|R, D|L},
    {U|R|L, D|R|L, R|U|D, L|U|D},
    {U|R|D|L}
};

int solve(int cur)
{
	if(cur==(int)cctv.size())
	{
		int cpymap[MAX][MAX];
		 memcpy(cpymap, map, sizeof(cpymap));

	  for (int i = 0; i < (int)cctvs.size(); ++i) {
            int y = cctvs[i].first, x = cctvs[i].second;
            int type = cctv[i] - 1;
            for (int j = 0; j < 4; ++j) {
                if (moving[type][direct[i]] & (1 << j)) {
                    for (int cy = y, cx = x;; cy += dy[j], cx += dx[j]) {
                        if (cy < 0 || cy >= n || cx < 0 || cx >= m || cpymap[cy][cx] == 6) break;
                        cpymap[cy][cx] = -1;
                    }
                }
            }
        }
		
		int sum = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                sum += cpymap[i][j] == 0;
        return sum;
	
	}
	
	int ret = 987987987;
    for (int i = 0; i < (int)moving[cctv[cur] - 1].size(); ++i) {
        direct[cur] = i;
        ret = min(ret, solve(cur + 1));
    }
    return ret;
}

int main(int argc, char** argv) {
	cin>>n>>m;
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>map[i][j];
			if(map[i][j]>=1 && map[i][j]<=5)
			{
				cctv.push_back(map[i][j]);
				cctvs.push_back({i,j});
			}
		}
	}
	
	printf("%d",solve(0));
	
	
	return 0;
}
