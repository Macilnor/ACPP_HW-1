#pragma once
#include <optional>
#include <ostream>
#include <tuple>
#include <iostream>

using namespace std;

class Person
{
private:
	string m_name;
	optional<string> m_patronymic;
	string m_family;
	friend ostream& operator<<(ostream& os, const Person& aPerson);
public:
	Person();
	Person(string family, string name, optional<string> patronimymic);
	string getFamily() const;
	bool operator<(const Person& aPerson) const;
	bool operator==(const Person& aPerson) const;
};

