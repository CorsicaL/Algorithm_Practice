### **ABC115 D**
A legal burger: 

$$Level(0) = P$$
$$Level(n) = B+Level(n-1)+P+Level(n-1) +B$$

input $N$ and $X$, output the number of $P$ layer in the bottom-most $X$ layers of $Level \space n$ burger 

    input 2 7
    output 4

There are $4$ patties in the bottom-most $7$ layers of a $Level \space 2$ burger ($BBPPPBPBPPPBB$).

#### `Mathematics Problem solution`

Char String, calculate the length of $Level \space n$

$$ f(n) = 2 \times f(n-1) + 3 $$
$$ f(n) = 2^2 \times f(n-2) + 2 \times 3 + 3 $$
$$ \cdots $$
$$ f(n) = 2^n \times f(0) + 3 \times (\sum_{i=0}^{n-1} 2^i) $$
$$ f(n) = 2^{n+2} - 3$$
$$ p(n,n) = 2 \times p(n-1,n-1) + 1$$
$$ p(n,n) = 2^{n+1}-1 $$

#### `Classification in Recursion`

$$ p(n,x) = 
\begin{cases} 
p(n-1,x-1),&x<2^{n+1}-2 \\ 
2^{n}-1+1+p(n-1,x-(2^{n+1}-2)),&2^{n+1}-2 \le x\le 2^{n+2}-3  \\
2^{n+1}-1,&x=2^{n+2}-3
\end{cases} 
$$

#### `Boundary conditions in Recursion`
- The boundary conditions in `p(n,x)`, `x` has a higher priority because while `n == 0 && x == 0`, we should return 0 but not 1 
```c
if (x == 0)
    return 0;
if (n == 0)
    return 1;
```
- We can merge the second and the third case in $p(n,x)$ if we let `x = min(x, 1ll << (n + 2) - 3)`


#### `Attention`

- Don't use `long long int`, use `typedef long long ll;`
- $1\le N\le 50$, $2^{N} \ge 2^{32}$, use `long long` not `int` when we assign the `p(n, x)`,`x`
- The default length of integer is `32-bit`, `1ll` means `64-bit 1`. In this problem, $2^{n}$ should be written as `1ll << n`
