#include <bits/stdc++.h>

long long int burger(int n, long long int x) {
    if (x == 0) {
        return 0;
    }
    if (n == 0) {
        return 1;
    }
    x = std::min(x, (long long int) (1ll << (n + 2)) - 3);
    if (x < (1ll << (n + 1)) - 1) {
        return burger(n - 1, x - 1);
    }
    else {
        return (1ll << (n)) + burger(n - 1, x - (1ll << (n + 1)) + 1);
    }
}

int main() {
    int n;
    long long int x;
    scanf("%d%lld", &n, &x);
    printf("%lld", burger(n, x));
    return 0;
}