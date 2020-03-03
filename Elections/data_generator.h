#pragma once

#include "voter.h"
#include "candidate.h"
#include "constituency.h"

class DataGenerator
{
public:
	DataGenerator() = default;

	static std::vector<std::string> split_str(const std::string& line, char separator);
	static Candidate parse_candidate(const std::string& candidate_text);
	static Voter parse_voters(const std::string& voters_text);
	static std::vector<Voter> get_voters(const std::string& filename);
	static std::vector<Candidate> get_candidates(const std::string& filename);
	static std::vector<Voter> set_candidates_for_voters(const std::string& candidates_filename, const std::string& voters_filename);

	~DataGenerator() = default;
};

