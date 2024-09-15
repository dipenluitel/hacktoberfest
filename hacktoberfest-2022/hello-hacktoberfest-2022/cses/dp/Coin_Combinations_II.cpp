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

int main(){
	ll n,x;
	cin>>n>>x;
	vector<int> coins(n);
	for(int i=0;i<n;i++){
		cin>>coins[i];
	}
	ll dp[1000001];
	dp[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=x;j++){
			if(j-coins[i-1]>=0){
				dp[j]+=dp[j-coins[i-1]];
				dp[j]=dp[j]%hell;
			}
		}
	}
	cout<<dp[x]<<endl;
	return 0;
}