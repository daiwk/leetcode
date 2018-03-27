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