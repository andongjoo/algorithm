import java.util.Arrays;
import java.util.Scanner;

public class boj1041주사위 {

	static long n, one, two, three;
	static long arr[];

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		arr = new long[6];
		one = 987987987;
		two = 987987987;
		three = 987987987;

		for (int i = 0; i < 6; i++) {
			arr[i] = sc.nextLong();
			one = Math.min(one, arr[i]);
		}

		for (int i = 0; i < 5; i++) {
			for (int j = i + 1; j < 6; j++) {

				if (i == 0 && j == 5)
					continue;
				if (i == 1 && j == 4)
					continue;
				if (i == 2 && j == 3)
					continue;

				two = Math.min(two, arr[i] + arr[j]);

			}
		}
		for (int i = 0; i < 4; i++) {
			for (int j = i + 1; j < 5; j++) {
				for (int k = j + 1; k < 6; k++) {
					if (i == 0 && (k == 5 || (j == 1 & k == 4) || (j == 2 && k == 3)))
						continue;
					if (i == 1 && (k == 4 || j == 4 || (j == 2 && k == 3)))
						continue;
					if (i == 2 && (j == 3))
						continue;
					three = Math.min(three, arr[i] + arr[j] + arr[k]);

				}
			}
		}
		long sum = 0;

		if (n == 1) {

			Arrays.sort(arr);
			for (int i = 0; i < 5; i++) {
				sum += arr[i];
			}

		} else if (n == 2) {
			sum = (two * 4) + (three * 4);

		} else {
			sum = ((5 * n * n - 16 * n + 12) * one);
			sum += ((8 * n - 12) * two);
			sum += (three * 4);
		}

		System.out.println(sum);
	}

}
