#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

class Solution {
private:
    int w = 0;
    int h = 0;
public:

    Solution(int w, int h) : w(w), h(h) {} 

    int getArea() {
        return w * h;
    }

    int getW() {
        return w;
    }

    int getH() {
        return h;
    }

    double getScale() {
        return min(w/double(h), h/double(w));
    }

};

bool cmp(Solution a, Solution b) {
    if(a.getArea() != b.getArea()) {
        return a.getArea() < b.getArea();
    }
    else {
        if( a.getScale() != b.getScale()) {
            return a.getScale() > b.getScale();
        }
        else {
            return a.getW() < b.getW();
        }
    }
}

int main(void) {
    int n;
    cin >> n;
    vector<Solution> nums;
    for(int i = 0; i < n; i ++) {
        int w;
        int h;
        cin >> w;
        cin >> h;
        Solution s(w,h);
        nums.push_back(s);
    }

    sort(nums.begin(), nums.end(), cmp);

    for(auto it : nums) {
        cout << it.getW() << it.getH() << " "; 
    }

    return 0;
}