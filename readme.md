# Set Operations

Simple parameterized library that includes various set operations for general purpose use.

# Design Philosophy

* Implement various operations for any given set of elements
* Implement a basic interface to use in any project
* Include common operations to avoid repetitive writing

# Interface

Set Operations implements the following interface:
```c++

// Generates a random set
template <typename Type, typename Index>
Type* getSet(Type, Index, Type (*random)(Type));

// Generates a copy of an existing set
template<typename Type, typename Index>
Type* copySet   (Type* const, Index);

// Reverses the set order
template <typename Type, typename Index>
Type* reverse   (Type* const, Index);

// Shuffles the set
template <typename Type, typename Index>
Type* shuffle   (Type* const, Index);

// Checks if the set is ordered
template<typename Type, typename Index>
bool  isSorted  (Type* const, Index);

// Checks set equality
template<typename Type, typename Index>
bool areEqual(Type* const, Index, Type* const, Index);

// Swaps elements in a given set
template<typename Type, typename Index>
void  swap(Type* const, Index, Index);

// Outputs set contents to a stream
template<typename Type, typename Index, typename Stream>
void  outputSet (Type* const, Index, Stream&);

// Generates a random integral number up to, excluding the 
// given max
template<typename Type>
Type getRandomNumber(Type max);
```

Additionally, the library can be used with user-defined types
as long as they overload the following operators
```c++
Type& operator=(const Type& right);
bool  operator<(const Type& right);
bool  operator!()
```


# Usage

```c++
#include <iostream>
#include "setoperations.hpp"

int main(){

	// Some Code Here

	// Creates a set of 32 elements in the range of (0-16) with a Pseudo Random Number Generator
	int set* = SetOperations::getSet(17, 32, SetOperations::getRandomNumber<int>);

	// Copies the set
	int copySet* = SetOperations::copySet<int, int>(set, 32);

	// Shuffles the set
	SetOperations::shuffle<int, int>(set, 32);

	// Evaluates as false
	bool equal = SetOperations::areEqual<int, int>(set, 32, copySet, 32);

	// More Code here

	delete[] set;
	delete[] copySet;

	return 0;

}
```

# Constraints

* SetOperations does not release memory automatically, this is left to the individual programmer
* Sets are treated as contiguous blocks, either as stack-local or dynamically allocated
* Container and Abstract Data Types such as Linked Lists or ```std::vector``` may be used as long as the proper operators are overloaded
<<<<<<< HEAD

=======
>>>>>>> d3dd4f0443ff9fec67e0af33dc1e4a64627e919b
