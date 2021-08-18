#pragma once
#include <optional>
#include <ostream>

using namespace std;

class PhoneNumber
{
private:
	int m_contrycode;
	int m_citycode;
	string m_number;
	optional<int> m_additional;
	friend ostream& operator<<(ostream& os, const PhoneNumber& aNumber);
public:
	PhoneNumber();
	PhoneNumber(int country, int city, string number, optional<int> additional);
	bool operator<(const PhoneNumber& aPhone) const;
	PhoneNumber& operator=(const PhoneNumber& aPhone);
};

