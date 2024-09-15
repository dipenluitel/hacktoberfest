/* ____                       _  __                     _       _       _       
  |  _ \ _ __ ___ _ __ ___   | |/ /__ _ _ __ ___   __ _| |     | | __ _(_)_ __  
  | |_) | '__/ _ \ '_ ` _ \  | ' // _` | '_ ` _ \ / _` | |  _  | |/ _` | | '_ \ 
  |  __/| | |  __/ | | | | | | . \ (_| | | | | | | (_| | | | |_| | (_| | | | | |
  |_|   |_|  \___|_| |_| |_| |_|\_\__,_|_| |_| |_|\__,_|_|  \___/ \__,_|_|_| |_|
*/                                                                            

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define debug(x); cout<<#x<<" "<<x<<endl;
ll hell=1e9+7;

void solve()
{
    ll n;
    cin>>n;
    vector<vector<char>> grid(n,vector<char> (n));
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }

    if(grid[n-1][n-1]=='*'){
        cout<<"0"<<endl;
        return ;
    }
    
    vector<vector<ll>> dp(n,vector<ll> (n,0));
    dp[0][0]=1;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            if(i>0){
                dp[i][j]+=dp[i-1][j];
            }
            if(j>0){
                dp[i][j]+=dp[i][j-1];
            }

            if(grid[i][j]=='*'){
                dp[i][j]=0;
            }
            dp[i][j]%=hell;
        }
    }
    cout<<dp[n-1][n-1]<<endl;
    return ;
}

int main()
{
    solve();
    return 0;
}