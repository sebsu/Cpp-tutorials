// http://www.cprogramming.com/tutorial/initialization-lists-c++.html

#include <iostream>

class foo{
public:
  foo(int x){
    std::cout << "foo construct " << x << std::endl;
  }
};

class bar : public foo{
public:
  bar() : foo(10){
    std::cout << "bar construct" << std::endl;
  }
};

int main(){
  bar bar;
  return 0;
}
