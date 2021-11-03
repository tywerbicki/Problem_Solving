#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

template<class T>
using A_List_t = unordered_map<T, unordered_set<T>>;

template<class T1 = char>
int Traverse(A_List_t<T1>& a, const T1 start, unordered_set<T1>& cache) {

    if (cache.find(start) != cache.end()) { return 0; }
    else { cache.insert(start); }

    int count = 1;
    for (auto neighbour : a[start]) {
        count += Traverse(a, neighbour, cache);
    }
    return count;
}

template<class T1 = char>
int Largest_Island(A_List_t<T1>& a) {

    unordered_set<T1> cache;
    int island_size, largest_island = -1;
    T1 node;
    for (const auto& pair : a) {
        node = pair.first;
        if (cache.find(node) != cache.end()) { continue; }
        else { 
            island_size = Traverse(a, node, cache);
            if (island_size > largest_island) { largest_island = island_size; }
         }
    }
    return largest_island;
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

    int largest_island = Largest_Island<int>(a_list);

    cout << "Largest Island: " << largest_island << endl;

    return 0;
}