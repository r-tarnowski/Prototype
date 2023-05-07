#include <iostream>
#include <string>
#include <algorithm>


using std::cout;
using std::endl;

void printHeader() {
   cout << endl;
   cout << "================================================" << endl;
   cout << "Design Patterns in Modern C++ by Dmitri Nesteruk" << endl;
   cout << "         Prototype, Copying Constructor         " << endl;
   cout << "================================================" << endl;
   cout << endl;
}


class Address {

public:

   std::string city;
   std::string street;
   unsigned int suite;

   Address() = default;

   Address( const std::string & city, const std::string & street, unsigned int suite)
         : city { city },
           street { street },
           suite { suite } {
   }


   Address(const Address& other)
         : city { other.city },
           street { other.street },
           suite { other.suite } {

   }

/*
   Address& operator=(Address other) {
      using std::swap;
      swap(city, other.city);
      swap(street, other.street);
      swap(suite, other.suite);
      return *this;
   }
*/

   Address& operator=(const Address & other) {
      city = other.city;
      street = other.street;
      suite = other.suite;
      return *this;
   }

   friend std::ostream& operator<<(std::ostream& os, const Address & obj) {
      return os << "city: " << obj.city << ", street: " << obj.street << ", suite: "
                << obj.suite;
   }

};

class Contact {

public:

   std::string name;
   Address * pAddress;

   Contact(const Contact& other)
         : name{ other.name },
           pAddress{ new Address{ *other.pAddress } } {
      
   }

   friend std::ostream& operator<<(std::ostream& os, const Contact & obj) {
      return os << "name: " << obj.name << ", city: " << obj.pAddress->city
                << ", street: " << obj.pAddress->street << ", suite: "
                << obj.pAddress->suite;
   }
};

//int main(int argc, char *argv[]) {
auto main() -> int {
   printHeader();

   Address myAddress { "Warszawa", "Fabryczna", 116 };

   cout << "myAddress: " << myAddress << std::endl;

   Address yourAddress( myAddress );
   cout << "yourAddress: " << yourAddress << std::endl;

   Address hisAddress { "Warszawa", "Okrąg", 0 };
   cout << "hisAddress: " << hisAddress << std::endl;

   Address herAddress {};
   cout << "herAddress: " << herAddress << std::endl;
   herAddress = hisAddress;
   cout << "herAddress: " << herAddress << std::endl;
   cout << "hisAddress: " << hisAddress << std::endl;

   cout << endl;
   return 0;
}
