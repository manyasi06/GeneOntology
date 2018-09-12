#include "hashMap.hpp"


template <class T>
hashMap<T>::hashMap()
{
	//dynamically allocate memory for unordered hashmap.
	aptr = new std::unordered_map<std::string, std::vector<Type>*>();

}

template <class T>
void hashMap<T>::addhashMap(std::string goID, T val )
{
	
	
}

template <class T>
void hashMap<T>::removehashMap()
{
}

template <class T>
void hashMap<T>::printhashMap()
{
}

template <class T>
hashMap<T>::~hashMap()
{
}
