#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int panduanNum(string s) {
        int count = 0;

        int len = s.length();

        if(len == 0) {
            return 1;
        }
        else if(len == 1) {
            return 4;
        }

        for(int i = 0,j = 1; i < len || j < len;) {
            char c = s[i];
            char behind = s[j];

            if(c == '%') {
                if(j == i + 1){
                    count += 3;   
                }
                if(behind == 's') {
                    count += 3;
                }
                else if(behind == 'd') {
                    count += 4;
                }
                else if(behind == 'u') {
                    count += 5;
                }
                else if(behind == 'p') {
                    count += 6;
                }
                else if(behind == 'f') {
                    count += 7;
                }
                else if(behind >= '0' && c <= '9') {
                    count += 8;
                    j ++;
                    continue;
                }
                else if(behind == '%') {
                    count += 9;
                }
                else if(behind == '\0') {
                    count += 0;
                }
                else {
                    count += 10;
                }

                i = j + 1;
                j = i + 1;
            }
            else {
                count += 3; 
                i ++;
                j = i+1;
            }
            
        }

        count ++;


        return count;

    }
};

int main(void) {
    int num;
    
    cin >> num;

    vector<string> strs;
    
    for(int i = 0; i < num; i ++) {
        string s;
        cin >> s;

        strs.push_back(s);
    }

    Solution solution;

    for(int i = 0; i < num; i ++) {
        int count = solution.panduanNum(strs[i]);
        cout << count << endl;
    }

    return 0;
}