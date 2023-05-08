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

   Address( const std::string & city, const std::string & street, unsigned int suite )
         : city { city },
           street { street },
           suite { suite } {
      std::cout << "---> Address( const std::string & city, const std::string & street, unsigned int suite ) called" << std::endl;
   }


   Address( const Address& other )
         : city { other.city },
           street { other.street },
           suite { other.suite } {
      std::cout << "---> Address( const Address& other ) called" << std::endl;
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
      std::cout << "---> Address& operator=(const Address & other) called" << std::endl;
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

   Contact() = default;

   ~Contact() {
      delete pAddress;
      std::cout << "---> ~Contact() called" << std::endl;
   }

   Contact( const std::string & name,
            const Address & address )
            : name{ name },
              pAddress{ new Address(address) } {
      std::cout << "---> Contact( const std::string & name, const Address & address ) called" << std::endl;
   }

   Contact( const Contact& other )
         : name{ other.name },
           pAddress{ new Address{ *other.pAddress } } {
      std::cout << "---> Contact( const Contact& other) called" << std::endl;
   }

   Contact& operator=( const Contact& other ) {
      std::cout << "---> Contact& operator=( const Contact& other ) called" << std::endl;
      if (this == &other) {
         return *this;
      }

      name = other.name;

      if ( ( pAddress != nullptr ) && ( other.pAddress != nullptr ) ) {
         *pAddress = *other.pAddress;
      }

      if ( ( pAddress != nullptr ) && ( nullptr == other.pAddress ) ) {
         delete pAddress;
         pAddress = nullptr;
      }

      if ( ( nullptr == pAddress  ) && ( other.pAddress != nullptr ) ) {
         pAddress = new Address{ * other.pAddress };
      }

      return *this;
   }

   friend std::ostream& operator<<(std::ostream& os, const Contact & obj) {
      if (obj.pAddress != nullptr) {
         return os << "name: " << obj.name << ", address:  " << *obj.pAddress
                   << ", pAddress : " << obj.pAddress;
      }
      else {
         return os << "name: " << obj.name << ", pAddress : nullptr";
      }
   }
};

//int main(int argc, char *argv[]) {
auto main() -> int {
   printHeader();
/*
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

   Contact yourContact( "Helena Kowalska", yourAddress );
   cout << "yourContact -> " << yourContact << std::endl;
   yourContact.pAddress->suite = 144;
   cout << "yourContact -> " << yourContact << std::endl;
*/

   Contact empty{};
   cout << "empty -> " << empty << std::endl;

   Contact worker { "", Address{ "Warszawa",  "Przemysłowa 12", 0 }};
   cout << "worker -> " << worker << std::endl;

   empty = worker;
   cout << "empty -> " << empty << std::endl;

   Contact Jan = worker;
   Jan.name = "Jan Kowalski";
   Jan.pAddress->suite = 5;

   Contact Janina = worker;
   Janina.name = "Janina Nowak";
   Janina.pAddress->suite = 11;

   std::cout << "Janina  -> " << Janina << std::endl;
   std::cout << "Jan     -> " << Jan << std::endl;

   empty = Jan;
   cout << "empty (not empty now) -> " << empty << std::endl;

   cout << endl;

   return 0;
}
