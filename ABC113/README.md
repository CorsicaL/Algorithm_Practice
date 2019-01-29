## Pair

 Pair is a struct template that provides a way to store two $\underline{\text{heterogeneous objects}}$ (异构对象) as a single unit.

```c++
std::pair<int ,int> a; // a is an ordered pair and the type of its elements is int
a = {7, 5};
```

`a.first` is `7`. `a.second` is `5`.

Comparing two `pair`

```c++
std::pair<int, int> a, b;
if ((a.first > b.first) || (a.first == b.first) && (a.second > b.second))
    a > b;
```



## Vector

Vector  is a sequence container that $\underline{\text{encapsulates}}$ (封装) dynamic size arrays.

```c++
std::vector<int> arr(10); // define arr and initialize its size as 10
arr.resize(20); // use resize to change the size of arr
```

If the size does not matter.

```c++
std::vector<int> arr; // the size of arr is 0
```

Some Member Functions

```c++
arr.push_back(1); //adds an element to the end, arr[0] = 1, the size of arr ++

arr.begin(); //returns an iterator(迭代器) to the beginning

arr.end(); //returns an iterator to the end

std::sort(arr.begin(), arr.end());//sort arr
```

Vector can use all operators.



Elements are `pair<int, int>`.

```c++
std::vector<pair<int, int>> arr; //linear dynamic array
arr.emplace_back(1, 2); //a[0] = <1, 2> 
std::sort(arr.begin(), arr.end());
```

```c++
std::vector<pair<int, int>> arr[10]; //2-dementional dynamic array
arr[1].emplace_back(1, 2);//a[1][0] = <1, 2>
std::sort(arr[1].begin(), arr[1].end());
```



## Sort

Sorts the elements in the range `[first, last)` in $\underline{\text{ascending order}}$ (升序). 

Complexity is $\mathbf{O(N \cdot log(N))}$.

We can also define a function and use it to sort. The default comparing way is $<​$. Only anti-reflexive relation is allowed.

```c++
bool compare(int x, int y) {
    return x > y;
}

std::sort(a + 1, a + n + 1); //a[1] to a[n] ascending order
std::sort(a + 1, a + n + 1, compare); // a[1] to a[n] descending order
```



## ABC113#C

### Problem Statement

There are $N$ prefectures, and a total of $M$ cities that belong to those prefectures. 

City $i$ established in year $Y_i$ and belongs to Prefecture $P_i$.

There are no multiple cities that are established in the same year.

It is decided to allocate a $12$-digit ID number to each city. If City $i$ is the $x$-th established city among the cities that belong to Prefecture $i$, the first 6 digits is $P_i$, and the last 6 digits is $x$.

If $P_i$ or $x$ has less than six digits, zeros are added to the left until it has six digits.

---

```c++
using namespace std;
vector<pair<int, int>> arr[MAXN];
int p[MAXN], y[MAXN];

//i from 1 to m
arr[p[i]].emplace_back(y[i], i); //use i to record the sequence of input

//i from 1 to n
sort(arr[i].begin(), arr[i].end()); //sort all cities belong to each prefecture;
int k = 1;
for (auto j : arr[i]) {
    y[j.second] = k++; //j.second means the sequence of input(index in y[]), for each prefecture, change the value of y[j.second] to the order.
}
```

