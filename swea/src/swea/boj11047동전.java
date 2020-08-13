package swea;

import java.util.Scanner;

public class boj11047동전 {

	static int[] arr;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n, money;

		n = sc.nextInt();
		money = sc.nextInt();
		arr =new int[n];
		for (int i = 0; i < n; i++) {
			arr[i] = sc.nextInt();
		}
		int index = n - 1;
		int ans = 0;
		while (money > 0) {
			
			if (money >= arr[index]) {
				ans += money / arr[index];
				money = (money % arr[index]);
				
			}
			index--;
//			System.out.println(money);
		}

		System.out.println(ans);
	}

}
