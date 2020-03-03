#include "data_generator.h"

std::vector<std::string> DataGenerator::split_str(const std::string& line, const char separator)
{
	std::stringstream ss;
	ss.str(line);

	std::vector<std::string> elements;
	std::string element;

	while (std::getline(ss, element, separator))
	{
		elements.emplace_back(element);
	}

	return elements;
}

Candidate DataGenerator::parse_candidate(const std::string& candidate_text)
{
	std::vector<std::string> elements = split_str(candidate_text, ';');
	return Candidate{ elements[0], elements[1], std::stoi(elements[2]), str_to_constituency(elements[3]) };
}

std::vector<Candidate> DataGenerator::get_candidates(const std::string& filename)
{
	std::ifstream reader;
	reader.open(filename);

	if (!reader.is_open())
	{
		std::cout << "CAN'T OPEN FILE " << filename << std::endl;
	}

	std::vector<Candidate> all_candidates;
	std::string line;

	while (!reader.eof())
	{
		std::getline(reader, line);
		all_candidates.emplace_back(parse_candidate(line));
	}

	reader.close();

	return all_candidates;
}

Voter DataGenerator::parse_voters(const std::string& voters_text)
{
	std::vector<std::string> elements = split_str(voters_text, ';');
	return Voter{ std::stoi(elements[0]), str_to_constituency(elements[1]) };
}

std::vector<Voter> DataGenerator::get_voters(const std::string& filename)
{
	std::ifstream reader;
	reader.open(filename);

	if (!reader.is_open())
	{
		std::cout << "CAN'T OPEN FILE " << filename << std::endl;
	}

	std::vector<Voter> all_voters;
	std::string line;

	while (!reader.eof())
	{
		std::getline(reader, line);
		all_voters.emplace_back(parse_voters(line));
	}

	reader.close();

	return all_voters;
}

std::vector<Voter> DataGenerator::set_candidates_for_voters(const std::string& candidates_filename, const std::string& voters_filename)
{
	std::map<Constituency, std::vector<std::shared_ptr<Candidate>>> candidates_grouped_by_constituency;

	std::vector<Voter> voters = get_voters(voters_filename);
	std::vector<Candidate> candidates = get_candidates(candidates_filename);

	for (const auto& candidate : candidates)
	{
		candidates_grouped_by_constituency[candidate.get_constituency()].emplace_back(std::make_shared<Candidate>(candidate));
	}

	for (auto& voter : voters)
	{
		for (const auto& c : candidates_grouped_by_constituency[voter.get_constituency()])
		{
			voter.add_candidate(c);
		}
	}

	return voters;
}
