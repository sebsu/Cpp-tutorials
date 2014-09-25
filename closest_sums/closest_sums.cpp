#include <iostream>
#include <vector>
#include <limits>
#include <cstdlib>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  int cases = 1;
  int n;
  while(cin >> n){
    vector<int> m;
    m.reserve(n);
    for(int i=0; i<n; ++i){
      cin >> m[i];
    }
    int queries;
    cin >> queries;
    cout <<  "Case " << cases << ":\n";
    for(int i=0; i<queries; ++i){
      int query;
      cin >> query;
      int closest = numeric_limits<int>::max();
      for(int j=0; j<n; ++j){
	if(closest == query){
	  break;
	}
	for(int k=0; k<n; ++k){
	  if(k==j){
	    continue;
	  }
	  int sum = m[j]+m[k];
	  if(abs(query-sum) < abs(query-closest)){
	    closest = sum;
	  }
	}
      }
      cout << "Closest sum to " << query << " is " << closest << ".\n";
    }
    ++cases;
  }

  return 0;
}
