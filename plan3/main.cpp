#include<iostream>
#include<vector>

using namespace std;

class Player{
private:
    int x;
    int y;
    int m;
    int n;
public:
    Player(int x, int y, int m, int n) : x(x), y(y), m(m), n(n){}

    void move(int length, char dir) {
        if(dir == 'W') {
            y += length;
            if(y > n) y = n; 
        }
        else if(dir == 'S') {
            if(y < length) {
                y = 1;
            } else {
                y -= length;
            }
        }
        else if(dir == 'A') {
            if(x < length) {
                x = 1;
            } else {
                x -= length;
            }
        }
        else if(dir == 'D') {
            x += length;
            if(x > m) x = m;
        }
    }
    
    int getX() {
        return x;
    }

    int getY() {
        return y;
    }
};

class Operator {
    friend Player;
private:
    int player_num;
    int time;
    int length;
    char dir;
public:
    Operator(int p, int t, int l, char d) : player_num(p), time(t), length(l), dir(d) {}

    void doWork(int t, Player player) {
        if(t == time) {
            player.move(length,dir);
        }
    }

    int getNum() {
        return player_num;
    }

};

int main(void) {
    int m,n,x,y,r;

    cin >> m;
    cin >> n;
    cin >> x;
    cin >> y;
    cin >> r;

    int d = x + r;
    int a = x - r;
    int w = y + r;
    int s = y - r;
    if(d >= m) d = m;
    if(r >= x) a = 1;
    if(w >= n) w = n;
    if(r >= y) s = 1;

    int k;
    cin >> k;
    vector<Player> others;

    while(k) {
        int kx,ky;
        cin >> kx;
        cin >> ky;
        Player other(kx,ky,m,n);
        others.push_back(other);
        --k;
    }

    int c; //其他玩家操作数
    cin >> c;
    vector<Operator> ops;

    while(c) {
        int pNum;
        int time;
        int length;
        char dir;
        cin >> pNum;
        cin >> time;
        cin >> length;
        cin >> dir;
        Operator op(pNum-1,time,length,dir);
        ops.push_back(op);
        --c;
    }

    int timeNum;
    cin >> timeNum;
    vector<int> timeCount;
    while(timeNum) {
        int t;
        cin >> t;
        timeCount.push_back(t);
        -- timeNum;
    }

    for(int i = 0; i < timeCount.size(); i ++) {
        int count = 0;
        for(int j = 0; j < ops.size(); j ++) {
            ops[j].doWork(timeCount[i],others[ops[j].getNum()]);
        }

        for(int j = 0; j < others.size(); j ++) {
            if(others[j].getX() >= a && others[j].getX() <= d
               &&  others[j].getY() >= s && others[j].getY() <= w) {
                   count ++;
            }
        }

        cout << count << " ";
    }

   

    return 0;

}