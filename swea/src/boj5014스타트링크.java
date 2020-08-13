import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class boj5014스타트링크 {

	static int[] visited;
	static int F, S, G, U, D;

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		F = sc.nextInt();
		S = sc.nextInt();
		G = sc.nextInt();
		U = sc.nextInt();
		D = sc.nextInt();
		visited = new int[1000001];
		Arrays.fill(visited, -1);
		Queue<Integer> q = new LinkedList<>();
		q.add(S);
		visited[S] = 0;
		int ans = 987987987;
		while (!q.isEmpty()) {

			int cur = q.peek();
			q.poll();

			if (cur == G) {
				System.out.println(visited[G]);
				System.exit(0);

			}

			int[] dir = { U, -1 * D };

			for (int i = 0; i < 2; i++) {
				int next = cur + dir[i];

				if (next > F || next < 1)
					continue;

				if (visited[next] !=-1)
					continue;

				visited[next] = visited[cur] + 1;
				q.add(next);

			}

		}

		System.out.println("use the stairs");
	}

}
