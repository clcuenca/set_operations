#include <iostream>
#include "setoperations.hpp"

template<typename Type, typename Index>
void testOperations();

const unsigned int MAX_ELEMENTS = 128 ;
const unsigned int MAX_RANGE    = 55  ;

int main(){

	testOperations<int, int>();



	return 0;
}


template<typename Type, typename Index>
void testOperations(){

	std::cout << "---------------" << std::endl;
	std::cout << "Generating Sets" << std::endl;
	std::cout    				   << std::endl;

	Type* setOne = SetOperations::getSet<Type, Index>
	(MAX_RANGE, MAX_ELEMENTS, SetOperations::getRandomNumber<Type>);

	Type* setTwo = SetOperations::getSet<Type, Index>
	(MAX_RANGE, MAX_ELEMENTS, SetOperations::getRandomNumber<Type>);

	Type* setThree = SetOperations::getSet<Type, Index>
	(MAX_RANGE, MAX_ELEMENTS, SetOperations::getRandomNumber<Type>);

	std::cout << "Sets: "    << std::endl;
	std::cout << "Set One: " << std::endl;

	SetOperations::outputSet<Type, Index>(setOne, MAX_ELEMENTS, std::cout);

	std::cout << "\nSet Two: " << std::endl;

	SetOperations::outputSet<Type, Index>(setTwo, MAX_ELEMENTS, std::cout);

	std::cout << "\nSet Three: " << std::endl;

	SetOperations::outputSet<Type, Index>(setThree, MAX_ELEMENTS, std::cout);

	std::cout << 
	"--------------------------------------------------------------------------------" 
	<< std::endl;
	std::cout << "Shuffling Sets" << std::endl;
	std::cout   				  << std::endl;

	SetOperations::shuffle<Type, Index>(setOne,   MAX_ELEMENTS);
	SetOperations::shuffle<Type, Index>(setTwo,   MAX_ELEMENTS);
	SetOperations::shuffle<Type, Index>(setThree, MAX_ELEMENTS);

	std::cout << "Sets: "    << std::endl;
	std::cout << "Set One: " << std::endl;

	SetOperations::outputSet<Type, Index>(setOne, MAX_ELEMENTS, std::cout);

	std::cout << "\nSet Two: " << std::endl;

	SetOperations::outputSet<Type, Index>(setTwo, MAX_ELEMENTS, std::cout);

	std::cout << "\nSet Three: " << std::endl;

	SetOperations::outputSet<Type, Index>(setThree, MAX_ELEMENTS, std::cout);

	std::cout << 
	"--------------------------------------------------------------------------------" 
	<< std::endl;
	std::cout << "Reversing Sets" << std::endl;
	std::cout   				  << std::endl;

	SetOperations::reverse<Type, Index>(setOne,   MAX_ELEMENTS);
	SetOperations::reverse<Type, Index>(setTwo,   MAX_ELEMENTS);
	SetOperations::reverse<Type, Index>(setThree, MAX_ELEMENTS);

	std::cout << "Sets: "    << std::endl;
	std::cout << "Set One: " << std::endl;

	SetOperations::outputSet<Type, Index>(setOne, MAX_ELEMENTS, std::cout);

	std::cout << "\nSet Two: " << std::endl;

	SetOperations::outputSet<Type, Index>(setTwo, MAX_ELEMENTS, std::cout);

	std::cout << "\nSet Three: " << std::endl;

	SetOperations::outputSet<Type, Index>(setThree, MAX_ELEMENTS, std::cout);

	std::cout << 
	"--------------------------------------------------------------------------------" 
	<< std::endl;
	std::cout << "Copying Sets"   << std::endl;
	std::cout   				  << std::endl;

	Type* copyOne = SetOperations::copySet<Type, Index>
	(setOne,   MAX_ELEMENTS);

	Type* copyTwo = SetOperations::copySet<Type, Index>
	(setTwo,   MAX_ELEMENTS);

	Type* copyThree = SetOperations::copySet<Type, Index>
	(setThree, MAX_ELEMENTS);

	std::cout << "\nSets: "    << std::endl;
	std::cout << "Set One: " << std::endl;

	SetOperations::outputSet<Type, Index>(setOne, MAX_ELEMENTS, std::cout);

	std::cout << "\nSet Two: " << std::endl;

	SetOperations::outputSet<Type, Index>(setTwo, MAX_ELEMENTS, std::cout);

	std::cout << "\nSet Three: " << std::endl;

	SetOperations::outputSet<Type, Index>(setThree, MAX_ELEMENTS, std::cout);

	std::cout << "\nCopies: "    << std::endl;
	std::cout << "Set One: " << std::endl;

	SetOperations::outputSet<Type, Index>(copyOne, MAX_ELEMENTS, std::cout);

	std::cout << "\nSet Two: " << std::endl;

	SetOperations::outputSet<Type, Index>(copyTwo, MAX_ELEMENTS, std::cout);

	std::cout << "\nSet Three: " << std::endl;

	SetOperations::outputSet<Type, Index>(copyThree, MAX_ELEMENTS, std::cout);

	std::cout << "Equality: " << std::endl;
	std::cout << SetOperations::areEqual(setOne,   MAX_ELEMENTS, copyOne,   MAX_ELEMENTS) << std::endl;
	std::cout << SetOperations::areEqual(setTwo,   MAX_ELEMENTS, copyTwo,   MAX_ELEMENTS) << std::endl;
	std::cout << SetOperations::areEqual(setThree, MAX_ELEMENTS, copyThree, MAX_ELEMENTS) << std::endl;
	std::cout << SetOperations::areEqual(setOne,   MAX_ELEMENTS, copyTwo,   MAX_ELEMENTS) << std::endl;

	std::cout << "Finished" << std::endl;

	delete[] setOne;
	delete[] setTwo;
	delete[] setThree;

	delete[] copyOne;
	delete[] copyTwo;
	delete[] copyThree;



}
