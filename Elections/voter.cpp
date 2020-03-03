#include "voter.h"

Voter::Voter(const int id, const Constituency constituency)
{
	set_id(id);
	set_constituency(constituency);
}


int Voter::get_id() const
{
	return id;
}

void Voter::set_id(const int id)
{
	this->id = id;
}

Constituency Voter::get_constituency() const
{
	return constituency;
}

void Voter::set_constituency(const Constituency constituency)
{
	this->constituency = constituency;
}

void Voter::add_candidate(const std::shared_ptr<Candidate>& candidate)
{
	candidates.emplace_back(candidate);
}

std::vector<std::shared_ptr<Candidate>> Voter::get_candidates() const
{
	return candidates;
}

std::ostream& operator<<(std::ostream& out, const Voter& v)
{
	return out << "ID: " + std::to_string(v.id) + ", Constituency: " + constituency_to_str(v.constituency);
}