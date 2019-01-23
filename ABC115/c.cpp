#include <bits/stdc++.h>

#define MAXN (100010)

int h[MAXN];

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &h[i]);
    }
    std::sort(h + 1, h + n + 1);
    int hmin = INT32_MAX;
    for (int i = 1; i + k - 1 <= n ; ++i) {
        hmin = std::min(hmin, h[i+k-1] - h[i]);
    }
    printf("%d", hmin);
    return 0;
}
