#include <iostream> 
using namespace std; 
 
int main() { 
    int tree[10]; 
    int n; 
 
    cout << "Enter number of nodes: "; 
    cin >> n; 
 
    cout << "Enter tree elements level-wise: "; 
    for (int i = 0; i < n; i++) { 
        cin >> tree[i]; 
    } 
 
    cout << "Complete Binary Tree Representation:\n"; 
 
    for (int i = 0; i < n; i++) { 
        cout << "Node: " << tree[i]; 
 
        int left = 2 * i + 1; 
        int right = 2 * i + 2; 
 
        if (left < n) 
            cout << ", Left Child: " << tree[left]; 
 
        if (right < n) 
            cout << ", Right Child: " << tree[right]; 
 
        cout << endl; 
    } 
 
    return 0; 
}  