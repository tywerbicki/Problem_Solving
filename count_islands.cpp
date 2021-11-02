#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

template<class T>
using A_List_t = unordered_map<T, unordered_set<T>>;

template<class T1 = char>
void Traverse(A_List_t<T1>& a, const T1 start, unordered_set<T1>& cache) {

    if (cache.find(start) != cache.end()) { return; } 
    else { cache.insert(start); } 

    for (auto neighbour : a[start]) {
        Traverse(a, neighbour, cache);
    }
}

template<class T1 = char>
int Count_Islands(A_List_t<T1>& a) {

    unordered_set<T1> cache;
    T1 node;
    int count = 0;

    for (auto pair : a) {
        node = pair.first;
        if (cache.find(node) != cache.end()) { continue; }
        else { 
            count++;
            Traverse<T1>(a, node, cache); 
        }
    }
    return count;
}

int main() {

    A_List_t<int> a_list;
    a_list[0] = {8, 1, 5};
    a_list[1] = {0};
    a_list[5] = {0, 8};
    a_list[8] = {0, 5};
    a_list[2] = {3, 4};
    a_list[3] = {2, 4};
    a_list[4] = {3, 2};

    int count = Count_Islands<int>(a_list);
    cout << "Number of islands: " << count << endl;

    return 0;
}