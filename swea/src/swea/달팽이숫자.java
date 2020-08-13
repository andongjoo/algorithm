package swea;

import java.util.Scanner;

public class 달팽이숫자 {

	static int[] dx = { 0, 1, 0, -1 };
	static int[] dy = { 1, 0, -1,0 };
	static int N;
	static int[][] arr;
	
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		int TC = sc.nextInt();

		for (int t = 1; t <= TC; t++) {
			N = sc.nextInt();
			arr = new int[N][N];

			go(0,0,0,1);
			System.out.println("#" + t);
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					System.out.printf("%d ", arr[i][j]);
				}
				System.out.println();
			}
		}

	}
	
	public static void go(int x,int y,int dir,int num) {
		
		arr[x][y]=num;
		int nx=x+dx[dir];
		int ny=y+dy[dir];
		
		
		if(num==N*N)
		{
			return;
		}
		
		if(dir==0)
		{
			if(ny>=N)
				go(x+1,y,1,num+1);
			else if (arr[nx][ny]>0)
				go(x+1,y,1,num+1);
			else
				go(nx,ny,dir,num+1);
			
		}else if (dir==1) {
			if(nx>=N)
				go(x,y-1,2,num+1);
			else if (arr[nx][ny]>0)
				go(x,y-1,2,num+1);
			else
				go(nx,ny,dir,num+1);
			
		}else if (dir==2) {
			if(ny<0)
				go(x-1,y,3,num+1);
			else if (arr[nx][ny]>0)
				go(x-1,y,3,num+1);
			else
				go(nx,ny,dir,num+1);
		}else if (dir==3) {
			if(nx<0)
				go(x,y+1,0,num+1);
			else if (arr[nx][ny]>0)
				go(x,y+1,0,num+1);
			else
				go(nx,ny,dir,num+1);
		}
		
	
	}
	

}
