#include "PhoneNumber.h"

PhoneNumber::PhoneNumber() : m_contrycode(7), m_citycode(495), m_number("1234567"), m_additional(nullopt)
{
}

PhoneNumber::PhoneNumber(int country, int city, string number, optional<int> additional) : m_contrycode(country), m_citycode(city), m_number(number), m_additional(additional)
{
}

bool PhoneNumber::operator<(const PhoneNumber& aPhone) const
{
	return tie(m_contrycode, m_citycode, m_number, m_additional) < tie(aPhone.m_contrycode, aPhone.m_citycode, aPhone.m_number, aPhone.m_additional);
}

PhoneNumber& PhoneNumber::operator=(const PhoneNumber& aPhone)
{
	m_contrycode = aPhone.m_contrycode;
	m_citycode = aPhone.m_citycode;
	m_number = aPhone.m_number;
	m_additional = aPhone.m_additional;
	return *this;
}


ostream& operator<<(ostream& os, const PhoneNumber& aPhone)
{
	os << "+" << aPhone.m_contrycode << "(" << aPhone.m_citycode << ")" << aPhone.m_number;
	if (aPhone.m_additional.has_value())
		os << " " << aPhone.m_additional.value();
	return os;
}
