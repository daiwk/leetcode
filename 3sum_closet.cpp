/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(num.begin(),num.end());
        int sums = num[0] + num[1] + num.back();
        int i = 0;
        int j = 1;
        int k = num.size();
        int temp_sum = sums;
        for( i = 0; i < num.size() - 2; i++)
        {
            j = i +1;
            k = num.size() - 1;
            while(j < k) {
                temp_sum = num[i] + num[j] + num[k];
                if(abs(sums - target) > abs(temp_sum - target)) {
                    sums = temp_sum;
                }
                if( temp_sum == target)
                    return target;
                else if( temp_sum < target){
                    j++;
                }
                else
                    k--;
                
            }
        }
        return sums;        
    }
};
