//Filename: Person.h
//Name:	Shawn Ogbomo
// Student #022609127
// date: 03/03/2023
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments
//-----------------------------------------------------------
#ifndef SDDS_PERSON_H
#define SDDS_PERSON_H
#include <iostream>
#include <string>
namespace sdds
{
	class Person
	{
	public:
		virtual std::string status() const = 0;
		virtual std::string name() const = 0;
		virtual std::string age() const = 0;
		virtual std::string id() const = 0;
		virtual void display(std::ostream&) const = 0;
		virtual ~Person() = default;
	};

	class Employee : public Person {
	public:
		explicit Employee(std::istream& is);
		virtual ~Employee();
		std::string status() const override;
		std::string name() const override;
		std::string age() const override;
		std::string id() const override;
		void display(std::ostream& out) const override;
	private:
		std::string	m_name;
		unsigned m_age{};
		std::string m_id;
	};

	class Professor : public Employee {
	public:
		explicit Professor(std::istream& in);
		virtual ~Professor();
		void display(std::ostream& out) const override;
		std::string status() const override;
		std::string department() const;

	private:
		using Employee::status;
		using Employee::name;
		using Employee::age;
		using Employee::id;
		using Employee::display;
		std::string m_department;
	};

	class  Student : public Person {
	public:
		explicit Student(std::istream& in);
	private:
	};
}
#endif//!SDDS_PERSON_H