#pragma once
#include "libs.h"
#include "constituency.h"

class Candidate
{
private:
	std::string name;
	std::string surname;
	int votes;
	Constituency constituency;

public:
	Candidate(const std::string& name, const std::string& surname, int votes, const Constituency constituency);

	std::string get_name() const;
	void set_name(const std::string& name);
	std::string get_surname() const;
	void set_surname(const std::string& surname);
	int get_votes() const;
	void set_votes(int votes);
	Constituency get_constituency() const;
	void set_constituency(const Constituency constituency);

	void increment_votes();
	void reset_votes();
	friend std::ostream& operator<<(std::ostream& out, const Candidate& c);

	~Candidate() = default;
};