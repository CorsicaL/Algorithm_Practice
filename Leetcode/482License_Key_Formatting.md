## 482

给定一个密钥字符串S，只包含字母，数字以及 '-'（破折号）。N 个 '-' 将字符串分成了 N+1 组。给定一个数字 K，重新格式化字符串，除了第一个分组以外，每个分组要包含 K 个字符，第一个分组至少要包含 1 个字符。两个分组之间用 '-'（破折号）隔开，并且将所有的小写字母转换为大写字母。

给定非空字符串 S 和数字 K，按照上面描述的规则进行格式化。

```c++
string t;
for (int i = 0; i < S.length(); ++i) {	//处理输入字符串，去掉‘-’
    if (S[i] == '-') continue;
    t += toupper(S[i]);
}
int first = S.length() % K;		//第一组需要first个
int num = S.length() / K;		//除了第一组，还需要num组
if (!first) {					//若第一组为0，则第一组个数为K
    first = K;
    num --;						//除了第一组之外的组数需要减1
}
string ans = t.substr(0,first);	//初始化ans为t的0-first
for (int i = 0; i < num; ++i) {	//把后面的加入
    ans += '-' +t.substr(first + i * k, k); 
}
return ans;
```

### substr(pos, len)

The substring is the portion of the object that starts at character position `pos` and spans `len` characters

