package swea;

import java.util.Base64;
import java.util.Scanner;
import java.util.Base64.Decoder;

public class Base64Decoder {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		
		int TC = sc.nextInt();
		for (int t = 1; t <= TC; t++) {

			String str=sc.next();
			String str2=new String(Base64.getDecoder().decode(str));
			
			System.out.printf("#%d %s\n",t,str2);
		}

	}

}
