#include "RomanToInteger.h"
using namespace std;

int RomanToInteger::romanToInt(string s) {
    map<char, int> Map;
    Map['I'] = 1;
    Map['V'] = 5;
    Map['X'] = 10;
    Map['L'] = 50;
    Map['C'] = 100;
    Map['D'] = 500;
    Map['M'] = 1000;
        
    int rs = 0;
    int len = s.size();
        
    for(int i = 0; i < len-1; i++) {
        int cur = Map[s.at(i)];
        int next = Map[s.at(i+1)];
        if (cur >= next) {
            rs += cur;
        } else {
            rs -= cur;
        }
    }
        
    rs += Map[s[len-1]];
        
    return rs;
}

int main() {
    string str = "LVIII";
    RomanToInteger roman;
    int result = roman.romanToInt(str);
    cout << "result " << result << endl;
    return 0;
}
