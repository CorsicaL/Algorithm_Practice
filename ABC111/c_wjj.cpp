#include <bits/stdc++.h>

#define MAXN (100010)

int n;
int cnt1[MAXN], cnt2[MAXN];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        int x;
        scanf("%d", &x);
        if (i & 1) ++cnt1[x];
        else ++cnt2[x];
    }
    std::pair<int, int> odd1(0, 0), odd2(0, 0); // first: count, second: number
    std::pair<int, int> even1(0, 0), even2(0, 0);
    for (int i = 1; i < MAXN; ++i) {
        if (cnt1[i] > odd1.first) {
            odd2 = odd1;
            odd1 = {cnt1[i], i};
        } else if (cnt1[i] > odd2.first) {
            odd2 = {cnt1[i], i};
        }

        if (cnt2[i] > even1.first) {
            even2 = even1;
            even1 = {cnt2[i], i};
        } else if (cnt2[i] > even2.first) {
            even2 = {cnt2[i], i};
        }
    }

    if (odd1.second == even1.second) {
        printf("%d\n", n - std::max(odd1.first + even2.first, odd2.first + even1.first));
    } else {
        printf("%d\n", n - odd1.first - even1.first);
    }

    return 0;
}