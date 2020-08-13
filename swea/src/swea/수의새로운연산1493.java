package swea;



import java.util.Scanner;

public class 수의새로운연산1493 {
	static int[][] arr;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int TC = sc.nextInt();
		arr = new int[301][301];
		int x = 0, y = 0, idx = 1;
		for (int i = 0; i < 301; i++) {
			x = i;
			y = 0;
			for (int j = 0; j <= i; j++) {
				arr[x][y] = idx++;
				x--;
				y++;

			}
		}


		for (int i = 0; i < 10; i++) {
			
			for (int j = 0; j <10; j++) {
				System.out.print(arr[i][j]+" ");
			}System.out.println();
		}
		

		for (int t = 1; t <= TC; t++) {
			int nx = 0, ny = 0;
			int p = sc.nextInt();
			int q = sc.nextInt();
			int x1=0,x2=0,y1=0,y2=0;
			for (int i = 0; i <= 300; i++) {
				for (int j = 0; j <= 300; j++) {
					if (arr[i][j] == p ) {
						x1 = i;
						y1 = j;
					}
					if ( arr[i][j] == q) {
						x2 = i;
						y2 = j;
					}

				}
			}
			nx=x1+x2;
			ny=y1+y2;
			System.out.println(nx+" "+ny);
			System.out.printf("#%d %d\n", t, arr[nx+1][ny+1]);

		}
		
		

	}

}
