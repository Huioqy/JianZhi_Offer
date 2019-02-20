/*矩形覆盖*/

/*
我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
*/

/*
斐波那契数列
*/
class Solution {
public:
    int rectCover(int number) {
        int  fn = 1, fn_1 = 0;
        if (number < 1) {
            return 0;
        } else while (number>0 && number--){
            fn += fn_1;
            fn_1 = fn - fn_1;
        }
        return fn;
        /*
        if (number < 1) {
            return 0;
        } else if (number == 1 || number == 2) {
            return number;
        } else {
            return rectCover(number-1) + rectCover(number-2);
        }
        */
    }
};
