#include <iostream>
#include <cstddef>
#include <queue>
#include <string>
#include <cstdlib>
#include <vector>
#include <map>

using namespace std;

static map<int,vector<int>> graph;

void findPath(int a, int b) {
    vector<int> children = graph[a];

    for (int i = 0; i < children.size(); ++i) {
        if (children[i] == b) {
            cout << a << "," << b << endl;
            break;
        }
    }

    for (int j = 0; j < children.size(); ++j) {
        findPath(children[j], b);
    }
}

int main(){
    string edgeString;
    int count;
    cin >> count;

    int parent, child;
    while(count-- > 0) {
        cin >> parent;
        cin >> child;

        vector<int> children = graph[parent];
        children.push_back(child);
    }

    int queries;
    cin >> queries;

    int a, b;
    while(queries-- > 0) {
        cin >> a;
        cin >> b;

        findPath(a, b);
    }


    cout << endl;
}
