#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Return array of numbers that sum to target_sum,
// where each array element is contained in the given array arr.

vector<int> How_Sum(const int target_sum, const vector<int> &arr, unordered_map<int, vector<int>> &cache)
{
    if (target_sum == 0)
    {   return vector<int> {};  } 
    if (target_sum < 0)
    {   return vector<int> {-1};  }
    if (cache.find(target_sum) != cache.end())
        {   return cache.at(target_sum);    }
        
    int remainder;
    vector<int> result;
    for (auto i : arr)
    {
        remainder = target_sum - i;
        result = How_Sum(remainder, arr, cache);
        if (find(result.begin(), result.end(), -1) == result.end())
        {   
            result.push_back(i); 
            cache[remainder] = result; 
            break;  
        } else {
            cache[remainder] = result;
        }
    }
    return result;
}

int main()
{
    int sum = 84;
    vector<int> row = {35, 14, 15, 12};
    unordered_map<int, vector<int>> record;

    for (auto i : How_Sum(sum, row, record))
    {   cout << i << " ";   }
    cout << endl << endl;

    for (auto &i : record)
    {   
        for (auto j : i.second)  
        {   cout << j << " ";  }
        cout << endl;
    }

    return 0;
}