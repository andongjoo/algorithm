#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
    int tc;

    cin>>tc;

    for(int t=0;t<tc;t++){
        int x1, x2, y1, y2, r1, r2, ret;
        cin>>x1>>y1>>r1;
        cin>>x2>>y2>>r2;

        double d = sqrt((x2-x1)*(x2-x1)+ (y1-y2)*(y1-y2));
        int sm = abs(r1-r2);
        int big = r1+r2; 

        if(d == 0.0){
            if(r1 == r2)
                ret = -1;
            else
                ret = 0;
        }else{
            if(sm < d && big > d)
                ret = 2;
            else if(big == d || sm == d)
                ret = 1;
            else
                ret = 0;
        }
        printf("%d\n",ret);
    }
 return 0;   
}
