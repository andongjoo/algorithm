package swea;
import java.util.Arrays;
import java.util.Scanner;
public class 부분수열의합2817 {
	static int N,M,ans;
	static int[] arr;
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int TC=sc.nextInt();
		for (int t = 1; t <= TC; t++) {
			N = sc.nextInt();
			M=sc.nextInt();
			ans = 0;
			arr = new int[N];
			for (int i = 0; i < N; i++)
				arr[i] = sc.nextInt();
			
			comb(0,0);
			System.out.printf("#%d %d\n", t, ans);

		}
	}
	
	private static void comb(int index,int sum) {
		
		if(sum==M)
		{
			ans++;
			return;
		}
		
		if(index==N)
			return;
		
		comb(index+1,sum+arr[index]);
		comb(index+1,sum);
		
	}

}
