/*斐波那契数列*/

/*
现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0）。
斐波那契数列：1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, ...
F(1)=1，F(2)=1, F(n)=F(n-1)+F(n-2)（n>=3，n∈N*）
n<=39
*/

/*
迭代（Iteration） VS 递归（Recursion）
每次递归都是未知的,前面的值都要计算
动态规划 Good
*/
class Solution {
public:
    int Fibonacci(int n) {
        int  fn = 0, fn_1 = 1;
        while (n>0 && n--){
            fn += fn_1;
            fn_1 = fn - fn_1;
        }
        return fn;
    }
};
