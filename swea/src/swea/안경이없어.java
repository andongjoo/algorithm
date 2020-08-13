package swea;

import java.util.Scanner;

public class 안경이없어{

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int TC = sc.nextInt();
		for (int T = 1; T <= TC; T++) {
			String str1 = "", str2 = "";
			String str3 = "", str4 = "";
			str1 = sc.next();
			str2 = sc.next();
			String ans = "DIFF";

			if (str1.length() == str2.length()) {
				for (int i = 0; i < str1.length(); i++) {
					if (str1.charAt(i) == 'A' || str1.charAt(i) == 'D' || str1.charAt(i) == 'O' || str1.charAt(i) == 'P'
							|| str1.charAt(i) == 'Q' || str1.charAt(i) == 'R') {
						str3 += '1';
					} else if (str1.charAt(i) == 'B')
						str3 += '2';
					else
						str3 += '0';

					if (str2.charAt(i) == 'A' || str2.charAt(i) == 'D' || str2.charAt(i) == 'O' || str2.charAt(i) == 'P'
							|| str2.charAt(i) == 'Q' || str2.charAt(i) == 'R') {
						str4 += '1';
					} else if (str2.charAt(i) == 'B')
						str4 += '2';
					else
						str4 += '0';

				}
				if (str3.equals(str4))
					ans = "SAME";
			}

			System.out.printf("#%d %s\n", T, ans);

		}

	}

}
