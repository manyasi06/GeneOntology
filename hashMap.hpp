/*
Date: 9/12/2018
Program: Datastructure that is hashmap to work on the storing of the GO ID's
Author: Bryan Musungu
*/

#pragma once
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <unordered_map>
#include <iostream>

template <class T>
class hashMap
{
private:
	std::unordered_map<std::string, std::vector<Type>*> * aptr;

public:
	hashMap();
	void addhashMap();
	void removehashMap();
	void printhashMap();
	~hashMap();
};

