#include "Data.hpp"
#include "Serializer.hpp"

int main()
{
	Data 		*eden = new Data;
	uintptr_t	ptr;
	
	eden->ID = 1;
	eden->name = "Eden";
	eden->occupation = "Student";

	std::cout << "ID: " << eden->ID << std::endl;
	std::cout << "Name: " << eden->name << std::endl;
	std::cout << "Occupation: " << eden->occupation << std::endl;

	ptr = Serializer::serialize(eden);
	eden  = Serializer::deserialize(ptr);

	std::cout << "ID: " << eden->ID << std::endl;
	std::cout << "Name: " << eden->name << std::endl;
	std::cout << "Occupation: " << eden->occupation << std::endl;

	delete eden;
}