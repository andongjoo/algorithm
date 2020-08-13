package swea;

import java.util.Scanner;

public class boj1541잃어버린괄호 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String str = sc.next();

		int cur = 0;
		int ans = 0;
		int sign = 1;
		for (int i = 0; i < str.length(); i++) {
			if (str.charAt(i) == '+') {
				ans += cur;
				cur = 0;
			} else if (str.charAt(i) == '-') {
				sign = -1;
				ans += cur;
				cur = 0;

			} else {

				cur = (10 * cur) + (str.charAt(i) - '0') * sign;
			}
		}
		ans += cur;
		System.out.println(ans);
	}

}
