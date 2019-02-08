## 66

给定一个由**整数**组成的**非空**数组所表示的非负整数，在该数的基础上加一。

最高位数字存放在数组的首位， 数组中每个元素只存储一个数字。

你可以假设除了整数 0 之外，这个整数不会以零开头。

- ```vector::insert(position, element)```: The vector is extended by inserting new elements before the element at the specified *position*, effectively increasing the container size by the number of elements inserted.

- ```vector::pop_back()```: Removes the last element in the vector, effectively reducing the container size by one.
- ```vector::back()```: Returns a reference to the last element in the vector.

```c++
vector<int> plusOne(vector<int> &digits) {
	for (int i = digits.size() - 1; i >= 0; --i) {
		digits[i] += 1;
		if (digits[i] == 10) {
			digits[i] = 0;
		} else {
			break;
		}
    }
    if (digits[0] == 0) {
        digits.insert(digits.begin(), 1);
    }
    return digits;
}
```

