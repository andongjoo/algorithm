package swea;

import java.util.Arrays;
import java.util.Scanner;

public class repermutation {
	static int N,R;
	static int[] numbers;
	static boolean[] isSelected;
	static int []input;
	
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);
		
		N=sc.nextInt(); R=sc.nextInt();
		numbers = new int[N];
		input = new int [N];
		
		isSelected=new boolean[N+1];
		
		for(int i=0;i<N;i++)
			input[i]=sc.nextInt();
		
		reperm(0,0);
	}
	private static void reperm(int index,int k) {
		
		if(k==R) {
			
			System.out.println(Arrays.toString(numbers));
			
			return;
		}
		
		if(index==N)
		{
			return;
		}
		
		for(int i=0;i<numbers.length;i++)
		{
			if(!isSelected[i])
			{
				isSelected[i]=true;
				numbers[index]=input[i];
				reperm(index+1,k+1);
				isSelected[i]=false;
			}
		}
		
	}
	
	
}