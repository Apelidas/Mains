#include "Data.hpp"

Data* deserialize(uintptr_t raw) {
	
	return (reinterpret_cast<Data *>(raw));
}

uintptr_t serialize(Data* ptr) {
	
	return (reinterpret_cast<uintptr_t>(ptr));
}

int main()
{
	Data test;
	test.stuff = "I see you shiver with antici...";
	test.test = "...pation";
	uintptr_t	serialized;
	Data 		*deserialized;

	serialized = serialize(&test);
	deserialized = deserialize(serialized);

	std::cout << "Adress-Test" << std::endl;
	std::cout << "Original    : " << &test << std::endl;
	std::cout << "serialized  : " << std::hex << "0x" << serialized << std::endl;
	std::cout << "deserialized: " << deserialized << std::endl << std::endl;

	std::cout << "Value-Test" << std::endl;
	std::cout << "Original:" << std::endl << test.stuff << std::endl << test.test << std::endl;
	std::cout << "Data ptr:" << std::endl << deserialized->stuff << std::endl << deserialized->test << std::endl;


}