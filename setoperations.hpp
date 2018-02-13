/// @author: Carlos L. Cuenca
/// @file: set_operations.hpp
/// @note: Various Templeted set operations
#include <ctime>

namespace SetOperations{
                
    template <typename Type, typename Index>
    Type* getSet    (Type, Index, Type (*random)(Type));
        
    template<typename Type, typename Index>
    Type* copySet   (Type* const, Index);
        
    template <typename Type, typename Index>
    Type* reverse   (Type* const, Index);

    template <typename Type, typename Index>
    Type* shuffle   (Type* const, Index);
                
    template<typename Type, typename Index>
    bool  isSorted  (Type* const, Index);

    template<typename Type, typename Index>
    bool areEqual(Type* const, Index, Type* const, Index);

    template<typename Type, typename Index>
    void  swap      (Type* const, Index, Index);

    template<typename Type, typename Index, typename Stream>
    void  outputSet (Type* const, Index, Stream&);

    template<typename Type>
    Type getRandomNumber(Type max);

}

template <typename Type, typename Index>
Type* SetOperations::getSet(Type max, Index elements, Type (*random)(Type)){

    // Create a new set
    Type* set = new Type[elements];
    
    // Loop through each element and....
    for(Index index = 0; index < elements; index++){
        
        // Create and set a random number within
        set[index] = random(max);
        
    }
    
    // Give it back
    return set;

}
        
template<typename Type, typename Index>
Type* SetOperations::copySet(Type* const set, Index elements){

    // If the set is null, return null
    if(!set) return 0x0;
    
    // Allocate a new set
    Type* returnSet = new Type[elements];
    
    // Copy the set
    for(Index index = 0; index < elements; index++)
        returnSet[index] = set[index];
    
    // Return it
    return returnSet;

}
        
template <typename Type, typename Index>
Type* SetOperations::reverse   (Type* const set, Index elements){

    // Check invalidity
    if(!set) return 0x0;

    // Reverse the elements
    for(Index index = 0; index < elements; index++)
        SetOperations::swap<Type, Index>(set, index, elements - index - 1);

    return set;
}

template <typename Type, typename Index>
Type* SetOperations::shuffle   (Type* const set, Index elements){

    // Check invalidity
    if(!set) return 0x0;

    Index randomIndex;

    // Seed random
    std::srand(std::time(0));
    
    // Loop through each element and....
    for(Index index = 0; index < elements; index++){

        // Generate a random index
        randomIndex = std::rand() % (index + 1);
        
        // Swap the elements
        SetOperations::swap<Type, Index>(set, index, randomIndex);
        
    }
    
    // Give it back
    return set;


}


template<typename Type, typename Index>
void  SetOperations::swap(Type* const set, Index alpha, Index beta){

	Type buffer = set[alpha];
	set[alpha]  = set[beta] ;
	set[beta]   = buffer    ;

}

template<typename Type>
Type SetOperations::getRandomNumber(Type max){

	// Seed srand
	// std::srand(std::time(0));

	// Return the number within the max
	return std::rand() % max;

}
                

                
template<typename Type, typename Index>
bool  SetOperations::isSorted  (Type* const set, Index elements){

	// Leave when the pointer is null
    if(!set) return false;
    
    for(Index index = 1; index < elements; index++){
        
        // If the current element is less than the previous
        if(set[index] < set[index - 1]) return false;
        
    }
    
    // Nothing went wrong
    return true;

}

template<typename Type, typename Index>
bool SetOperations::areEqual(Type* const setAlpha, Index elementsAlpha, 
    Type* const setBeta, Index elementsBeta){

    if(!setAlpha || !setBeta) return false;

    // No sense to run
    if(elementsAlpha != elementsBeta) return false;


    for(Index index = 0; index < elementsAlpha; index++)
        if(setAlpha[index] != setBeta[index]) return false;

    return true;

}

template<typename Type, typename Index, typename Stream>
void  SetOperations::outputSet (Type* const set, Index elements, Stream& out){

    // Opening
    out << "{ ";
    
    // Loop through
    for(Index index = 0; index < elements; index++)     
        // Print the current element
        out << set[index] << ", ";
    
    // Closing
    out << "}\n";

}



