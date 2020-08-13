package swea;
import java.util.Scanner;
import java.util.Arrays;

public class permutation {

	private static int N,R;
	private static int[] numbers;
	private static int[] input;
	private static boolean[] isSelected;

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);
		
		N=sc.nextInt(); R=sc.nextInt();
		numbers = new int[N];
		input = new int [N];
		
		isSelected=new boolean[N+1];
		
		for(int i=0;i<N;i++)
			input[i]=sc.nextInt();
		
		perm(0,0);
	}
	
	private static void perm(int cnt,int start) {
		
		if(cnt==R)
		{
				System.out.println(Arrays.toString(numbers));
//			System.out.println();
			return;
		}
		
		for(int i=start;i<N;i++) {
			
			numbers[cnt]=input[i];
			perm(cnt+1,i+1);
			
			
		}
		
	}
	

}
