package swea;

import java.util.Scanner;

public class 상호의배틀필드 {

	static int dr[] = { 1, -1, 0, 0 };
	static int dc[] = { 0, 0, -1, 1 };

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int TC = sc.nextInt();
		for (int t = 1; t <= TC; t++) {
			int H, W;
			H = sc.nextInt();
			W = sc.nextInt();
			char[][] map = new char[H][W];
			int r = 0, c = 0;
			for (int i = 0; i < H; i++) {
				String str = sc.next();
				for (int j = 0; j < str.length(); j++) {
					{
						map[i][j] = str.charAt(j);
						if (map[i][j] == '<' || map[i][j] == '^' || map[i][j] == 'v' || map[i][j] == '>') {
							r = i;
							c = j;
						}
					}

				}
			}

//			for(int i=0;i<H;i++)
//			{
//				for(int j=0;j<W;j++) {
//					System.out.printf("%c ",map[i][j]);
//				}System.out.println();
//			}System.out.println();
			
			int dir = 0;
			if (map[r][c] == 'v') {
				dir = 0;
			} else if (map[r][c] == '^') {
				dir = 1;
			} else if (map[r][c] == '<') {
				dir = 2;
			} else if (map[r][c] == '>') {
				dir = 3;
			}

			int N = sc.nextInt();
			String s = sc.next();
			for (int i = 0; i < N; i++) {

				if (s.charAt(i) == 'U') {
					dir = 1;
					map[r][c] = '^';
				} else if (s.charAt(i) == 'D') {
					dir = 0;
					map[r][c] = 'v';
				} else if (s.charAt(i) == 'L') {
					dir = 2;
					map[r][c] = '<';
				} else if (s.charAt(i) == 'R') {
					dir = 3;
					map[r][c] ='>';
				}

				int nr = r + dr[dir];
				int nc = c + dc[dir];

				if (nr >= H || nr < 0 || nc >= W || nc < 0)
					continue;

				if (s.charAt(i) == 'U') {
					dir = 1;
					if (map[nr][nc] == '.') {

						map[r][c]='.';
						r = nr;
						c = nc;
						map[nr][nc]='^';
					}
				} else if (s.charAt(i) == 'D') {
					dir = 0;
					if (map[nr][nc] == '.') {

						map[r][c]='.';
						r = nr;
						c = nc;
						map[nr][nc]='v';
					}
				} else if (s.charAt(i) == 'L') {
					dir = 2;
					if (map[nr][nc] == '.') {

						map[r][c]='.';
						r = nr;
						c = nc;
						map[nr][nc]='<';
					}
				} else if (s.charAt(i) == 'R') {
					dir = 3;
					if (map[nr][nc] == '.') {
						map[r][c]='.';
						r = nr;
						c = nc;
						map[nr][nc]='>';
					}
				} else if (s.charAt(i) == 'S') {
					int shr=nr;
					int shc=nc;
					while(true) {
						
						if(shr >= H || shr < 0 || shc >= W || shc < 0)
							break;
						
						if(map[shr][shc]=='#') {
								break;
						}
						
						
						if(map[shr][shc]=='*') {
							map[shr][shc]='.';
								break;
						}
						
						
						shr=shr +dr[dir];
						shc=shc+dc[dir];
						
					}
//					if (map[nr][nc] == '*') {
//						map[nr][nc] = '.';
//					}
				}
			}
			System.out.printf("#%d ",t);
			for(int i=0;i<H;i++)
			{
				for(int j=0;j<W;j++) {
					System.out.printf("%c",map[i][j]);
				}System.out.println();
			}System.out.println();
			
		}
	}

}
