package swea;

import java.util.Scanner;
import java.util.Queue;
import java.util.LinkedList;

public class 암호생성기 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		for(int t=1;t<=10;t++)
		{
			Queue<Integer> q=new LinkedList();
			int tc=sc.nextInt();
			for(int i=0;i<8;i++)
			{
				int item=sc.nextInt();
				q.offer(item);
			}
			
			while(true)
			{
				int item=0;
				for(int i=1;i<=5;i++)
				{
//					System.out.printf("item:%d ",item);
					item=q.peek();
					item-=i;
					item= item>0? item:0;
//					System.out.printf("item:%d\n",item);
					q.poll();
					q.offer(item);
					
					if(item==0)
						break;
				}
				if(item==0)
					break;
			}
			System.out.printf("#%d ",t);
			while(!q.isEmpty())
			{
				System.out.print(q.poll()+" ");
			}System.out.println();
		}
		
		
	}

}
