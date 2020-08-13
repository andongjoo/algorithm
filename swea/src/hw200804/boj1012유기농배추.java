package hw200804;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;



public class boj1012유기농배추 {
	static int N,K,M,ans;
	static int[][] map;
	static boolean[][]visited;
	static int[] dx= {1,-1,0,0};
	static int[] dy= {0,0,1,-1};
	public static void main(String[] args) {
		Scanner sc =new Scanner(System.in);
		int TC=sc.nextInt();
		
		for(int t=0;t<TC;t++)
		{
			ans=0;
			M=sc.nextInt();
			N=sc.nextInt();
			K=sc.nextInt();
			map=new int[N][M];
			visited=new boolean[N][M];
			for(int i=0;i<K;i++)
			{

				int x=sc.nextInt();
				int y=sc.nextInt();

				map[y][x]=1;
			}
			
			for(int i=0;i<N;i++)
			{
				for(int j=0;j<M;j++) {
					if(!visited[i][j] && map[i][j]==1) {
						bfs(i,j);
						ans++;
					}
					
				}
			}
			System.out.println(ans);
		}
		
	}
	
	static private void bfs(int x,int y) {
		Queue<Integer> q = new LinkedList<Integer>();
		q.offer(x);
		q.offer(y);
		visited[x][y]=true;
		
		while(!q.isEmpty())
		{
			int curx=q.peek();
			q.poll();
			int cury=q.peek();
			q.poll();
			
			for(int i=0;i<4;i++)
			{
				int nx=curx+dx[i];
				int ny=cury+dy[i];
				
				if(nx>=N || ny>=M || nx<0 || ny<0)
					continue;
				
				if(!visited[nx][ny] && map[nx][ny]==1)
				{
					visited[nx][ny]=true;
					q.offer(nx);
					q.offer(ny);
				}
			}
			
			
		}
		
	}

}
