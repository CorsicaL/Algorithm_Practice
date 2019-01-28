#include <bits/stdc++.h>

typedef long long ll;

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    ll a = n / k;
    ll b = n / (k / 2) - a;
    if (k & 1) {
       printf("%lld", a * a * a);
       return 0;
    } else {
        printf("%lld",  a * a * a + b * b * b);
        return 0;
    }
}
