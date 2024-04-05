#include<bits/stdc++.h>
using namespace std;

// Phi(n) = n * (1 - 1/p1) * (1 - 1/p2) * ... * (1 - 1/pk)
// Voi pi la thua so nguyen to thu i cua n

unsigned int phi(int n) {
    unsigned int result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

int main(){
	int n;
	cout << "Nhap n: ";
	cin >> n;
	
	cout << "Phi(" << n << ") = " << phi(n);
}

