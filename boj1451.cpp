#include <iostream>
using namespace std;
 
int n, m, a[101][101];
long long Max = 0;
 
long long sum(int sx, int sy, int ex, int ey) {
    long long ret = 0;
    for (int i = sy; i <= ey; i++) {
        for (int j = sx; j <= ex; j++) {
            ret += a[i][j];
        }
    }
    return ret;
}
 
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char tmp;
            cin >> tmp;
            a[i][j] = tmp-'0';
        }
    }
 
    // 1번 case
    for (int i = 0; i < m-2; i++) {
        for (int j = i + 1; j < m - 1; j++) {
            long long a = sum(0, 0, i, n - 1);
            long long b = sum(i+1, 0, j, n - 1);
            long long c = sum(j+1, 0, m - 1, n-1);
            if (Max < a*b*c)
                Max = a*b*c;
        }
    }
    // 2번 case
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            long long a = sum(0, 0, m-1, i);
            long long b = sum(0, i+1, m-1, j);
            long long c = sum(0, j+1, m - 1, n - 1);
            if (Max < a*b*c)
                Max = a*b*c;
        }
    }
    // 3번 case
    for (int i = 0; i < m - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            long long a = sum(0, 0, i, n-1);
            long long b = sum(i+1,0,m-1,j);
            long long c = sum(i+1,j+1,m-1,n-1);
            if (Max < a*b*c)
                Max = a*b*c;
        }
    }
    // 4번 case
    for (int i = m-1; i > 0; i--) {
        for (int j = 0; j < n - 1; j++) {
            long long a = sum(i,0,m-1,n-1);
            long long b = sum(0,0,i-1,j);
            long long c = sum(0,j+1,i-1,n-1);
            if (Max < a*b*c)
                Max = a*b*c;
        }
    }
    // 5번 case
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 1; j++) {
            long long a = sum(0,0,m-1,i);
            long long b = sum(0,i+1,j,n-1);
            long long c = sum(j+1,i+1,m-1,n-1);
            if (Max < a*b*c)
                Max = a*b*c;
        }
    }
    // 6번 case
    for (int i = n-1; i > 0; i--) {
        for (int j = 0; j < m - 1; j++) {
            long long a = sum(0,i,m-1,n-1);
            long long b = sum(0,0,j,i-1);
            long long c = sum(j+1,0,m-1,i-1);
            if (Max < a*b*c)
                Max = a*b*c;
        }
    }
    cout << Max << '\n';
    return 0;
}

