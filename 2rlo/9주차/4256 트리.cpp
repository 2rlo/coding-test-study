// BOJ 4256 트리 https://www.acmicpc.net/problem/4256

#include <iostream>

using namespace std;

int preorder[1001], inorder[1001], postorder[1001];

void ans(int pl, int ph, int il, int ih){
    if(pl > ph) return;
     
    int root = preorder[pl];
    int size = postorder[root] - il;

    ans(pl+1, pl+size, il, postorder[root]-1);
    ans(pl+size+1, ph, postorder[root]+1, ih);

    cout << root << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;  // testcase
    cin >> t;

    int n;  // node
    while(t--){
        cin >> n;
        for(int i=0; i<n; i++)
            cin >> preorder[i];
        for(int i=0; i<n; i++){
            cin >> inorder[i];
            postorder[inorder[i]] = i;
        }

        ans(0, n-1, 0, n-1);
        cout << "\n";
    }

    return 0;
}