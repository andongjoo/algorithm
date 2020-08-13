package swea;
import java.util.Scanner;
public class 준환이의운동관리_3431 {
	static int L,U,X,ans;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int TC=sc.nextInt();
		for(int t=1;t<=TC;t++) {
			L=sc.nextInt();
			U=sc.nextInt();
			X=sc.nextInt();
			ans=-1;
			
			if(X>=L && X<=U)
				ans=0;
			else if (X<L)
				ans= L-X;
			
			System.out.printf("#%d %d\n",t,ans);
		}
		

	}

}
