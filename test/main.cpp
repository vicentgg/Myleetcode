#include<iostream>
#include<vector>

using namespace std;

int main(void) {
    vector<int> test{0,1,2,3,4,5};
    vector<int> copy(test.begin(),test.begin() + 2);

    vector<int>::iterator it = copy.begin();
    for(; it != copy.end(); it ++) {
        cout << *it << endl;
    }

    return 0;
}