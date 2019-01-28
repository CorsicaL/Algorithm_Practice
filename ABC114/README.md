## Bitwise Operation

### ^

```
x ^ y = z
z ^ y = x
z ^ x = y
x ^ x = 0
0 ^ x = x
```

**Example 1:**

You are given several integers, and **only one** number appeared once, find out this number.

```
a1 ^ a2 ^ ... ^ an = a
```

`a` is the unique number

**Example 2:**

**Two** numbers appeared once

```
a1 ^ a2 ^ ... ^ an = z
```

`z` means `x ^ y`, `z` at least one bit in binary is `1`. According to the `1`, which means in binary this bit is different in `x` and `y`, we can divide all numbers into two parts. Do the steps in **Example 1** again: 

```
b1 ^ b2 ^ ... ^ bk = x
c1 ^ c2 ^ ... ^ cs = y
```

`x` `y` are the two numbers.

### &

**Example 1:**

Fine the lowest bit `1`

```c
lowbit(4) = 100;
lowbit(5) = 1;
lowbit(6) = 10;
```

```c
lowbit(x) = x & (-x);
x - lowbit(x) = x & (x - 1);
x = 100001001;
x - 1 = 100001000;
-x = 011110111;
```





## ABC114#C

### Problem Statement

A legal number is :

1. Only consists of 3, 5 and 7
2. Each of 3, 5 and 7 appeared at least once when the number is written in base ten

From $1$ to $N$, how many legal number are there?

**Recursive**

```c++
ll dfs(ll x, int cnt3, int cnt5, int cnt7) {
    if (x > n) {
        return 0;
    }
    if (cnt3 && cnt5 && cnt7) {
        cnt ++;
    }
    dfs(x * 10 + 3, 1, cnt5, cnt7);
    dfs(x * 10 + 5, cnt3, 1, cnt7);
    dfs(x * 10 + 7, cnt3, cnt5, 1);
}
```

`dfs(0, 0, 0, 0)` from `x = 0` to `x = n`,  initialize `cnt3`, `cnt5` and `cnt7 = 0`. Recursively shift `x` one bit to the left and add `3`, `5` and `7`, and assign `cnt3`, `cnt5` or `cnt7` to `1`, which means this number `x` now have a `3`, `5` or `7`. When `cnt3`, `cnt5` and `cnt7` are all `1`, this number is legal.



## ABC114#D

Among the divisors of $N!$, how many numbers that have exactly 75 divisors are there?

**Prime Factorization(质因数分解)**

Divide from the smallest prime number and divide each factor until it cannot be divided.

$$
p^{a_1}q^{a_2} \cdots r^{a_n} = N \\
$$
the number of factors of $N​$
$$
(a_1 + 1)(a_2 + 1) \cdots (a_n + 1)
$$

```c++
void div(int x) {
    for (int i = 2; i <= x; ++i) { 
        while (x % i == 0) { // i is the divisor of x
            num[i] ++;		 // count the amount of the factor i
            x /= i;			 // x /= i until x % i != 0
        }
    }
}
```

 

**Dynamic Programming**

```c++
    a[0][1] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= 75; ++j) {
            for (int k = 0; k <= num[i]; ++k) {
                if (j * (k + 1) <= 75) {
                    a[i][j * (k + 1)] += a[i - 1][j];
                }
            }
        }
    }
```

`a[i - 1][j]` means use the number  from $1$ to $i$, and use them $j​$ times in total.

`a[i][j * (k + 1)]` means based on the `a[i - 1][j]`, add the factor $i$ and use it $k$ times(multiply $i^k$). 