package swea;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class contact1238 {
	static int n, start,max,index;
	static ArrayList<Integer>[] node;
	static boolean[] visited;
	static int[] cnt;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		for (int t = 1; t <= 10; t++) {
			max=0;
			index=0;
			n = sc.nextInt();
			start = sc.nextInt();
			visited = new boolean[101];
			cnt=new int[101];
			node= new ArrayList[101];
			
			for(int i=0;i<101;i++)
				node[i]= new ArrayList<Integer>();
			
			for (int i = 0; i < n/2; i++) {
				int from = sc.nextInt();
				int to = sc.nextInt();
				node[from].add(to);
			}
			bfs(start);

			for(int i=0;i<101;i++)
			{
				if(cnt[i]>=max)
				{
					max=cnt[i];
					index=i;
				}
			}
			
			System.out.printf("#%d %d\n",t,index);
//			for(int i=0;i<101;i++)
//				System.out.printf("%d:%d  ",i,cnt[i]);
//			System.out.println();
		}
	}

	private static void bfs(int cur) {
		Queue<Integer> q = new LinkedList<Integer>();
		visited[cur] = true;
		q.offer(cur);
		int t = 1;
		while (!q.isEmpty()) {
			int qs = q.size();
			while (qs>0) {
				qs--;
				int current = q.poll();
				cnt[current]=t;
				for (int temp : node[current]) {
					if (!visited[temp]) {
						q.offer(temp);
						visited[temp] = true;
					}
				}
			}
			t++;
		}

	}

}
