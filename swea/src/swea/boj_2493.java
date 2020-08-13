package swea;

import java.util.Stack;
import java.util.StringTokenizer;
import java.io.*;


	
public class boj_2493 {

	static int n;
	static int[] arr;

	public static void main(String[] args) throws NumberFormatException, IOException {
	
	
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());
		
		arr = new int[n + 1];
		int[] ans = new int[n + 1];
		Stack<Integer> stck = new Stack<>();
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		
		for (int i = 1; i <= n; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		
		stck.push(1);
		System.out.print("0 ");
		  
		int index = 2;
		while (index <= n) {
			if (stck.isEmpty()) {
				System.out.print("0 ");
				stck.push(index);
				index++;
			} else if (arr[stck.peek()] > arr[index]) {
			
				System.out.print(stck.peek()+" ");
				stck.push(index);
				index++;
			} else {
				stck.pop();

			}
		}


	}
}
