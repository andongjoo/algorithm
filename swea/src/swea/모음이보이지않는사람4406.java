package swea;

import java.util.Scanner;

public class 모음이보이지않는사람4406 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int TC=sc.nextInt();
		for(int t=1;t<=TC;t++) {
			String str=sc.next();
		
			System.out.printf("#%d ",t);
			for(int i=0;i<str.length();i++)
			{
				if(str.charAt(i)!='o' && str.charAt(i)!='i' && str.charAt(i)!='a' && str.charAt(i)!='e' && str.charAt(i)!='u' )
					System.out.print(str.charAt(i));
			}System.out.println();
			
			
		}
		

	}

}
