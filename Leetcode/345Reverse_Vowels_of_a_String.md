## 345

编写一个函数，以字符串作为输入，反转该字符串中的元音字母。 

```
Input: "hello"
Output: "holle"
```

### string

```c++
string a;
a.length(); 		//初始长度是0
a = “hello world”;	//整体赋值
a[1] = ‘a’;			//单个赋值
a += “a”;			//末尾加一个字符
a = a + ‘a’ + ‘b’;	//末尾加ab，不能 a += 'a' + 'b'
```



```c++
class Solution {
public:
    static bool judge(char x) { 	//反复判断所以写成函数可读性更好
        x = tolower(x);				//大小写字母均有可能
        return x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u';
    }
    string reverseVowels(string s) {
        string a;	//用一个string来存元音字母
        for (int i = 0; i < s.length(); ++i) {
            if (judge(s[i])) {
                a += s[i];
            }
        }
        reverse(a.begin(), a.end()); //翻转a
        int j = 0;
        for (int i = 0; i < s.length(); ++i) { //是元音字母就把a的元素放回去
            if (judge(s[i])) {
                s[i] = a[j++];
            }
        }
        return s;
    }
};

};

```

### stack

```c++
std::stack<T> s;
s.size(); 	// int，初始大小为0
s.empty(); 	// bool，判断是否为空
s.pop(); 	// void，出栈
s.push(T); 	// void，入栈
s.top() 	// T，栈顶指针所指的元素
```

```C++
class Solution {
public:
    static bool judge(char x) {
        x = tolower(x);
        return x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u';
    }
    string reverseVowels(string s) {
        stack<char> a;	//逆序输出，用栈
        for (int i = 0; i < s.length(); ++i) {
            if (judge(s[i])) {
                a.push(s[i]);
            }
        }
        for (int i = 0; i < s.length(); ++i) {
            if (judge(s[i])) {
                s[i] = a.top();
                a.pop();
            }
        }
        return s;
    }
};
```

### 双指针

双指针主要用于遍历数组，两个指针指向不同的元素，从而协同完成任务。

```c++
while (left <= right) {
    if (ans < target) {			//左不满足改左
        left++;
    } else if (ans > target) {	//右不满足改右
        right--;
    } else {					//都满足执行满足的操作
        ok~
    }
}
```

**空间复杂度O(1)**

```C++

class Solution {
public:
    static bool judge(char x) {
        x = tolower(x);
        return x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u';
    }
    string reverseVowels(string s) {
        int i = 0, j = s.length() - 1;
        while (i <= j) {
            if (!judge(s[i])) {			//左边下标i不是元音，改左
                i++;
            } else if (!judge(s[j])) {	//右边下标i不是元音，改右
                j--;
            } else {					//左右都是元音，交换位置
                char tmp = s[i];
                s[i++] = s[j];
                s[j--] = tmp;
            }
        }
        return s;
    }
};
```

