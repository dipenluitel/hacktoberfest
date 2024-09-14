#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int binarysearch(int arr[], int n, int k) {
        int l = 0;
        int r = n-1;
      
        for(int i=0;i<n;i++){
            int mid = (l+r)/2;
            if(k>arr[mid])
                l = mid+1;
            else if(k<arr[mid])
                r = mid-1;
            else
                return mid;
        }
        return -1;
    }
};
int main() {
    int t;
    cin >> t;

    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];
        int key;
        cin >> key;
        Solution ob;
        int found = ob.binarysearch(arr, N, key);
        cout << found << endl;
    }
}
