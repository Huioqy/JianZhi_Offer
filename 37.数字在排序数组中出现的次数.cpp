/*数字在排序数组中出现的次数*/

/*
统计一个数字在排序数组中出现的次数。
*/

/*
二分查找
*/

class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        //return count(data.begin(),data.end(),k);
        
        //auto left = lower_bound(data.begin(), data.end(), k);
        //auto right = upper_bound(data.begin(), data.end(), k);
        //return right - left;
        
        int index = FindOneK(data,k);
        if(index==-1) return 0;
        int count = 1;
        int index_last = index;
        while(--index>=0 && data[index] == k ) count++;
        while(++index_last<data.size() && data[index_last] == k ) count++;
        return count;
    }
    
    int FindOneK(vector<int> &data, int k){
        int start = 0;
        int end = data.size() - 1;
        if(start>end) return -1;
        while(start<=end){
            int mid = (start + end) / 2;
            if(data[mid]<k) start = mid+1;
            if(data[mid]>k) end  = mid-1;
            if(data[mid]==k) return mid;
        }
        return -1;
    }
};