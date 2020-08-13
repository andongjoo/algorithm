package swea;

import java.util.Scanner;

public class 백만장자프로젝트_1895 {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		int TC=sc.nextInt();
		for(int T=1;T<=TC;T++)
		{
			long ans=0;
			int N=sc.nextInt();
			int[] day = new int[N];
			for(int i=0;i<N;i++)
			{
				day[i]=sc.nextInt();
			}
			

			long sum=0;
			int max=day[N-1];
			for(int i=N-2;i>=0;i--)
			{
				if(max>day[i])
				{
					sum+=(long)(max-day[i]);
				}else if(max<day[i])
				{
					max=day[i];
				}
				
				ans=Math.max(ans,(long) sum);
			}
			
			
			System.out.printf("#%d %d\n",T,ans);
			
		}
		
	}

}
