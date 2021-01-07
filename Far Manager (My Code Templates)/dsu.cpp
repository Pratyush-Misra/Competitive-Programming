#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ld long double
#define ar array
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
#define vt vector
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define fi first
#define se second

#define pii pair<int,int>
#define pll pair<ll,ll>

#define F_OR(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define EACH(x, a) for (auto& x: a)
 
template<class T> bool umin(T& a, const T& b) {
	return b<a?a=b, 1:0;
}

template<class T> bool umax(T& a, const T& b) { 
	return a<b?a=b, 1:0;
} 
 
mt19937 mt_rng(chrono::steady_clock::now().time_since_epoch().count());
const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};
const int N=1e5+5; 

vt<pii> edge(N);		// edge list
vt<int> spar(N,-1);
vt<int> srank(N,1);
int V,E;
int sfind(int i){					// path compressed sfind
	if(spar[i]==-1)	return i;
	else return spar[i]=sfind(spar[i]);
}

void sunion(int x,int y){			// union by rank
	int s1=sfind(x);
	int s2=sfind(y);
	if(s1!=s2){
		int r1=srank[s1];
		int r2=srank[s2];
		if(r1<r2){					
			srank[s2] += srank[s1];	// rank of r2 increases by an amt of rank of r1
			spar[s1] = s2;			// shift s1 under s2 since s1 wala chota hai s2 se
		}
		else{
			srank[s1] += srank[s2];	// rank of r1 increases by an amt of rank of r2
			spar[s2] = s1;			// shift s2 under s1 since s2 wala chota hai s2 se
		}
	}
}

bool cycle(){
	FOR(E){
		int x = edge[i].fi;
		int y = edge[i].se;
		int s1=sfind(x);
		int s2=sfind(y);
		if(s1!=s2)	sunion(s1,s2);
		else return true;
	}
	return false;
}

void solve(){
	
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
#ifdef LOCAL_DEFINE
	//freopen("input.txt","r",stdin);
	freopen("o.txt","w",stdout);
#endif

	int t=1;//	cin>>t;
	FOR(t) {
		//write("Case #", i+1, ": ");
		solve();
	}

#ifdef LOCAL_DEFINE
	cerr << endl << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s" << endl;
#endif
	return 0;
}
