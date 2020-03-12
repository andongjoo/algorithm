#include <iostream>
#include <cmath>
using namespace std;

double get_len(double ax,double ay,double bx,double by)
{
	
	return sqrt( (ax-bx)*(ax-bx)+(ay-by)*(ay-by));
}

int main(int argc, char** argv) {
	
	
	
	int ax,ay,bx,by,cx,cy,dx,dy;
	
	cin>>ax>>ay>>bx>>by>>cx>>cy>>dx>>dy;
	


	double sa,ea,sb,se;
	
	double f1=get_len(ax,ay,cx,cy);
	double f2=get_len(bx,by,dx,dy);
	
	
	
	return 0;
}
