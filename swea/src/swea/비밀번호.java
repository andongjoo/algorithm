package swea;

import java.util.Scanner;
import java.util.Stack;

public class 비밀번호 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		for (int T = 1; T <= 10; T++) {
			String ans = "";
			int N = sc.nextInt();
			String str = sc.next();
			Stack<Character> stck = new Stack();

			for (int i = N - 1; i >= 0; i--) {
				if (!stck.isEmpty() && stck.peek() == str.charAt(i)) {
					stck.pop();
				} else {
					stck.push(str.charAt(i));
				}
			}

			while (!stck.isEmpty()) {
				ans += stck.peek();
				stck.pop();
			}

			System.out.printf("#%d %s\n", T, ans);
		}

	}

}
