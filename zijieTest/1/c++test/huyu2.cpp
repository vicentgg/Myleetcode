#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<int>> reAns(int t, vector<vector<vector<int>>>& infos, vector<pair<int,int>>& athinfo) {
        vector<vector<int>> ans(t);
        for(int i = 0; i < t; i ++) {
            vector<vector<int>>& vec = infos[i];
            int athNum = athinfo[i].first;
            vector<unordered_set<int>> count(athNum);

            for(int j = 0; j < vec.size(); j ++) {
                vector<int>& sb = vec[j];

                int len = sb.size();
                unordered_set<int> mset;
                for(int k = len - 1; k >= 1; k --) {
                    count[sb[k] - 1].insert(mset.begin(), mset.end());
                    mset.insert(sb[k]);
                }
            }

            vector<int> subans;
            for(int j = athNum - 1; j >= 0; j --) {
                int k;
                for(k = 0; k < athNum; k ++) {
                    if(count[k].size() == j) {
                        subans.push_back(k+1);
                        break;
                    }
                }
                if(k == athNum) {
                    subans.clear();
                    break;
                }
            }

            ans[i] = subans;


        }
        return ans;
    }
};

int main(void) {
    int t;
    cin >> t;
    vector<pair<int,int>> athinfo(t);
    vector<vector<vector<int>>> infos(t);
    for(int i = 0; i < t; i ++) {
        cin >> athinfo[i].first >> athinfo[i].second;
        vector<vector<int>> vec(athinfo[i].second);

        for(int j = 0; j < athinfo[i].second; j ++) {
            int temp;
            cin >> temp;
            vector<int> sb(temp+1);
            sb[0] = temp;
            for(int k = 1; k <= temp; k ++) cin >> sb[k];
            vec[j] = sb;
        } 

        infos[i] = vec;
    }

    Solution solution;
    vector<vector<int>> ans = solution.reAns(t, infos, athinfo);
    for(int i = 0; i < t; i ++) {
        if(ans[i].size() == 0) cout << "N0" << endl;
        else {
            for(int j = 0; j < ans[i].size(); j ++) cout << ans[i][j] << ' ';
            cout << endl;
        }
    }

    return 0;


}