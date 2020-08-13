package swea;

import java.util.Scanner;
import java.io.FileInputStream;

/*
   사용하는 클래스명이 Solution 이어야 하므로, 가급적 Solution.java 를 사용할 것을 권장합니다.
   이러한 상황에서도 동일하게 java Solution 명령으로 프로그램을 수행해볼 수 있습니다.
 */
class 재미있는오셀로게임 {
	static int[] dr = { 1, -1, 0, 0, 1, 1, -1, -1 };
	static int[] dc = { 0, 0, 1, -1, -1, 1, -1, 1 };
	static int N, d;
	static int[][] map;
	static int[][] visit;

	public static void main(String args[]) throws Exception {
		Scanner sc = new Scanner(System.in);

		int TC = sc.nextInt();
		for (int t = 1; t <= TC; t++) {

			int M;
			N = sc.nextInt();
			M = sc.nextInt();
			map = new int[N + 1][N + 1];
			visit = new int[N + 1][N + 1];
			map[N / 2][N / 2] = 2;
			map[N / 2 + 1][N / 2 + 1] = 2;
			map[N / 2 + 1][N / 2] = 1;
			map[N / 2][N / 2 + 1] = 1;

			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= N; j++) {
					visit[i][j] = 0;
				}
			}

			for (int k = 0; k < M; k++) {
				int r, c;
				r = sc.nextInt();
				c = sc.nextInt();
				d = sc.nextInt();

				for (int i = 0; i < 8; i++) {
					int nr = r + dr[i];
					int nc = c + dc[i];
					if (nr > N || nr <= 0 || nc > N || nc <= 0) {
						continue;
					}

					if (map[nr][nc] != 0 && map[nr][nc] != d) {

						map = go(r, c, i);

					}

				}

			}

			int b = 0, w = 0;
			for (int i = 1; i <= N; i++) {
				for (int j = 0; j <= N; j++) {
					if (map[i][j] == 1) {
						b++;
					} else if (map[i][j] == 2) {
						w++;
					}
				}
			}

			System.out.printf("#%d %d %d\n", t, w, b);
		}
	}

	public static int[][] go(int r, int c, int dir) {

		int x = r, y = c;
		int[][] tmp = new int[N + 1][N + 1];
		int[][] tmp2 = new int[N + 1][N + 1];

		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				tmp2[i][j] = map[i][j];
		System.arraycopy(map, 0, tmp, 0, map.length);

		tmp[r][c] = d;

		while (true) {
			int nr = r + dr[dir];
			int nc = c + dc[dir];

			if (nr > N || nr <= 0 || nc > N || nc <= 0) {
				return tmp2;
			}

			if (tmp[nr][nc] == 0) {

				return tmp2;
			}

			if (tmp[nr][nc] == d) {
				tmp[x][y] = d;
				return tmp;
			}
			tmp[nr][nc] = d;
			r = nr;
			c = nc;

		}

	}
}