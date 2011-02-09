#include <iostream>
#include <string>
using namespace std;

class Human
{
public:
  int age;
  string name;
  int weight;
  void print()
  {
    cout << "age: " << age << " name: " << name 
	 << " weight: " << weight << endl;
  }
};

int main()
{
  Human me;
  Human a;
  me.age = 32;
  me.name = "Антон";
  me.weight = 68;
  a.age = 10;
  a.name = "Роберт";
  a.weight = 20;
  
  me.print();
  a.print();
}

