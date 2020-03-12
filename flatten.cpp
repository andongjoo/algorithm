#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
    for(int t=1;t<=10;t++)
        {
	        int n;
	        cin>>n;
	        vector<int> v;
	      
	        for(int i=0;i<100;i++)
	        {
			
	         	int a;
	            cin>>a;
	            v.push_back(a);
	    	}
	    	
	    	
//	        for(int i=0;i<v.size();i++)
//	        	printf("%d ",v[i]);
//	        printf("\n");
//			printf("º¤ÅÍ»çÀÌÁî %d\n",v.size());
	        
	        
	        for(int k=0;k<n;k++)
			{
				int big=-1;
	        int small=100000;
	        int index1;
	        int index2;
	    		for(int i=0;i<v.size();i++)
				{
					if(big<=v[i])
					{
						big=v[i];
						index1=i;
					}
					
					
					if(small>=v[i])
					{
						small=v[i];
						index2=i;
					}
				}
				v[index1]--;
				v[index2]++;
				
//				printf("#%d   index1:%d value:%d   index2:%d  %d\n",k+1,index1,v[index1],index2,v[index2]);
			}
			
			int b=v[0];
			int s=v[0];
			for(int i=0;i<v.size();i++)
				{
					b=max(b,v[i]);
					s=min(s,v[i]);
				}
//				for(int i=0;i<v.size();i++)
//					printf("%d ",v[i]);
			printf("\n%d %d\n",b,s);	
			printf("#%d %d\n",t,b-s);
			v.clear();	
		}
    	
	return 0;
}
