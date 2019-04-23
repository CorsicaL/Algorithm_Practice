## 375Guess_Number_Higher_or_Lower_2

**题目描述**：我们正在玩一个猜数游戏，游戏规则如下：

我从 **1** 到 **n** 之间选择一个数字，你来猜我选了哪个数字。

每次你猜错了，我都会告诉你，我选的数字比你的大了或者小了。

然而，当你猜了数字 x 并且猜错了的时候，你需要支付金额为 x 的现金。直到你猜到我选的数字，你才算赢得了这个游戏。

给定 **n ≥ 1，**计算你至少需要拥有多少现金才能确保你能赢得这个游戏。

**解题思路**：动态规划。

从小到大遍历区间长度 `2 <= len <= n`，在固定区间长度时，用`i,j`作为区间的头尾，即`j = i + len - 1`，然后遍历`1 ~ n`，在一段`[i,j]`区间中，取`k (i <= k <= j)`，遍历整个`[i,j]`，`dp[i][k - 1]` 代表k左边取错的花费，`dp[k + 1][j]`代表k右边取错的花费，两者取最大值，加上k，再与`dp[i][j]`取最小值，即可得到`[i][j]`区间的最小花费。

```c++
int getMoneyAmount(int n) {
    vector<vector<int>> dp(n + 2, vector<int>(n+2, 0));
    for (int len = 2; len <= n; ++len) {
        for (int i = 1; i + len - 1 <= n; ++i) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k <= j; ++k) {
                dp[i][j] = min(dp[i][j], max(dp[i][k-1], dp[k+1][j])+k);
            }
        }
    }
    return dp[1][n];
}
```
