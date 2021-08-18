#include "Person.h"

ostream& operator<<(ostream& os, const Person& aPerson)
{
    os.width(12);
    os << aPerson.m_family << "\t";
    os.width(12);
    os << aPerson.m_name << "\t";
    if (aPerson.m_patronymic.has_value())
    {
        os.width(14);
        os << aPerson.m_patronymic.value();
    }
    else {
        os.width(14);
        os << " ";
    }
    return os;
}

Person::Person()
{
}

Person::Person(string family, string name, optional<string> patronimymic) : m_name(name), m_patronymic(patronimymic), m_family(family)
{
}

string Person::getFamily() const
{
    return m_family;
}

bool Person::operator<(const Person& aPerson) const
{

    return tie(m_family, m_name, m_patronymic) < tie(aPerson.m_family, aPerson.m_name, aPerson.m_patronymic);
}

bool Person::operator==(const Person& aPerson) const
{

    return tie(m_family, m_name, m_patronymic) == tie(aPerson.m_family, aPerson.m_name, aPerson.m_patronymic);
}
