#include "PhoneBook.h"


PhoneBook::PhoneBook()
{
}

PhoneBook::PhoneBook(ifstream& file)
{
	if (!file)
	{
		cerr << "File Error" << endl;
		exit(1);
	}
	while (file)
	{
		string s_buf;

		while (getline(file, s_buf))
		{
			string person;
			string number;

			string family;
			string name;
			string patr;

			string country;
			string city;
			string num;
			string add;

			if (s_buf.find("+") != string::npos)
			{
				size_t num_pos = s_buf.find("+");
				for (size_t i = 0; i < num_pos; i++)
				{
					person += s_buf[i];
				}
				for (size_t i = num_pos; i < s_buf.size(); i++)
				{
					number += s_buf[i];
				}

				istringstream per_str(person);
				per_str >> family;
				per_str >> name;
				per_str >> patr;

				istringstream num_str(number);
				getline(num_str, country, '(');
				getline(num_str, city, ')');
				num_str >> num;
				num_str >> add;
			}
			optional<string> patronymic = nullopt;
			optional<int> addition = nullopt;

			if (!patr.empty())
				patronymic = patr;
			if (!add.empty())
				addition = stoi(add);

			m_book.push_back({ Person{family,name,patronymic}, PhoneNumber{stoi(country),stoi(city),num,addition} });
		}
	}
}

void PhoneBook::SortByName()
{
	sort(m_book.begin(),m_book.end(), [](pair<Person, PhoneNumber> record1, pair<Person, PhoneNumber> record2)
		{return record1.first < record2.first; });
}

void PhoneBook::SortByPhone()
{
	sort(m_book.begin(), m_book.end(), [](pair<Person, PhoneNumber> record1, pair<Person, PhoneNumber> record2)
		{return record1.second < record2.second; });
}

tuple<string, PhoneNumber> PhoneBook::GetPhoneNumber(string family) const
{
	size_t found{ 0 };
	PhoneNumber out;
	for_each(m_book.begin(), m_book.end(), [family,&found,&out](pair<Person, PhoneNumber> record)
		{
			if (record.first.getFamily() == family)
			{
				found++;
				out = record.second;
			}
		});
	if (found == 0)
		return make_tuple("not found", PhoneNumber());
	else if (found == 1)
		return make_tuple("", out);
	else
		return make_tuple("found more than 1", PhoneNumber());
}

void PhoneBook::ChangePhoneNumber(Person aPerson, PhoneNumber aPhone)
{
	auto it = find_if(m_book.begin(), m_book.end(), [aPerson](pair<Person, PhoneNumber> record)
		{return aPerson == record.first; });
	if (it != m_book.end())
		it->second = aPhone;
}

ostream& operator<<(ostream& os, const PhoneBook& aBook)
{
	for (auto n : aBook.m_book)
	{
		os << n.first << "\t" << n.second << endl;
	}
	return os;
}
