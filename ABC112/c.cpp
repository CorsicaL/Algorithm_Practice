#include <bits/stdc++.h>
#define MAXN (110)
int n;
int x[MAXN], y[MAXN], h[MAXN];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d%d", x + i, y + i, h + i);
    }
    for (int cx = 0; cx <= 100; ++cx) {
        for (int cy = 0; cy <= 100; ++cy) {
            bool flag = true;
            int ans = 0, max = INT32_MAX;
            for (int i = 1; i <= n; ++i) {
                int t = std::abs(x[i] - cx) + std::abs(y[i] - cy);
                if (h[i] == 0) {
                    max = std::min(max, t);
                } else {
                    if (ans == 0) {
                        ans = t + h[i];
                    } else if (ans != t + h[i]) {
                        flag = false;
                        break;
                    }
                }
                if (ans > max) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                printf("%d %d %d\n", cx, cy, ans);
                return 0;
            }
        }
    }
}
