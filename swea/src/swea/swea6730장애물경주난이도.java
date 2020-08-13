package swea;
import java.util.Scanner;

public class swea6730장애물경주난이도 {
	static int []map;
	static int n;
	public static void main(String[] args) {
		Scanner sc =new Scanner(System.in);
		int tc=sc.nextInt();
		
		for(int t=1;t<=tc;t++)
		{
			int max=0,min=0;
			n=sc.nextInt();
			map=new int[n];
			for(int i=0;i<n;i++)
				map[i]=sc.nextInt();
			
			for(int i=0;i<n-1;i++)
			{
				if(map[i]>map[i+1])
				{
					min= Math.max(map[i]-map[i+1], min);
				}
				if (map[i]<map[i+1]) {
					max=Math.max(max, map[i+1]-map[i]);
				}
			}
			
			
			System.out.printf("#%d %d %d\n",t,max,min);
		}
	}

}
