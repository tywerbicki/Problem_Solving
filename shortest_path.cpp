#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <utility>

using namespace std;

template<class T>
using A_List_t = unordered_map<T, unordered_set<T>>;

template<class T1 = char>
int Shortest_Path(A_List_t<T1>& a, const T1 start, const T1 end) {

    unordered_set<T1> cache;
    pair<T1, int> current_node, tmp, first = {start, 0};
    queue<pair<T1, int>> q; q.push(first); cache.insert(start);
    while (! q.empty()) {
        current_node = q.front(); q.pop();
        if (current_node.first == end) { return current_node.second; }
        for (const auto neighbour : a[current_node.first]) {
            tmp = {neighbour, current_node.second + 1};
            if (cache.find(tmp.first) != cache.end()) { continue; }
            else { cache.insert(tmp.first); }
            q.push(tmp);
        }
    }
    return -1;
}

template<class T1 = char>
A_List_t<T1> Generate_AL(vector<vector<T1>>& ud) {

    A_List_t<T1> al;
    for (auto edge : ud) {
        al[edge[0]].insert(edge[1]);
        al[edge[1]].insert(edge[0]);
    }
    return al;
}

int main() {

    vector<vector<char>> edge_list;
    edge_list.push_back({'w', 'x'});
    edge_list.push_back({'x', 'y'});
    edge_list.push_back({'z', 'y'});
    edge_list.push_back({'z', 'v'});
    edge_list.push_back({'w', 'v'});

    A_List_t<char> a_list = Generate_AL(edge_list);

    int shortest_path = Shortest_Path(a_list, 'w', 'z');

    cout << "Shortest path: " << shortest_path << endl;

    return 0;
}