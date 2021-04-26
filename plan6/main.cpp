#include<iostream>
#include<vector>

using namespace std;

struct Axis {
    int x;
    int y;
    int z;
};

class Soltuion {

public:
    //将网络变为一个三维坐标数组
    int length(int x, int y) {
        vector<Axis> nums;

        Axis start;
        start.x = 0;
        start.y = 0;
        start.z = 0;
        nums.push_back(start);

        for(int i = 0; i < x; i ++) {

        }

        for(int j = 0; j < y; j ++) {

        }
    }

};

int main(void) {
    int t;
    cin >> t;
    vector<int> xnum(t);
    vector<int> ynum(t);

    for(int i = 0; i < t; i ++) {
        cin >> xnum[i];
        cin >> ynum[i];
    }

    Soltuion s;

    // for(int i = 0; i < t; i ++) {
    //     cout << s.length(xnum[i], ynum[i]) << endl;
    // }
    return 0;
}