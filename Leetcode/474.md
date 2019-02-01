## 474

现在，假设你分别支配着 **m** 个 `0` 和 **n** 个 `1`。另外，还有一个仅包含 `0` 和 `1` 字符串的数组。

你的任务是使用给定的 **m** 个 `0` 和 **n** 个 `1` ，找到能拼出存在于数组中的字符串的最大数量。每个 `0` 和 `1` 至多被使用**一次**。

```
Input: Array = {"10", "0001", "111001", "1", "0"}, m = 5, n = 3
Output: 4

Explanation: This are totally 4 strings can be formed by the using of 5 0s and 3 1s, which are “10,”0001”,”1”,”0”
```



```c++
class Solution {
public:
    static pair<int, int> count(string s) { //计数每个串中存在多少0和多少1，存到pair中。因为要反复使用，所以最好定义一个函数
        pair<int, int> a;
        for (int i = 0; i < s.length(); ++i) {
            a.first += s[i] == '0';
            a.second += s[i] == '1';
        }
        return a;
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp; //01背包问题，因为有两个约束条件，所以是二维dp（之前学的例子是一维，因为只有背包容量这一个约束条件）
        dp.resize(m + 1);		//定义数组时不能有变量只能有常量，有变量就用vector
        for (int i = 0; i <= m; ++i) {
            dp[i].resize(n + 1);
        }
        for (int i = 0; i < strs.size(); ++i) {
            pair<int, int> w = count(strs[i]);
            for (int j = m; j >= w.first; --j) {
                for (int k = n; k >= w.second; --k) {
                    dp[j][k] = max(dp[j][k], dp[j - w.first][k - w.second] + 1);
                    //01背包，从 m 和 n 开始，保证 j-w.first 和 k-w.second 是前一个状态，没被遍历过
                    //如果从 w.first 和 w.second 开始遍历，就是无穷背包， j-w.first 和 k-w.second 已经被遍历过，可以被选择很多次
                    //dp[j][k]表示前一个状态中用j个0和k个1最多能够表示出多少个数
                    //dp[j - w.first][k - w.second] + 1 表示前一个状态中 j-w.first 个 0 和 k-w.second 个 1 可以表示的最多个数加1
                    //决策加不加第i个
                }
            }
        }
        return dp[m][n];
    }
};

```

