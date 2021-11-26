/** 
* @author      : Jackson Fernando Merma Portocarrero (jmermap@unsa.edu.pe)
* @created     : 25/11/2021
* @filename    : solution
* @description : _
* https://open.kattis.com/problems/maxloot
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define PI 3.1415926535897932384626

void solve(){
	ll n;
	ll C;
	cin>>n>>C;
	vector<ll> values(n);

	for(ll i=0;i<n;i++)
		cin>>values[i];

	vector<ll> costs(n);
	for(ll i=0;i<n;i++)
		cin>>costs[i];

	vector<vector<ll>> data(n+1, vector<ll>(C+1));

	for(ll i=0;i<=n;i++){
		for(ll u=0;u<=C;u++){
			if(i==0||u==0){
				data[i][u]=0;
			}else if(costs[i-1]<=u){
				data[i][u]=max(values[i-1]+data[i-1][u-costs[i-1]],data[i-1][u]);
			}else{
				data[i][u]=data[i-1][u];
			}
		}
	}
	cout<<data[n][C]<<endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;cin>>n;

	while(n--)
		solve();

	return 0;
}

