package swea;

import java.util.Arrays;
import java.util.Scanner;

public class 최고의쌍9839 {

	static int N, ans;
	static int[] arr;

	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int tc = sc.nextInt();
		
		for (int t = 1; t <= tc; t++) {
			N = sc.nextInt();
			ans = -1;
			arr = new int[N];
			for (int i = 0; i < N; i++)
				arr[i] = sc.nextInt();
			Arrays.sort(arr);
			for (int i = 0; i < N - 1; i++) {
				for (int j = i + 1; j < N; j++) {
					int num = arr[i] * arr[j];
					boolean flag = true;
					int temp = num;  // 12345
					num/=10;   // 1234
					
					while (num > 0) {
						if (temp%10 - 1 != num % 10) {   // 5 와 4를 비교
							flag = false;
							break;
						}
						temp/=10;
						num /= 10;
					}

					if (flag == false) //연속된숫자가 아니라면 continue;
						continue;
					ans = Math.max(ans, arr[i] * arr[j]);
				}
			}
			System.out.printf("#%d %d\n", t, ans);

		}
	}

}
