#include <iostream>
#include <vector>
#include <limits>
#include <cstdlib>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  int cases = 1;
  int n;
  while(cin >> n && n!=0){ //Every time we get a new case
    vector<int> sums; //The vector where we store the int to sum
    sums.reserve(n);  //Reserve for speed
    for(int i=0; i<n; ++i){
      cin >> sums[i]; //Save the integers
    }
    int queries;
    cin >> queries; //Get the number of queries
    cout <<  "Case " << cases << ":\n"; //Some ugly print
    for(int i=0; i<queries; ++i){ //Loop while we still have queries
      int query; //What we should aim for
      cin >> query;
      int closest = 10000001; //A maximum value
      for(int j=0; j<n; ++j){
	for(int k=0; k<n; ++k){
	  if(k==j){
	    continue;
	  }
	  int sum = sums[j]+sums[k];
	  if(abs(query-sum) < abs(query-closest)){
	    closest = sum;
	    if(closest == query){
	      break;
	    }
	  }
	}
      }
      cout << "Closest sum to " << query << " is " << closest << ".\n";
    }
    ++cases;
  }

  return 0;
}
