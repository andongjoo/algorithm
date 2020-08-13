package swea;
import java.util.Scanner;

public class swea10032과자분배 {
	static int []map;
	static int n,k,ans;
	public static void main(String[] args) {
		Scanner sc =new Scanner(System.in);
		int tc=sc.nextInt();
		
		for(int t=1;t<=tc;t++)
		{
			n=sc.nextInt();
			k=sc.nextInt();
			ans=987987987;
			
			if(n%k==0) {
				ans=0;
			}else
				ans=1;
			
			System.out.printf("#%d %d\n",t,ans);
		}
	}

	
}
