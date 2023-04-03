#include <iostream>
#include <string>


using std::cout;
using std::endl;

void printHeader() {
   cout << endl;
   cout << "================================================" << endl;
   cout << "Design Patterns in Modern C++ by Dmitri Nesteruk" << endl;
   cout << "Prototype, Simple Duplication                   " << endl;
   cout << "================================================" << endl;
   cout << endl;
}


struct Address {
   std::string street;
   std::string city;
   unsigned int suite;
};

struct Contact {
   std::string name;
   Address address;

   friend std::ostream& operator<<(std::ostream& os, const Contact & obj) {
      return os << "name: " << obj.name << ", city: " << obj.address.city
                << ", street: " << obj.address.street << ", suite: "
                << obj.address.suite;
   }
};

int main(int argc, char *argv[]) {
   printHeader();

   Contact worker { "", Address{ "Okrąg 4", "Warszawa", 0 }};
   std::cout << worker << std::endl;

   Contact Jan = worker;
   Jan.name = "Jan Kowalski";
   Jan.address.suite = 5;
   std::cout << Jan << std::endl;

   Contact Janina = worker;
   Janina.name = "Janina Nowak";
   Janina.address.suite = 11;
   std::cout << Janina << std::endl;

   cout << endl;
   return 0;
}
