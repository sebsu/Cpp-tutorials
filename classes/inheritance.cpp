
class Animal{
public:
  Animal();
  ~Animal();
  void eat();
  void sleep();
  viod drink();

private:
  int legs;
  int arms;
  int age;
};
//The class Animal contains information and functions
//  related to all animals (almost).
class Cat : public Animal{
public:
  int fur_color;
  void purr();
  void fish();
  void markTerritory();
};
//Each of the above operations is unique
// to tour friendly furry friends.


int main(){

  return 0;
}
