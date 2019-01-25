#include <bits/stdc++.h>

#define MAXN (200010)

char s[MAXN], t[MAXN];
std::vector<std::vector<int>> cnt1(26), cnt2(26);

int main() {
    scanf("%s", s);
    scanf("%s", t);
    for (int i = 0; s[i]; ++i) {
        cnt1[s[i] - 'a'].push_back(i);
        cnt2[t[i] - 'a'].push_back(i);
    }
    // aba
    // abb
    // cnt1 = {{0, 2}, {1}, {}, {}, ...}
    // cnt2 = {{0}, {1, 2}, {}, {}, ...}
    std::sort(cnt1.begin(), cnt1.end());
    std::sort(cnt2.begin(), cnt2.end());
    puts(cnt1 == cnt2 ? "Yes" : "No");
    return 0;
}
/*
abb
aba
 */
