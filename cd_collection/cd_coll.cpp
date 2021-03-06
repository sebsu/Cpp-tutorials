#include <iostream>
#include <vector>
#include <time.h>

using namespace std;



void calc_same(int jack, int jill){
  ios_base::sync_with_stdio(false);
  int cd;
  int same = 0; 
  int jack_i = 0; //jack's index
  vector<int> jack_cds;
  jack_cds.reserve(jack);

  for(int i=0; i<jack; ++i){
    cin >> jack_cds[i];
  }
  
  for(int i=0; i<jill; ++i){ //For as many cds as Jill have
    cin >> cd;               // find what cd it is
    while(cd>jack_cds[jack_i] && jack_i<jack-1){
      ++jack_i; //Increment until we find it or come to end of collection.
    }
    if(cd==jack_cds[jack_i]){//compare it with Jack's
      ++same;                // and increment if the same.
      if(jack_i<jack-1){//As long as we are in Jack's cd collection
	++jack_i;                  // increment the index.
      }
    }    
  }

  cout << same << endl;
}

int main (){
  std::ios_base::sync_with_stdio(false);
  int jack, jill;
  double begin = (double)clock()*1000;
  while(cin >> jack && cin >> jill && !(jack==0 && jill==0)){
    calc_same(jack, jill);
  }
  cout << "\n" << ((double)clock()*1000-begin)/CLOCKS_PER_SEC;
  return 0;
}
