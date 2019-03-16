/*最小的K个数*/

/*
输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。
*/

/*
思路一：利用快速排序中的获取分割（中轴）点位置函数getPartitiion。
基于数组的第k个数字来调整，使得比第k个数字小的所有数字都位于数组的左边，比第k个数字大的所有数字都位于数组的右边。
调整之后，位于数组左边的k个数字就是最小的k个数字（这k个数字不一定是排序的）。
O(N)

思路二：利用堆排序，O(N logK)，适合处理海量数据
(1) 遍历输入数组，将前k个数插入到推中；（利用multiset来做为堆的实现）
(2) 继续从输入数组中读入元素做为待插入整数，并将它与堆中最大值比较：如果待插入的值比当前已有的最大值小，则用这个数替换当前已有的最大值；如果待插入的值比当前已有的最大值还大，则抛弃这个数，继续读下一个数。
这样动态维护堆中这k个数，以保证它只储存输入数组中的前k个最小的数，最后输出堆即可。
*/
class Solution {
public:
    //堆排序，O(N logK)
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
    {
        vector<int> result;
        int len = input.size();
        if(input.empty() || k<=0 || len < k) return result;
         
        multiset<int, greater<int> > leastNumbers; // 从大到小排序
        multiset<int, greater<int> >::iterator iterGreater; // 定义迭代器
         
        vector<int>::iterator iter = input.begin();
        for(; iter != input.end(); ++iter)
        {
            // 将前k个数直接插入进multiset中，注意是小于K
            if(leastNumbers.size() < k)
            {
                leastNumbers.insert(*iter);
            }
            else
            {
                // 因为设置的从大到小排序，故multiset中第一个位置的元素即为最大值
                iterGreater = leastNumbers.begin();
                 
                // 如果input中当前元素比multiset中最大元素小，则替换；即保持multiset中这k个元素是最小的。
                if(*iter < *(leastNumbers.begin()))
                {
                    // 替换掉当前最大值
                    leastNumbers.erase(iterGreater);
                    leastNumbers.insert(*iter);
                }
            }
        }
         
        for(iterGreater = leastNumbers.begin();iterGreater!=leastNumbers.end();++iterGreater)
        {
            result.push_back(*iterGreater); // 将multiset中这k个元素输出
        }
         
        return result;
    }
    
    /*
    //快速排序
    void swap(int &fir,int &sec)
    {
        int temp = fir;
        fir = sec;
        sec = temp;
    }
     
    int getPartition(vector<int> &input,int start,int end)
    {
        //找出input[end]的位置，左边都小于等于，右边大于
        if(input.empty() || start>end) return -1;
        int temp = input[end];
        int j = start - 1;
        for(int i=start;i<end;++i)
        {
            if(input[i]<=temp)
            {
                ++j;
                if(i!=j) swap(input[i],input[j]);                   
            }
        }
        swap(input[j+1],input[end]);
        return (j+1);
    }
         
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
    {
        vector<int> result;       
        if(input.empty() || k>input.size() || k<=0) return result;
         
        int start = 0;
        int end = input.size()-1;
        int index = getPartition(input,start,end);
         
        while(index != (k-1))
        {
            if(index > (k-1))
            {
                end = index - 1;
                index = getPartition(input,start,end);
            }
            else
            {
                start = index + 1;
                index = getPartition(input,start,end);
            }
        }
         
        for(int i=0;i<k;++i)
        {
            result.push_back(input[i]);
        }
         
        return result;
    }
    */
};