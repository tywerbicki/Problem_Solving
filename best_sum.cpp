#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Return array of numbers that sum to target_sum,
// where each array element is contained in the given array arr.

vector<int> Best_Sum(const int target_sum, const vector<int> &arr, unordered_map<int, vector<int>> &cache)
{
    if (target_sum == 0)
    {   return vector<int> {};  } 
    if (target_sum < 0)
    {   return vector<int> {-1};  }
    if (cache.find(target_sum) != cache.end())
        {   return cache.at(target_sum);    }
        
    int remainder; 
    vector<int> result, null = {-1}, shortest_path = {-1};
    for (auto i : arr)
    {
        remainder = target_sum - i;
        result = Best_Sum(remainder, arr, cache);
        if (result != null)
        {   
            result.push_back(i);
            if (shortest_path == null || result.size() < shortest_path.size())
            {   shortest_path = result; }
        }
    }
    cache[target_sum] = shortest_path;
    return shortest_path;
}

int main()
{
    int sum = 8;
    vector<int> row = {1, 4, 5};
    unordered_map<int, vector<int>> record;

    for (auto i : Best_Sum(sum, row, record))
    {   cout << i << " ";   }
    cout << endl << endl;

    for (auto &i : record)
    {   
        cout << i.first << ": ";
        for (auto j : i.second)  
        {   cout << j << " ";  }
        cout << endl;
    }

    return 0;
}