#include <stdio.h>

void main() {
    char *roman = "MCMXCIV";
    int result = romanToInt(roman);
    printf("result is %d\n", result);
}

// 解题思路：从左到右扫描，如果右边的数不大于当前的，则加上该数；如果右边大于当前的，则减去该数
// 罗马字母和十进制数字用一个数组做映射，数组的下标为字母的ASCII码的值的取16进制的低位（这个设计很巧妙）

int romanToInt(char * s){
    int nums[15] = {0};
                    //十进制：十六进制：二进制
    nums[9]  = 1;   //I:73:0X49:1001
    nums[6]  = 5;   //V:86:0X56:0110
    nums[8]  = 10;  //X:88:0X58:1000
    nums[12] = 50;  //L:76:0X4C:1011
    nums[3]  = 100; //C:67:0X43:0011
    nums[4]  = 500; //D:68:0X44:0100
    nums[13] = 1000;//M:77:0X4D:1101
    for(unsigned char i = 0;s[i] != '\0';i++) {
        if(nums[s[i] & 0xf] >= nums[s[i+1] & 0xf])
            nums[1] += nums[s[i] & 0xf];
        else
            nums[1] -= nums[s[i] & 0xf];
    }
    return nums[1];
}

// 暴力解法
// 对不同的模式去做识别，模式包括如下：
// IV IX I*
// XL XC X*
// CD CM C*
// V*
// L*
// D*
// M*
int romanToInt2(char * s){
    
    int rs = 0;
        
    for(int i = 0; s[i] != '\0';) {
        
        char tmp = s[i];
        printf("the %d number is %c\n", i, &tmp);
        
        if (tmp == 'I') {
            if (s[i+1] == '\0') {// last one
                rs += 1;
                i++;
                printf("case 00\n");
                continue;
            } else if (s[i+1] == 'V') {// IV
                rs += 4;
                i += 2;
                printf("case 01\n");
                continue;
            } else if (s[i+1] == 'X') {// IX
                rs += 9;
                i += 2;
                printf("case 02\n");
                continue;
            } else {// I+anything
                rs += 1;
                i++;
                printf("case 03\n");
                continue;
            }
        }

        if (tmp == 'X') {
            if (s[i+1] == '\0') {// last one
                rs += 10;
                i++;
                printf("case 10\n");
                continue;
            } else if (s[i+1] == 'L') {// XL
                rs += 40;
                i += 2;
                printf("case 11\n");
                continue;
            } else if (s[i+1] == 'C') {// XC
                rs += 90;
                i += 2;
                printf("case 12\n");
                continue;
            } else {// X+anything
                rs += 10;
                i++;
                printf("case 13\n");
                continue;
            }
        }

        if (tmp == 'C') {
            if (s[i+1] == '\0') {// last one
                rs += 100;
                i++;
                printf("case 20\n");
                continue;
            } else if (s[i+1] == 'D') {// CD
                rs += 400;
                i += 2;
                printf("case 21\n");
                continue;
            } else if (s[i+1] == 'M') {// CM
                rs += 900;
                i += 2;
                printf("case 22\n");
                continue;
            } else {// C+anything
                rs += 100;
                i++;
                printf("case 23\n");
                continue;
            }
        }
        
        if(tmp == 'V') {// V
            rs += 5;
            i++;
            printf("case 30\n");
        } else if(tmp == 'L') {// L
            rs += 50;
            i++;
            printf("case 40\n");
        } else if(tmp == 'D') {// D
            rs += 500;
            i++;
            printf("case 50\n");
        } else if(tmp == 'M') {// M
            rs += 1000;
            i++;
            printf("case 60\n");
            continue;
        } else {
            // error number
            printf("case 70\n");
            continue;
        }
    }
    
    return rs;
}
