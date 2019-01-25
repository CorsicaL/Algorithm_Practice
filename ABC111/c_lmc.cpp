#include <bits/stdc++.h>
#define MAXN (100010)
using namespace std;
int n;
bool flag1 = true, flag2 = true;
int cnt1[MAXN], cnt2[MAXN];
vector<pair<int,int>> v1, v2;
int vv1[MAXN], vv2[MAXN];

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    return a > b;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        if (i % 2) {
            scanf("%d", &vv1[i / 2]);
            cnt1[vv1[i / 2]]++;
            if (i > 1 && vv1[i / 2] != vv1[i / 2 - 1]) {
                flag1 = false;
            }
        } else {
            scanf("%d", &vv2[i / 2 - 1]);
            cnt2[vv2[i / 2 - 1]] ++;
            if (i > 2 && vv2[i / 2 - 1] != vv2[i / 2 - 2]) {
                flag2 = false;
            }
        }
    }
    if (flag1 && flag2) {
       if (vv1[0] == vv2[0]) {
           printf("%d", n / 2);
           return 0;
       } else {
           printf("0");
           return 0;
       }
    } else {
        for (int j = 0; j < MAXN; ++j) {
            if (cnt1[j]) {
                v1.emplace_back(cnt1[j], j);
            }
            if (cnt2[j]) {
                v2.emplace_back(cnt2[j], j);
            }
        }
        sort(v2.begin(), v2.end(), cmp);
        sort(v1.begin(), v1.end(), cmp);
        if (v1[0].second == v2[0].second) {
            printf("%d\n", min(n - v1[0].first - v2[1].first, n - v1[1].first - v2[0].first));
            return 0;
        } else {
            printf("%d\n", n - v1[0].first - v2[0].first);
            return 0;
        }
    }

    return 0;
}
/*
 12
 3 3 3 3 3 3 2 1 2 1 1 1
 */