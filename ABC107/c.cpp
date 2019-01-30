#include <bits/stdc++.h>

#define MAXN (100010)

int n, k, x[MAXN];

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", x + i);
    }
    int ans = INT_MAX;
    for (int j = 1; j <= n - k + 1; ++j) {
        int l = x[j];
        int r = x[j + k - 1];
        int s = abs(l - r) + std::min(abs(l), abs(r));
        ans = std::min(ans, s);
    }
    printf("%d", ans);
    return 0;
}