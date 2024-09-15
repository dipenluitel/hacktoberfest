/* ____                       _  __                     _       _       _       
  |  _ \ _ __ ___ _ __ ___   | |/ /__ _ _ __ ___   __ _| |     | | __ _(_)_ __  
  | |_) | '__/ _ \ '_ ` _ \  | ' // _` | '_ ` _ \ / _` | |  _  | |/ _` | | '_ \ 
  |  __/| | |  __/ | | | | | | . \ (_| | | | | | | (_| | | | |_| | (_| | | | | |
  |_|   |_|  \___|_| |_| |_| |_|\_\__,_|_| |_| |_|\__,_|_|  \___/ \__,_|_|_| |_|
*/                                                                            

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define debug(x); cout<<#x<<"="<<x<<endl;
ll hell=1e9+7;

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> page(n),cost(n);
    for(int& it : cost){
        cin>>it;
    }
    for(int& it : page){
        cin>>it;
    }
    vector<vector<int>> dp(n+1,vector<int> (k+1,0));
    for(int i=1;i<=n;i++){
        for(int j=0;j<=k;j++){
            dp[i][j]=dp[i-1][j];
            if(j>=cost[i-1]){
                dp[i][j]=max(dp[i][j],dp[i-1][j-cost[i-1]]+page[i-1]);
            }
        }
    }
    cout<<dp[n][k]<<endl;
    return 0;
}