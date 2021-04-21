#include<iostream>
#include<vector>
#include<numeric> //std::iota

using namespace std;

class Solution {
public:
    //按照题目所给的意思来
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> p(m);
        iota(p.begin(), p.end(), 1);

        vector<int> ans;

        for(int query: queries) {
            int pos = -1;
            for(int i = 0; i < m; i ++) {
                if(query == p[i]) {
                    pos = i;
                    break;
                }
            }

            ans.push_back(pos);
            p.erase(p.begin() + pos);
            p.insert(p.begin(), query);
        }

        return ans;
    }
};

int main(void) {

}