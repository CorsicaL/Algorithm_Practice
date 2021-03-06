## 56

Given a collection of intervals, merge all overlapping intervals.

```
Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
```

复杂度为O(n)，每个输入数据都只扫描了一次，所以是最优解答

```c++
/**
 \* Definition for an interval.
 \* struct Interval {
 \*     int start;
 \*     int end;
 \*     Interval() : start(0), end(0) {} 	//构造函数
 \*     Interval(int start, int end) {		//函数重载
 \*        	this->start = start;			//this指向实例
 \*			this->end = end;
 \*     }
 \*		Interval(int s, int e) : start(s), end(e) {}
 \* };
 */
class Solution {
public:

static bool cmp(const Interval &x, const Interval &y) {
	return x.start == y.start ? x.end < y.end : x.start < y.start;	//start不等就比较start，start相等就比较end
}

vector<Interval> merge(vector<Interval>& intervals) {
	sort(intervals.begin(), intervals.end(), cmp);	//区间排序
	vector<Interval> ans;
	for (int i = 0, j; i < intervals.size(); i = j) {
    //i从0开始，查找到不能合并的地方，说明j不能合并，前面都已经被合并了，从j开始往后判断
		int s = intervals[i].start;		//区间开始
		int e = intervals[i].end;		//区间结束
			for (j = i + 1; j < intervals.size(); ++j) {	
            //从i+1一直查找到不能合并的位置
				if (e >= intervals[j].start) {				
                //结束的大于下一个的开始，就可以合并。合并时要判断e和j的end谁更大
					e = max(e, intervals[j].end);
				} else {									
                 //不能合并，跳出
					break;
				}
			}
			// j == size or cannot merge j
			ans.emplace_back(s, e);							
            //s和e是起点和终点，放到结果的数组中
		}
		return ans;
	}
};
```


