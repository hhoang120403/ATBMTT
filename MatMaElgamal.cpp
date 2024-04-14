#include<bits/stdc++.h>
using namespace std;

int sqr(int x) {
    return x*x;
}

int lthua(int a, int b, int MOD) {
    if (b == 0) return 1 % MOD;
    else
        if (b % 2 == 0)
            return sqr(lthua(a, b/2, MOD)) % MOD;
        else
            return a * (sqr(lthua(a, b/2, MOD)) % MOD) % MOD;
}

int nghichDao(int a, int n){
    int Q,A1 = 1,A2 = 0,A3 = n,B1 = 0,B2 = 1,B3 = a;
	
	while(B3 != 0 && B3 != 1){
		Q = A3 / B3;
		
		int B1_cp = B1,B2_cp = B2,B3_cp = B3;
		
		B1 = A1 - B1 * Q;
		B2 = A2 - B2 * Q;
		B3 = A3 - B3 * Q;
		
		A1 = B1_cp;
		A2 = B2_cp;
		A3 = B3_cp;
	}
	if(B3 == 1){
	    if(B2 < 0) return (B2 + n);
	    return B2;
	}
	return -1;
}

int main(){
	int q,a,x,k,M;
	
	cout << "Nhap q: ";
	cin >> q;
	cout << "Nhap a: ";
	cin >> a;
	cout << "Nhap x: ";
	cin >> x;
	cout << "Nhap k: ";
	cin >> k;
	cout << "Nhap M: ";
	cin >> M;
	
	int y;
	y = lthua(a,x,q);
	cout << "PU = {q,a,y} = " << "{" << q << ", " << a << ", " << y << "}\n";
	
	int K;
	K = lthua(y,k,q);
	int C1, C2;
	C1 = lthua(a,k,q);
	C2 = lthua(K*M,1,q);
	cout << "Ban ma: (C1,C2) = " << "(" << C1 << ", " << C2 << ")\n";
	
	int K2;
	K2 = lthua(C1,x,q);
	int nghichDaoK2;
	nghichDaoK2 = nghichDao(K2,q);
	int M2;
	M2 = lthua(C2*nghichDaoK2,1,q);
	cout << "Ban ro: M2 = " << M2;
}
