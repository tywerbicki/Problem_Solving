#include <iostream>
#include <string>
#include <vector>

using namespace std;
 
bool Make_Word(const string &word, const vector<string> &subs) {
    
    int size = word.size();
    if (size == 0) {return true;}

    bool found = false;
    int sub_size;
    string front, back;
    for (auto sub : subs) {
        
        sub_size =  sub.size();
        if (sub_size > size) { continue; }
        
        front = word.substr(0, sub_size);
        if (sub == front) {
            found = Make_Word(word.substr(sub_size), subs);
            if (found) { return true; }
        }
        
        back = word.substr(size - sub_size);
        if (sub == back) {
            found = Make_Word(word.substr(0, size - sub_size), subs);
            if (found) { return true; }
        }
    }

    return found;
}

int main() {

    string s = "Mississippi";
    vector<string> subs = {"ubge", "M", "iss", "i", "p", "lol"};

    bool result = Make_Word(s, subs);

    cout << result << endl;

    return 0;
}