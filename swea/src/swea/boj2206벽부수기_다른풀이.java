package swea;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class boj2206벽부수기_다른풀이 {

	static int[][] map;
	static int[][][] visited;
	static int n, m, ans;
	static int[] dx = { 1, -1, 0, 0 };
	static int[] dy = { 0, 0, 1, -1 };

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		m = sc.nextInt();

		map = new int[n][m];
		visited = new int[n][m][2];

		ans = 987987987;
		for (int i = 0; i < n; i++) {
			String str = sc.next();
			for (int j = 0; j < m; j++) {
				map[i][j] = str.charAt(j) - '0';

			}
		}

		ans=bfs();
		System.out.println(ans);
	}

	static class Point {
		int x, y, b;

		public Point(int x, int y, int b) {
			super();
			this.x = x;
			this.y = y;
			this.b = b;
		}

	}

	static int bfs() {
		Queue<Point> q = new LinkedList();
		q.add(new Point(0, 0, 0));
		visited[0][0][0] = 1;

		while (!q.isEmpty()) {
			int x = q.peek().x;
			int y = q.peek().y;
			int b = q.peek().b;
			q.poll();

			if (x == n - 1 && y == m - 1) {
				return visited[x][y][b];
			}

			for (int i = 0; i < 4; i++) {

				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx >= n || ny >= m || nx < 0 || ny < 0)
					continue;

				if (visited[nx][ny][b] > 0)
					continue;

				if (map[nx][ny] == 0) {
					visited[nx][ny][b] = visited[x][y][b] + 1;
					q.add(new Point(nx, ny, b));
				}

				if (map[nx][ny] == 1 && b == 0) {

					visited[nx][ny][1] = visited[x][y][b] + 1;
					q.add(new Point(nx, ny, 1));
				}

			}
		}
		return -1;

	}
}
