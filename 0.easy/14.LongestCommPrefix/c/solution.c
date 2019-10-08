// 解题思路：
// 纵向扫描
// flower
// flow
// flight
// 从下标为0开始，扫描每个字符串是否相同，直到找到所有字符串不同的那个下标，即确定了最长公共子串

#include "string.h"
#include "stdio.h"

char * longestCommonPrefix(char** strs, int strsSize){
    char tmp_str;
    int tmp_pos;
    char* rs = (char*)malloc(128);
    memset(rs, 0, 128);
    if (strsSize == 0)
        return rs;
    if (strsSize == 1) {
        return *(strs);
    }
    int i, j = 0;
    while(1) {
        i = 0;
        while(i < strsSize - 1) {
            if (strs[i][j] == '\0' || strs[i][j] != strs[i+1][j])
                return rs;
            i++;
        }
        rs[j] = strs[0][j];
        j++;
    }
    return rs;
}
void main() {
    char *strs[] = {"flower", "flow", "flight"};
    //char** strs = strss;
    char* result = longestCommonPrefix(strs, 3);
    printf("result is %s\n", result);
}

