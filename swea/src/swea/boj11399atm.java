package swea;

import java.util.Arrays;
import java.util.Scanner;

public class boj11399atm {

	static Person[] arr;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n;

		n = sc.nextInt();

		arr = new Person[n];
		for(int i=0;i<n;i++)
		{
			int time=sc.nextInt();
			
			arr[i]=new Person(i,time);
		}
		
		Arrays.sort(arr);
		int ans=0;
		int cnt=n;
	
		for(int i=0;i<n;i++)
		{
			ans+=(cnt*arr[i].time);
			cnt--;
		}
		System.out.println(ans);
		


	}

	static class Person implements Comparable<Person> {

		int index, time;

		public Person(int index, int time) {
			super();
			this.index = index;
			this.time = time;
		}

		public int compareTo(Person p) {
			return this.time - p.time;
		}
	}
}
