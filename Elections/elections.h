#pragma once

#include "data_generator.h"

class Elections
{
private:
	std::vector<std::shared_ptr<Voter>> voters;
	std::map<Constituency, std::shared_ptr<Candidate>> winners;
	std::map<std::shared_ptr<Candidate>, int> vote() const;
	void check_winners(const std::map<std::shared_ptr<Candidate>, int>& candidates_with_votes);
	bool end_of_elections() const;
	void before_next_voting();
public:
	Elections(const std::string& candidates_filename, const std::string& voters_filename);

	void show();
	std::map<Constituency, std::shared_ptr<Candidate>> elections();
	std::map<Constituency, std::shared_ptr<Candidate>> get_winners() const;

	~Elections() = default;
};
