// http://www.cprogramming.com/tutorial/lesson17.html

#include <cstdarg>
#include <iostream>

using namespace std;

//This function will take num number of values to average.
double average(int num, ...){
  va_list arguments; //A place to store the list of arguments
  double sum = 0;

  va_start(arguments, num); //Init arguments to store all calues after num
  for(int x=0; x<num; x++){ //Loop until all numbers are added
    sum += va_arg(arguments, double); //Adds the next value un argument list to sum
  }
  va_end(arguments); //Cleans up the list

  return sum/num;
}

int main(int argc, char *argv[]){
  cout << average(3, 12.3, 14.1, 41.0) << endl;
  cout << average(6, 12.3, 14.1, 41.0, 1,5, 42.3) << endl;
  return 0;
}
