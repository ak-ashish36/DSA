//https://takeuforward.org/data-structure/nth-root-of-a-number-using-binary-search/
#include <bits/stdc++.h>
using namespace std;
double multiply(double number, int n) {
    double ans = 1.0;
    for(int i = 1;i<=n;i++) {
        ans = ans * number;
    }
    return ans; 
}

void getNthRoot(int n, int m) {
    double start = 1;
    double end = m;
    double eps = 1e-6; 
    
    while((end - start) > eps) {
        double mid = (start + end) / 2.0;

        if(multiply(mid, n) > m) {
            end = mid;    
        }
        else {
            start = mid;
        }
    }
    
    cout <<n<<"th root of "<<m<<" is "<<start<<endl;   
}
int squareroot(int x){
    if (x == 0) return 0;
    int start = 1, end = x, ans;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (mid > x / mid) {       //mid*mid > x
            end = mid-1;
        } else {
            ans = mid;
            start = mid+1;
        }
    }
    return ans;
}
int main() {
	int n=3, m=27; 
	getNthRoot(n, m); 
    cout<<squareroot(5);
	return 0;
}