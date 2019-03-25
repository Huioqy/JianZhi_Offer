/*字符串的排列*/

/*
输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
*/

//递归
class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> res;
        if(str.empty()) return res;
         Permutation(res, str, 0);
        //字典序
        sort(res.begin(),res.end());
        return res;
    }
    
    void Permutation(vector<string> &res, string str, int head) {
        if(head == str.size() - 1) 
            res.push_back(str);
        for(int i=head;i<str.size();i++){
            //当i==begin时，也要遍历其后面的所有字符；
            //当i!=begin时，先交换，使第begin位取到不同的可能字符，再遍历后面的字符
            if(i!=head && str[i]==str[head]) //有重复字符时，跳过
                continue;
            swap(str[i],str[head]);//遍历其后面的所有字符；
            
            Permutation(res, str, head+1);
            
            swap(str[i],str[head]);//为了防止重复的情况，还需要将head处的元素重新换回来
        }
    }
};
