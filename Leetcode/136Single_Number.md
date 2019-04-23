## 136Single_Number

给定一个**非空**整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

**说明：**

你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

```c++
int ans = 0;
for (int i = 0; i < nums.size(); ++i) {
    ans ^= a[i];
}
```

给定一个**非空**整数数组，除了某个元素只出现一次以外，其余每个元素均出现了三次。找出那个只出现了一次的元素。

```c++
int a = 0, b = 0;
for (auto x : nums) {
    a = (a ^ x) & ~b;
    b = (b ^ x) & ~a;
}
return a;
```

### 260

给定一个整数数组 `nums`，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 找出只出现一次的那两个元素。

```c++
int two = 0;
for (auto i : nums) {
    two ^= i;
}
int bit = 1;
while ((two & 1) == 0) { //找到两个出现一次的数中，最后一位不相同的数
    two >>= 1;
    bit <<= 1;
}
int a = 0, b = 0; //通过这一位1，把整个数组分成这位是1和这位是0的两部分，分别进行异或
for (auto i : nums) {
    if ((i & bit) != 0) {
        a  ^= i;
    } else {
        b ^= i;
    }
}
vector<int> ans = {a, b};
```
