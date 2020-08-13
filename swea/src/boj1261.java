import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class boj1261 {
	static int n, m;
	static int[][] dist, map;
	static int dx[] = { 1, -1, 0, 0 };
	static int dy[] = { 0, 0, 1, -1 };

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		m = sc.nextInt();
		n = sc.nextInt();

		map = new int[n][m];
		dist = new int[n][m];

		for (int i = 0; i < n; i++) {
			String str = sc.next();
			for (int j = 0; j < m; j++) {
				map[i][j] = str.charAt(j) - '0';
				dist[i][j] = 987987987;
			}
		}
		bfs();
		System.out.println(dist[n - 1][m - 1]);
	}

	static void bfs() {
		Queue<Point> q = new LinkedList<>();
		q.add(new Point(0, 0));
		dist[0][0] = 0;

		while (!q.isEmpty()) {

			int x = q.peek().x;
			int y = q.peek().y;
			q.poll();
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx >= n || ny < 0 || ny >= m || nx < 0)
					continue;

				if (map[nx][ny] == 0 && dist[nx][ny] > dist[x][y]) {
					dist[nx][ny] = dist[x][y];
					q.add(new Point(nx, ny));
				}

				if (map[nx][ny] == 1 && dist[nx][ny] > dist[x][y] + 1) {
					q.add(new Point(nx, ny));
					dist[nx][ny] = dist[x][y] + 1;
				}

			}

		}

	}

	static class Point {
		int x, y;

		public Point(int x, int y) {
			super();
			this.x = x;
			this.y = y;
		}

	}

}
