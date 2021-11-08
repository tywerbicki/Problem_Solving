#include <iostream>
#include <algorithm>

using namespace std;

template <class T>
struct node_t {
    T val;
    node_t<T> *left, *right;
};

template <class T>
T Max_Root_To_Leaf_Sum(node_t<T> *root) {

    T left, right;
    if (root->left) {
        left = Max_Root_To_Leaf_Sum(root->left); }
    else { left = 0; }
    if (root->right) {
        right = Max_Root_To_Leaf_Sum(root->right); }
    else { right = 0; } 

    return root->val + max(left, right);
}

int main() {

    node_t<int> node1 = {5, NULL, NULL} ;
    node_t<int> node2 = {11, NULL, NULL} ;
    node_t<int> node3 = {3, NULL, NULL} ;
    node_t<int> node4 = {4, NULL, NULL} ;
    node_t<int> node5 = {2, NULL, NULL} ;
    node_t<int> node6 = {1, NULL, NULL} ;
    node_t<int> node7 = {3, NULL, NULL} ;
    
    node1.left = &node2;
    node1.right = &node3;
    node2.left = &node4;
    node2.right = &node5;
    node3.right = &node6;
    node5.right = &node7;

    /*         5
              / \ 
            11   3
            /\    \
           4  2    1  
               \
                3
    */

    int max_sum = Max_Root_To_Leaf_Sum<int>(&node1);

    cout << "Max sum: " << max_sum << endl;

    return 0;
}
