#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

template<class T>
using A_List_t = unordered_map<T, unordered_set<T>>;

template<class T1 = char>
A_List_t<T1> Generate_AL(vector<vector<T1>>& ud) {

    A_List_t<T1> al;
    for (auto edge : ud) {
        al[edge[0]].insert(edge[1]);
        al[edge[1]].insert(edge[0]);
    }
    return al;
}

// Performing depth-first search.
template<class T1 = char>
bool Found_Depth_Path(A_List_t<T1>& a, const T1 start, const T1 end) {

    if (start == end) {return true; }
    static unordered_set<T1> cache;
    if (cache.find(start) != cache.end()) {
        return false; 
    } else { cache.insert(start); }

    for (auto i : a[start]) {
        if (Found_Depth_Path(a, i, end)) { return true; }
    }

    return false;
}

int main() {

    vector<vector<char>> edge_list;
    edge_list.push_back({'i', 'j'});
    edge_list.push_back({'k', 'i'});
    edge_list.push_back({'m', 'k'});
    edge_list.push_back({'k', 'l'});
    edge_list.push_back({'o', 'n'});

    A_List_t<char> a_list = Generate_AL(edge_list);

    cout << "i to m: " << Found_Depth_Path(a_list, 'i', 'm') << endl;
    cout << "o to k: " << Found_Depth_Path(a_list, 'b', 'a') << endl;

    //// View undirected edge list.
    //for (auto i : edge_list) {
    //    for (auto j : i) {
    //        cout << j << " ";
    //    }
    //    cout << endl;
    //}

    // View adjacency list.
    //for (auto i : a_list) {
    //    cout << i.first << ": ";
    //    for (auto j : i.second) {
    //        cout << j << ",";
    //    }
    //    cout << endl;
    //}

    return 0;
}