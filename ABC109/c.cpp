#include <bits/stdc++.h>

int n, x, xi, ans;

int main() {
    scanf("%d%d", &n, &x);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &xi);
        ans = std::__gcd(std::abs(xi - x), ans);
    }
    printf("%d\n", ans);
    return 0;
}