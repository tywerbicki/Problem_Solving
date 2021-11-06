#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <forward_list>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;

template<class T = char>
using adjacency_list_t = unordered_map<T, forward_list<pair<T, int>>>;

template<class T = char>
struct compare_node {
    bool operator()(const pair<T, int>& a, const pair<T, int>& b) {
        return a.second > b.second;
    }
};

template<class T1 = char>
vector<T1> Retrace_Steps(unordered_map<T1, T1>& previous, const T1 start, const T1 end) {

    vector<T1> steps; steps.reserve(previous.size() + 1);
    steps.push_back(end);
    while ( *(steps.end()-1) != start ) {
        steps.push_back(previous[*(steps.end()-1)]);
    } 
    reverse(steps.begin(), steps.end()); 
    return steps;
} 

template<class T1 = char>
pair<int, vector<T1>> Apply_Dijkstra(adjacency_list_t<T1>& al, const T1 start, const T1 end) {

    unordered_map<T1, int> cache;
    unordered_set<T1> visited;
    unordered_map<T1, T1> previous;
    priority_queue<pair<T1, int>, vector<pair<T1, int>>, compare_node<T1>> pq;
    cache[start] = 0; pq.push(pair<T1, int> { start, 0 });
    pair<T1, int> tmp;
    T1 name; int total_cost;

    while (! pq.empty()) {

        tmp = pq.top(); pq.pop();

        if (cache.find(tmp.first) != cache.end()) {
            if (cache[tmp.first] < tmp.second) { continue; }
        }
        visited.insert(tmp.first);

        for (const auto& neighbour : al[tmp.first]) {
            name = neighbour.first; 
            total_cost = cache[tmp.first] + neighbour.second;
            if (visited.find(name) != visited.end()) { continue; }
            if (name == end) { 
                previous[end] = tmp.first;
                pair<int, vector<T1>> result;
                result.first = total_cost;
                result.second = Retrace_Steps<T1>(previous, start, end);
                return result;
            }
            
            if (cache.find(name) != cache.end()) {
                if (total_cost >= cache[name]) {
                    continue; }
            } 
            cache[name] = total_cost;
            pq.push(neighbour);
            previous[name] = tmp.first;
        }
    }
    return pair<int, vector<T1>> {-1, {}};
}

int main() {

    adjacency_list_t<int> a_list;
    a_list[0] = { {1, 4}, {2, 1} };
    a_list[1] = { {3, 1} };
    a_list[2] = { {1, 2}, {3, 5} };
    a_list[3] = { {4, 3} };
    a_list[4] = { };

    pair<int, vector<int>> lowest_cost = Apply_Dijkstra<int>(a_list, 0, 4);

    cout << "Lowest cost: " << lowest_cost.first << endl;
    cout << "Path travelled: ";
    for (auto& i : lowest_cost.second) { cout << i << " "; }
    cout << endl;

    return 0;
}