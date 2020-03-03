#pragma once
#include "candidate.h"

class Voter
{
	int id;
	Constituency constituency;
	std::vector<std::shared_ptr<Candidate>> candidates;

public:
	Voter(int id, Constituency constituency);

	int get_id() const;
	void set_id(int id);
	Constituency get_constituency() const;
	void set_constituency(Constituency constituency);
	void add_candidate(const std::shared_ptr<Candidate>& candidate);
	std::vector<std::shared_ptr<Candidate>> get_candidates() const;

	friend std::ostream& operator<<(std::ostream& out, const Voter& v);

	~Voter() = default;
};