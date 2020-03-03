#include "candidate.h"

Candidate::Candidate(const std::string& name, const std::string& surname, const int votes, const Constituency constituency)
{
	set_name(name);
	set_surname(surname);
	set_votes(votes);
	set_constituency(constituency);
}

std::string Candidate::get_name() const
{
	return name;
}

void Candidate::set_name(const std::string& name)
{
	this->name = name;
}

std::string Candidate::get_surname() const
{
	return surname;
}

void Candidate::set_surname(const std::string& surname)
{
	this->surname = surname;
}

int Candidate::get_votes() const
{
	return votes;
}

void Candidate::set_votes(const int votes)
{
	this->votes = votes;
}

Constituency Candidate::get_constituency() const
{
	return constituency;
}

void Candidate::set_constituency(const Constituency constituency)
{
	this->constituency = constituency;
}

void Candidate::increment_votes()
{
	this->votes += 1;
}

void Candidate::reset_votes()
{
	this->votes = 0;
}

std::ostream& operator<<(std::ostream& out, const Candidate& c)
{
	return out << "Name: " + c.name + ", Surname: " + c.surname + ", Votes: " + std::to_string(c.votes) + ", Constituency: " + constituency_to_str(c.constituency);
}
