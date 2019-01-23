#include <bits/stdc++.h>

int n, t, a, h;

int main() {
    std::cin >> n >> t >> a;
    double  min = INT32_MAX;
    int mini;
    for (int i = 1; i <= n; ++i) {
        std::cin >> h;
        double ht = t - h * 0.006;
        if (fabs(ht - a) < min) {
            mini = i;
            min = fabs(ht - a);
        }
    }
    std::cout << mini;
}