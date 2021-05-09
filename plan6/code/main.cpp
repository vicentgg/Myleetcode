#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    vector<string> record;
    int count = 1;
    void wirteRecord(string message) {
        string re;
        string time;
        string num;

        if(message.substr(0,5) == "check") {
            if(message.substr(5,2) == "in") {

                if(message.substr(8,2) == "-t" && message.substr(17,2) == "-n" ) {
                    time = message.substr(11,6);
                    num = message.substr(20,6);
                    re = "Record" + num + " " + time.substr(0,2) + ":" + time.substr(2,2) + ":" + time.substr(4,2) + " in";
                }
                else {
                    re = "error";
                }
            }
            else if(message.substr(5,3) == "out") {

                if(message.substr(9,2) == "-t" && message.substr(18,2) == "-n" ) {
                    time = message.substr(12,6);
                    num = message.substr(21,6);
                    re = "Record"  + num + " " + time.substr(0,2) + ":" + time.substr(2,2) + ":" + time.substr(4,2) + " out";
                
                }
                else {
                    re = "error";
                }
            }
            else {
                re = "error";
            }

            record.push_back(re);
        }

        
    }
};

int main(void) {
    string s;

    Solution solution;

    s="checkin -t=222222 -n=at2121";
    // cin >> s;
    solution.wirteRecord(s);


    for(auto re : solution.record) {
        for(auto r : re) {
            cout << r;
        }
        cout << endl;
    }

    return 0;

}