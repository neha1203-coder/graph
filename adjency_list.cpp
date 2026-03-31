#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n = 5; // nodes
    vector<int> adj[n];

        // edges
    adj[0].push_back(11);
    adj[1].push_back(39);

    adj[0].push_back(47);
    adj[2].push_back(83);

    for(int i=0;i<n;i++){
        cout << i << " -> ";
        for(int j: adj[i]){
            cout << j << " ";
        }
        cout << endl;
    }
}