#pragma once
#include "Person.h"
#include "PhoneNumber.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <tuple>
#include <algorithm>

using namespace std;

class PhoneBook
{
private:
	vector<pair<Person, PhoneNumber>> m_book;
	friend ostream& operator<<(ostream& os, const PhoneBook& aBook);
public:
	PhoneBook();
	PhoneBook(ifstream& file);
	void SortByName();
	void SortByPhone();
	tuple<string, PhoneNumber> GetPhoneNumber(string family) const;
	void ChangePhoneNumber(Person aPerson, PhoneNumber aPhone);
};

