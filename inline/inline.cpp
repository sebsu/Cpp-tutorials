#include <iostream>

using namespace std;


//The code in the inline function is pasted into the place where it's 
// called. This makes the program largeer but faster.
inline void hello(){
  cout << "Hello, World!" << endl;
}

int main(){
  hello();//Call it like a regular function
  return 0;
}
