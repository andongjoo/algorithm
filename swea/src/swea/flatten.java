package swea;

import java.util.Scanner;
import java.util.Arrays;

public class flatten {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);	
//		int TC=sc.nextInt();
		
		for(int t=1;t<=10;t++) {
			
			int n = sc.nextInt();
			
			int[] arr=new int[100];
			for(int i=0;i<100;i++)
			{
				arr[i]=sc.nextInt();
			}
			
			for(int i=0;i<n;i++)
			{
			Arrays.sort(arr);
			arr[0]++;
			arr[99]++;
			
			}
			
			
			System.out.printf("#%d %d\n",t,arr[99]-arr[0]);
		}
		
		

	}

}
