#include <iostream>

int fak_rec(int n){
  int x;
  if(n>1){
    x = n*fak_rec(n-1);
  }else{
    return 1;
  }
  return x;  
}

int fak_it(int n){
  int x=1;
  for(int i=1; i<=n; i++){
    x=i*x;
  }
  return x;
}


int main(){
  int x;
  std::cin >> x;
  std::cout << fak_it(x) << std::endl;
  std::cout << fak_rec(x) << std::endl;
  return 0;
}
