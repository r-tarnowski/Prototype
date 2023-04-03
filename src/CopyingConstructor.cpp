#include <iostream>
#include <string>


using std::cout;
using std::endl;

void printHeader() {
   cout << endl;
   cout << "================================================" << endl;
   cout << "Design Patterns in Modern C++ by Dmitri Nesteruk" << endl;
   cout << "Prototype, Copying Constructor                  " << endl;
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

   cout << endl;
   return 0;
}
