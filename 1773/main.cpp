#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int count = 0,pos;
        if(ruleKey == "type")pos = 0;
        else if(ruleKey == "color")pos = 1;
        else pos = 2;
        for(int i = 0; i < items.size(); i++){
            if(items[i][pos] == ruleValue) count++;
        }
        return count;
    }
};

int main(){

}