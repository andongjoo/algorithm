package swea;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class boj2606바이러스 {
	static int n, m, ans;
	static boolean visited[];
	static ArrayList<Integer>[] arr;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		m = sc.nextInt();
		ans = 0;
		arr = new ArrayList[n + 1];
		visited = new boolean[n + 1];
		for (int i = 1; i <= n; i++)
			arr[i] = new ArrayList();

		for (int i = 0; i < m; i++) {
			int n1, n2;
			n1 = sc.nextInt();
			n2 = sc.nextInt();
			arr[n1].add(n2);
			arr[n2].add(n1);
		}
		bfs();
		for (int i = 1; i <= n; i++) {
			if (visited[i])
				ans++;
		}
		System.out.println(ans-1);

	}

	static void bfs() {

		Queue<Integer> q = new LinkedList();
		visited[1] = true;
		q.add(1);

		while (!q.isEmpty()) {
			int node = q.peek();
			q.poll();

			for (int i = 0; i < arr[node].size(); i++) {
				int next = arr[node].get(i);
				if (!visited[next]) {
					q.add(next);
					visited[next] = true;
				}
			}
		}

	}
}
