
import java.util.Queue;
import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Scanner;

public class boj_dfsbfs {

	static int n,m,v;
	static boolean[] visited;
	static ArrayList<Integer>[] g;
	
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		
		n=sc.nextInt();
		m=sc.nextInt();
		v=sc.nextInt();
		visited=new boolean[n+1];
		g=new ArrayList[n+1];
		for(int i=0;i<n+1;i++)
			g[i]=new ArrayList<Integer>();
		
		for(int i=0;i<m;i++)
		{
			int from=sc.nextInt();
			int to=sc.nextInt();
			g[from].add(to);
			g[to].add(from);
		}
		
		for(int i=0;i<n+1;i++)
			Collections.sort(g[i]);
		
		
		dfs(v);
		System.out.println();
		visited=new boolean[1001];
		bfs();
		
		
		
	}
	
	private static void dfs(int node) {
		visited[node]=true;
		System.out.printf("%d ",node);
		for(int i=0;i<g[node].size();i++)
		{
			int next=g[node].get(i);
			if(!visited[next]) {
				dfs(next);
			}
		}
		
	}
	
	private static void bfs() {
		Queue<Integer> q=new LinkedList<Integer>();
		q.offer(v);
		visited[v]=true;
		
		while(!q.isEmpty()) {
			
			int cur=q.peek();
			q.poll();
			System.out.printf("%d ",cur);
			
			for(int i=0;i<g[cur].size();i++)
			{
				int next=g[cur].get(i);
				if(!visited[next]) {
					q.offer(next);
					visited[next]=true;
				}
			}
			
			
		}
		
		
	}

}
