package swea;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class boj1697숨바꼭질 {
	static int n, m, ans;
	static boolean visited[];
	static ArrayList<Integer>[] arr;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		m = sc.nextInt();
		ans = 987987987;
		Queue<Integer> q = new LinkedList();
		visited = new boolean[100012];
		int time = 0;
		q.add(n);
		visited[n] = true;
		while (!q.isEmpty()) {

			int qs = q.size();

			while (qs > 0) {

				int cur = q.peek();
//				System.out.println(cur);
				q.poll();
				if (cur == m) {
					ans = Math.min(time, ans);
					
				}
				int dn[] = { cur - 1, cur + 1, cur * 2 };

				for (int i = 0; i < 3; i++) {
					if (dn[i] >= 0 && dn[i] <= 100000) {
						if (!visited[dn[i]]) {
							q.add(dn[i]);
							visited[dn[i]] = true;
						}
					}
				}
				qs--;
			}
			time++;
		}
		System.out.println(ans);
	}

}
