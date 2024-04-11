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

// b = a^m mod n
int main(){
    int a,m,n;
    
    cout << "Nhap a: ";
    cin >> a;
    cout << "Nhap m: ";
    cin >> m;
    cout << "Nhap n: ";
    cin >> n;
    
    cout << "b = " << a << "^" << m << " mod " << n << " = " << lthua(a,m,n);
}
