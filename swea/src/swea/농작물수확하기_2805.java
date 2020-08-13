package swea;

import java.util.Scanner;

public class 농작물수확하기_2805 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc= new Scanner(System.in);
		int TC=sc.nextInt();
		for(int t=1;t<=TC;t++)
		{
			int ans=0,N;
			N=sc.nextInt();
			int[][] map = new int[N][N];
			
			for(int i=0;i<N;i++)
			{
				String str = sc.next();
				for(int j=0;j<N;j++)
				{

					map[i][j]=str.charAt(j)-'0';
				}
			}
			
			int s=N/2;
			int e=N/2;
			
			for(int i=0;i<N;i++)
			{
				for(int j=s;j<=e;j++)
				{
					ans+=map[i][j];
				}
				
				if(i <N/2)
				{
					s--;
					e++;
				}else{
					s++;
					e--;
				}
			}
			
			
			System.out.printf("#%d %d\n",t,ans);
		}
		
	}

}
