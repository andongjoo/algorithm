package swea;

import java.util.Scanner;

public class ladder1 {

	static int[] dx = { 0, 1, -1, 0 };
	static int[] dy = { 1, 0, 0, -1 };
	static final int N=100;
	static int[][] arr;
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		

		for (int t = 1; t <= 10; t++) {
			int TC = sc.nextInt();
			arr=new int [N][N];
			int ans=0;
			
			for(int i=0;i<N;i++)
			{
				for(int j=0;j<N;j++)
				{
					arr[i][j]=sc.nextInt();
				}
			}
			
			for(int i=0;i<N;i++)
			{
				if(arr[0][i]==1) {
					if(go(0,i)==true)
					{	ans=i;
						break;
					}
				}
			}
			
			
			
			
			
			System.out.printf("#%d %d\n",TC,ans);
		}
	}
	
	public static boolean go(int r,int c) {
		
		int x=r,y=c;
		
		while(x<100 && y<100)
		{
			if(arr[x][y]==2)
				return true;
			
			if(y+1<100 && arr[x][y+1]==1)
			{
				while(true)
				{
					y++;
					if(arr[x+1][y]==1) {
						x++;
						break;
					}
					
				}
				
				
			}else if (y-1>=0 && arr[x][y-1]==1) {
				while(true)
				{
					y--;
					if(arr[x+1][y]==1) {
						x++;
						break;
					}
					
				}
			}else {
				x++;
			}
			
		}
		
		
		return false;
	}

}
