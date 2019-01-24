#include <bits/stdc++.h>
int ci, ti, n, t;
int main() {
    scanf("%d%d", &n, &t);
    int min = INT32_MAX;
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", &ci, &ti);
        if (ti <= t) {
            min = std::min(min, ci);
        }
    }
    if (min == INT32_MAX) {
        return puts("TLE"), 0;
    } else {
        return printf("%d\n", min), 0;
    }
}
