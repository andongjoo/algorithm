

import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class boj회의실배정 {
	static int n, ans;
	static meeting []arr;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		arr =new meeting[n];
//		for(int i=0;i<n;i++)
//			arr[i]=new meeting;
		
		for (int i = 0; i < n; i++) {
			int s,e;
			s=sc.nextInt();
			e=sc.nextInt();
			arr[i]= new meeting(s,e);
		}
		
		int time = 0;
		ans=0;
		Arrays.sort(arr,new meetingcompare());
		for(int i=0;i<n;i++) {
			
			if(arr[i].s>=time)
			{
				ans++;
				time=arr[i].e;
			}
		}
		System.out.println(ans);
	}

	static class meeting implements Comparable<meeting> {
		int s, e;

		public meeting(int s, int e) {
			super();
			this.s = s;
			this.e = e;
		}
		
		@Override
        public int compareTo(meeting o) {
            
            int time = e - o.e;
            // 종료시간이 틀리면
            if(time != 0){ 
                return time;
            }
            // 종료시간이 같으면 시작시간이 빠른 순
            return s - o.s; 
        }

	}
	
	static class meetingcompare implements Comparator<meeting> {
		public int compare(meeting a, meeting b) {
			if (a.e == b.e) {
				return a.s - b.s;

			} else {
				return a.e - b.e;
			}
		}
		
	}
}
