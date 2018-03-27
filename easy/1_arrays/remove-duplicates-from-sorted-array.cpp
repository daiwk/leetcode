
// 题目：给定一个有序数组，你需要原地删除其中的重复内容，使每个元素只出现一次,并返回新的长度。
// 不要另外定义一个数组，您必须通过用 O(1) 额外内存原地修改输入的数组来做到这一点。

// 解法：因为已经排好序了，所以，用两个指针，快的指针如果发现当前值和慢的一样，就往后走，直到走到第一个不一样的，就把它的值赋值给慢的后面那个数，然后慢的指针也往前走
// 参考：https://leetcode.com/problems/remove-duplicates-from-sorted-array/solution/ 

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int i = 0;
        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] != nums[i]) {
                i++;
                nums[i] = nums[j];
            }
        }
        return i + 1;
    }
};
