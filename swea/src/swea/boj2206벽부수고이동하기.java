package swea;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class boj2206벽부수고이동하기 {

	static int[][] map;
	static int[][] visited, visited2;
	static int n, m, ans;
	static int[] dx = { 1, -1, 0, 0 };
	static int[] dy = { 0, 0, 1, -1 };

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		m = sc.nextInt();

		map = new int[n][m];
		visited = new int[n][m];
		visited2 = new int[n][m];
		ans = 987987987;
		for (int i = 0; i < n; i++) {
			String str = sc.next();
			for (int j = 0; j < m; j++) {
				map[i][j] = str.charAt(j) - '0';

			}
		}
		bfs();
		bfs2();

		if (visited2[0][0] != 0)
			ans = visited2[0][0];

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] == 1) {
					int a = 987987, b = 987987;
					int cnt1 = 0, cnt2 = 0;
					for (int k = 0; k < 4; k++) {
						int nx = i + dx[k];
						int ny = j + dy[k];
						if (nx >= n || ny >= m || nx < 0 || ny < 0)
							continue;
						if (map[nx][ny] == 0 && visited[nx][ny] > 0) {
							cnt1++;
							a = Math.min(visited[nx][ny], a);
						}

						if (map[nx][ny] == 0 && visited2[nx][ny] > 0) {
							cnt2++;
							b = Math.min(visited2[nx][ny], b);
						}
					}
					if (cnt1 > 0 && cnt2 > 0) {

						ans = Math.min(ans, a + b + 1);

					}
				}
			}
		}
		if (ans == 987987987)
			System.out.println(-1);
		else
			System.out.println(ans);
	}

	static class Point {
		int x, y;

		public Point(int x, int y) {
			super();
			this.x = x;
			this.y = y;
		}

	}

	static void bfs() {
		Queue<Point> q = new LinkedList();
		q.add(new Point(0, 0));
		visited[0][0] = 1;

		while (!q.isEmpty()) {
			int x = q.peek().x;
			int y = q.peek().y;
			q.poll();

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx >= n || ny >= m || nx < 0 || ny < 0)
					continue;

				if (visited[nx][ny] == 0 && map[nx][ny] == 0) {
					q.add(new Point(nx, ny));
					visited[nx][ny] = visited[x][y] + 1;
				}

			}
		}

	}

	static void bfs2() {
		Queue<Point> q = new LinkedList();
		q.add(new Point(n - 1, m - 1));
		visited2[n - 1][m - 1] = 1;

		while (!q.isEmpty()) {
			int x = q.peek().x;
			int y = q.peek().y;
			q.poll();

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx >= n || ny >= m || nx < 0 || ny < 0)
					continue;

				if (visited2[nx][ny] == 0 && map[nx][ny] == 0) {
					q.add(new Point(nx, ny));
					visited2[nx][ny] = visited2[x][y] + 1;
				}

			}
		}

	}
}
