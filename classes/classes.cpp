#include <iostream>

using namespace std;

class Computer{

public:
  Computer(); //Constructor
  ~Computer();//Destructor
  void setSpeed(int p);
  int getSpeed();

protected:  //Only accessible from within the class
  int processorspeed;

}; //SEMI-COLON!

Computer::Computer(){
  //Constructors can accept arguments, but this does not.
  processorspeed = 0;
}

Computer::~Computer(){
  //Destructors do not accept arguments
}

//To define a function outside put the name of the class
// after the return tupe and then two colons, and then
// the name of the function.
void Computer::setSpeed(int p){
  processorspeed = p;
}

int Computer::getSpeed(){
  return processorspeed;
}

int main(){
  Computer comp;
  comp.setSpeed(100);
  cout << comp.getSpeed() << endl;
  return 0;
}
