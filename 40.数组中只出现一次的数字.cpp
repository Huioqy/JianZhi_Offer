/*数组中只出现一次的数字*/

/*
一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。
*/

/*
HashMap
位运算中异或的性质：两个相同数字异或=0，一个数和0异或还是它本身
异或^=
==的优先级比&高，所以&时需要加括号。

思路：
1、异或思想，一个数与自己异或为0，一个数与0异或为自己
2、由于其它数字两两相同，所以所有数异或则得到这两个不同数的异或结果。取这个结果的第一个1作为标志位
3、这个标志的1，必须是：这两个数在该位一个为0，一个为1
4、这样可以将数组分为两组，一组在该标志位为1，一组在该标志位为0，这两个不同数字分别在这两组内
5、将两组内的数分别异或，得到两个结果则为这两个不同的数
*/
class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        int num=0;
        for(int i=0;i<data.size();i++){
            num^=data[i];//所有数异或，结果为不同的两个数字的异或
        }
        //cout<<bitset<sizeof(int)*8>(num)<<endl;
        int count=0;//标志位，记录num中的第一个1出现的位置
        for(;count<data.size();count++)
            if((num&(1<<count))!=0) break;
        for(int i=0;i<data.size();i++){
            if((data[i]&(1<<count))==0)//标志位为0的为一组，异或后必得到一个数字（这里注意==的优先级高于&，需在前面加（））
                *num1^=data[i];
            else
                *num2^=data[i];//标志位为1的为一组
        }
    }
};

/*
//哈希表
class Solution {
public:
   void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
    unordered_map<int, int> map;
    for (int i = 0; i < data.size(); i++)
        map[data[i]]++;
    vector<int>v;
    for (int i = 0; i < data.size(); i++)
        if (map[data[i]]== 1)
            v.push_back(data[i]);
    *num1 = v[0]; *num2 = v[1];
    }
};

//set
class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        set<int> save;
        set<int>::iterator iter;
        for (int i = 0; i < data.size(); i++){
            if (save.find(data[i]) == save.end())
                save.insert(data[i]);
            else{
                iter = save.find(data[i]);
                save.erase(iter);
            }
        }
        iter = save.begin();
        *num1 = *iter;
        *num2 = *(++iter);
    }
};

*/
