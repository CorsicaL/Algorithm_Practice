## 73Set_Matrix_Zeroes

给定一个 *m* x *n* 的矩阵，如果一个元素为 0，则将其所在行和列的所有元素都设为 0。请使用**原地**算法。

**空间复杂度为O(m + n) **

若`matrix[i][j]`为0，则第i行为0，第j列为0。扫描一次矩阵，设一个数组`bool flag[m + n]`，记录行和列为0的情况，依据这个布尔数组，将为0的行列置0，时间复杂度为*O(n^2)*

**空间复杂度为O(2) **

用第0行和第0列的m + n - 2 （不包括`matrix[0][0]`）个位置来记录行和列为0的情况，在设置两个布尔变量`row`和`column`，表示第0行和第0列的为0情况，最后再扫描一次置0，时间复杂度同上

```c++
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool row = false, column = false;
        int n = matrix.size(), m = matrix[0].size();
        for (int i = 0; i < n; ++i) { //扫描第一列
            if (matrix[i][0] == 0) {
                column = true;
                break;
            }
        }
        
        for (int j = 0; j < m; ++j) { //扫描第一行
            if (matrix[0][j] == 0) {
                row = true;
                break;
            }
        }

        for (int i = 1; i < n; ++i) { //全部扫描
            for (int j = 1; j < m; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for (int i = 1; i < n; ++i) { //行置零
            if (matrix[i][0] == 0) {
                for (int j = 0; j < m; ++j) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        for (int j = 1; j < m; ++j) { //列置零
            if (matrix[0][j] == 0) {
                for (int i = 0; i < n; ++i) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        if (column) { //第0列
            for (int i = 0; i < n; ++i) {
                matrix[i][0] = 0;
            }
        }
        
        if (row) { //第0行
            for (int j = 0; j < m; ++j) {
                matrix[0][j] = 0;
            }
        }
        
    }
};
```

