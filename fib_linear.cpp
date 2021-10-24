#include <iostream>
#include <unordered_map>

using namespace std;

// Return Fibonacci number in linear time.

long Get_Fibonacci(const int n, unordered_map<int, long long> &record)
{

    if (record.find(n) != record.end())
    {   return record.at(n);  } 
    if (n == 1)
    {   return 0;   }
    if (n == 2)
    {   return 1;   }

    record[n] = Get_Fibonacci(n - 1, record) + Get_Fibonacci(n - 2, record);
    
    return record.at(n);
}

int main()
{   
    unordered_map<int, long long> store;
    long result = Get_Fibonacci(51, store);
    cout << "Result: " << result << endl;
}