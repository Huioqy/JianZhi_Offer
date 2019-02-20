/*替换空格*/

/*请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。*/

class Solution {
public:
	void replaceSpace(char *str,int length) {
         //遍历一边字符串找出空格的数量
        int SpaceCount = 0;//记录空格的数量
        for (int i=0;i<length;i++){
            if (str[i] == ' ') {
                SpaceCount++;
            }
        }
        for (int i=length-1;i>=0;i--){
            if (str[i]!= ' ') {
                str[i+2*SpaceCount] = str[i];
            }
            else{
                SpaceCount--;
                str[i+2*SpaceCount] = '%';
                str[i+2*SpaceCount+1] = '2';
                str[i+2*SpaceCount+2] = '0';
            }
        }
	}
};