## 402

给定一个以字符串表示的非负整数 *num*，移除这个数中的 *k* 位数字，使得剩下的数字最小。

**注意:**

- *num* 的长度小于 10002 且 ≥ *k。*
- *num* 不会包含任何前导零。

**示例 1 :**

```
输入: num = "1432219", k = 3
输出: "1219"
解释: 移除掉三个数字 4, 3, 和 2 形成一个新的最小的数字 1219。
```

### 单调栈

```c++
stack<int> s;
while (!s.empty() && s.top() > /input/) {	//不为空且不单调就弹出
    s.pop();
}
s.push(/input/);//都弹出后，保证单调，压入栈
```

#### Example

$$a_1,a_2,a_3,a_4,a_5,a_6,a_7 \cdots a_n$$

对每个 i，求出一个区间 [li, ri]。满足 ai 是区间 [li, ri] 中的最小值，并且区间尽可能大。保证 ai 互不相同。

```c++
a  = 1 8 4 5 6 3 2 7
id = 1 2 3 4 5 6 7 8

i = 3, ai = 4。[li, ri] = [2, 5]。
```

```c++
int n;
int a[MAXN], l[MAXN], r[MAXN];

void solve() {
    stack<int> s;
    a[0] = a[n + 1] = INT_MIN //如果不初始化这两个，a[0]和a[n]的值不对
    for (int i = 0; i <= n + 1; ++i) {
        while (!s.empty() && a[s.top()] > a[i]) {
            r[s.top()] = i - 1;
            s.pop();
        };
        if (!s.empty){
	        l[i] = s.top() + 1;            
        }
        s.push(i);
    }
}
```



1. 要让数位单调不降。例如 ...43...。如果我不删掉43，那么前缀为 ...4；否则前缀为 ...3，一定优于前者。
2. 用单调栈维护，每次压入栈顶的时候，弹出栈顶严格大于当前元素的栈中元素。
3. 注意只能删掉 k 个元素。所以要在弹栈的时候加上限制。并且，如果数位已经单调不降，而 k 还有剩余，那么显然删掉末尾（栈顶） k 个元素。
4. 还要去掉前导 0。
5. 如果答案串为空串，将其设置为 0。

```c++
class Solution {
public:
string removeKdigits(string num, int k) {
	stack<char> s;
	for (int i = 0; i < num.length(); ++i) {
		while (k && !s.empty() && s.top() > num[i]) {	//单调栈，但最多只能弹出k次
			s.pop();
			k--;
		}
		s.push(num[i]);
	}
	string ans;
	while (!s.empty()) {
		if (k) {	//k不为0，弹出后面的
			--k;
		} else {	//k为0，存入ans串
			ans += s.top();
		}
		s.pop();
	}
	reverse(ans.begin(), ans.end());	//从栈顶开始存，所以是反的
	int i;
	for (i = 0; ans[i] == ‘0’; i++);	//把开头为0的排除
	ans = ans.substr(i, ans.length() - i);	//把没有前导0的存入ans
	if (ans == “”) {		//如果ans为空，ans为0
		ans = “0”;
	}
	return ans;
}
};

```

