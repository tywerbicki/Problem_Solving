#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

typedef vector<vector<char>> map_t;
typedef unordered_set<string> cache_t;

int Traverse(map_t& map, const int nrow, const int ncol, const int loc_r, const int loc_c, cache_t& cache) {

    if ( (loc_r < 0 || loc_r == nrow) || (loc_c < 0 || loc_c == ncol) ) { return 0; }
    if (map[loc_r][loc_c] == 'W') { return 0; }
    string loc = to_string(loc_r) + "," + to_string(loc_c);
    if (cache.find(loc) != cache.end()) { return 0; }

    cache.insert(loc);
    int count = 1;
    count += Traverse(map, nrow, ncol, loc_r - 1, loc_c, cache);
    count += Traverse(map, nrow, ncol, loc_r + 1, loc_c, cache);
    count += Traverse(map, nrow, ncol, loc_r, loc_c -1, cache);
    count += Traverse(map, nrow, ncol, loc_r, loc_c +1, cache);

    return count;
}

int Minimum_Island(map_t& map) {

    cache_t cache;
    int nrow = map.size(), ncol = map[0].size();
    int island_size, smallest = -1;

    for (size_t i = 0; i < nrow; i++)
    {
        for (size_t j = 0; j < ncol; j++)
        {
            if (map[i][j] == 'L')
            {
                string loc = to_string(i) + "," + to_string(j);
                if (cache.find(loc) == cache.end()) {
                    island_size = Traverse(map, nrow, ncol, i, j, cache);
                    if (island_size < smallest || smallest < 0) {
                        smallest = island_size;
                    }
                }
            }
        }
    }
    return smallest;
}

int main() {

    map_t map;
    map.push_back( {'W', 'L', 'W', 'W', 'L', 'W'} );
    map.push_back( {'L', 'L', 'W', 'W', 'L', 'W'} );
    map.push_back( {'W', 'L', 'W', 'W', 'W', 'W'} );
    map.push_back( {'W', 'W', 'W', 'L', 'L', 'W'} );
    map.push_back( {'W', 'W', 'W', 'L', 'L', 'W'} );
    map.push_back( {'W', 'W', 'W', 'L', 'W', 'W'} );

    int smallest_island = Minimum_Island(map);

    cout << "Smallest island: " << smallest_island << endl;

    return 0;
}
