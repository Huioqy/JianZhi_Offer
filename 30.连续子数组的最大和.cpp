/*连续子数组的最大和*/

/*
H计算连续子向量的最大和,当向量全为正数的时候,问题很好解决。但是,如果向量中包含负数,是否应该包含某个负数,并期望旁边的正数会弥补它呢？例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)。给一个数组，返回它的最大连续子序列的和，你会不会被他忽悠住？(子向量的长度至少是1)
*/

//动态规划
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        vector<int> dp(array.size());
        int local_sum = array[0], global_sum = array[0];
        for(int i = 1; i < array.size(); i++){
            local_sum = max(array[i], array[i]+local_sum);
            global_sum = max(local_sum,global_sum);
        }
        return global_sum;
    }
    /*
    int FindGreatestSumOfSubArray(vector<int> array) {
        vector<int> dp(array.size());
        dp[0] = array[0];
        for(int i = 1; i < array.size(); i++){
            dp[i] = max(array[i], array[i]+dp[i-1]);
        }
        return *max_element(dp.begin(), dp.end());
    }
    */
};
