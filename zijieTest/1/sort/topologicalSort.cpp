#include<iostream>
#include<vector>
#include<list>
#include<queue>

using namespace std;

//定义一个有向图
class Graph {
private:
    int V; //顶点个数
    list<int> *adj; //邻接表
    queue<int> q; //存放入度为0的顶点
    int *indegree; //存放每个顶点的入度值
public:
    //构造函数
    Graph(int v) {
        this ->V = v;
        
    }

};

int main(void) {

}