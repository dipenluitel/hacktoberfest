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
    int n;
    cin>>n;
    vector<pair<ll,ll>> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].first;
        v[i].second=i+1;
    }
    sort(v.begin(),v.end());
    ll ans=0;
    for(ll i=0;i<n;i++){
        int j=i;
        while(j+1<n && v[j+1].second>v[j].second){
            j++;
        }
        i=j;
        ans++;
    }
    cout<<ans<<endl;
    return ;
}

int main()
{
    int t;
    // cin>>t;
    t=1;
    while(t--)
        solve();
    return 0;
}