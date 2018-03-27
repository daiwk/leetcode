<!-- TOC -->

- [题目：买卖股票的最佳时机 II](#题目买卖股票的最佳时机-ii)
- [解法：](#解法)
    - [解法1：](#解法1)
    - [解法2：](#解法2)
    - [解法3:](#解法3)

<!-- /TOC -->

## 题目：买卖股票的最佳时机 II

假设有一个数组，它的第 i 个元素是一个给定的股票在第 i 天的价格。
设计一个算法来找到最大的利润。你可以完成尽可能多的交易（多次买卖股票）。然而，你不能同时参与多个交易（你必须在再次购买前出售股票）。

## 解法：
参考：https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/solution/

### 解法1：
暴力搜索，超时

```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        return calculate(prices, 0);
    }

    int calculate(vector<int>& prices, int s) {
        if (s >= prices.size())
            return 0;
        int max = 0;
        for (int start = s; start < prices.size(); start++) {
            int maxprofit = 0;
            for (int i = start + 1; i < prices.size(); i++) {
                if (prices[start] < prices[i]) {
                    int profit = calculate(prices, i + 1) + prices[i] - prices[start];
                    if (profit > maxprofit)
                        maxprofit = profit;
                }
            }
            if (maxprofit > max)
                max = maxprofit;
        }
        return max;
    }
};
```

### 解法2：

例如，输入是[7, 1, 5, 3, 6, 4]，那么走势图如下，

![](https://leetcode.com/media/original_images/122_maxprofit_1.PNG)

在波谷买进，波峰卖出，这样收益最大，所以A+B是最大的。相比C而言，有A+B>=C

所以，一个指针，先找到第一个波谷，买入，然后找到第一个波峰，卖出，这样这就是一次的利润了，然后继续，累加得到总利润。

```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i = 0;
        if (prices.size() == 0) return 0;
        int valley = prices[0];
        int peak = prices[0];
        int maxprofit = 0;
        while (i < prices.size() - 1) {
            while (i < prices.size() - 1 && prices[i] >= prices[i + 1])
                i++;
            valley = prices[i];
            while (i < prices.size() - 1 && prices[i] <= prices[i + 1])
                i++;
            peak = prices[i];
            maxprofit += peak - valley;
        }
        return maxprofit;
    }
};
```

### 解法3:

例如，输入是[1, 7, 2, 3, 6, 7, 6, 7]，那么走势图如下 
![](https://leetcode.com/media/original_images/122_maxprofit_2.PNG)
思路与解法2类似，只是可以干掉那两个while循环，我们发现在上升的过程中，相邻两个时间的上升量累加起来，正好就是到达波峰时波峰和波谷的差值，即可以发现A+B+C=D

```c++
class Solution {
public:
     int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i - 1])
                maxprofit += prices[i] - prices[i - 1];
        }
        return maxprofit;
    }
};
```