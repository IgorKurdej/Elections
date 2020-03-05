#include "elections.h"

Elections::Elections(const std::string& candidates_filename, const std::string& voters_filename)
{
	auto voters_from_file = DataGenerator::set_candidates_for_voters(candidates_filename, voters_filename);

	for (const auto& voter : voters_from_file)
	{
		voters.emplace_back(std::make_shared<Voter>(voter));
	}
}

std::map<Constituency, std::shared_ptr<Candidate>> Elections::elections()
{
	auto counter = 1;

	do
	{
		before_next_voting();
		std::cout << "------------------------Round number " << counter << "------------------------" << std::endl;
		const auto candidates_with_votes = vote();
		check_winners(candidates_with_votes);
		++counter;
	} while (!end_of_elections());

	return winners;
}

std::map<Constituency, std::shared_ptr<Candidate>> Elections::get_winners() const
{
	return winners;
}

std::map<std::shared_ptr<Candidate>, int> Elections::vote() const
{
	std::map<std::shared_ptr<Candidate>, int> candidates_with_votes;

	for (auto& v : voters)
	{
		if (winners.find(v->get_constituency()) != winners.end())
		{
			continue;
		}

		std::cout << *v << std::endl;
		std::cout << "Your candidates: " << std::endl;
		auto i = 1;

		for (const auto& c : v->get_candidates())
		{
			std::cout << i << ") " << c->get_name() << " " << c->get_surname() << std::endl;
			i++;
		}

		int number;
		do {
			std::cout << "Choose correct candidate number: " << std::endl;
			std::cin >> number; std::cin.get();
		} while (number < 1 || number > v->get_candidates().size());

		for (auto i = 0; i < v->get_candidates().size(); ++i)
		{
			if ((i + 1) == number)
			{
				v->get_candidates()[i]->increment_votes();
				break;
			}
		}

		for (const auto& c : v->get_candidates())
		{
			candidates_with_votes[c] = c->get_votes();
		}

	}

	return candidates_with_votes;
}

void Elections::check_winners(const std::map<std::shared_ptr<Candidate>, int>& candidates_with_votes)
{
	std::map<Constituency, int> voters_number_per_constituency;
	for (const auto& v : voters)
	{
		if (voters_number_per_constituency.find(v->get_constituency()) != voters_number_per_constituency.end())
		{
			voters_number_per_constituency[v->get_constituency()]++;
		}
		else
		{
			voters_number_per_constituency[v->get_constituency()] = 1;
		}
	}

	for (auto& c : candidates_with_votes)
	{
		if (c.second * 2 > voters_number_per_constituency[c.first->get_constituency()])
		{
			winners[c.first->get_constituency()] = c.first;
		}
	}
}

bool Elections::end_of_elections() const
{
	return winners.size() == 5;
}

void Elections::before_next_voting()
{
	for (const auto& voter : voters)
	{
		for (const auto& candidate : voter->get_candidates())
		{
			candidate->reset_votes();
		}
	}
}

void Elections::show()
{
	for (auto& v : voters)
	{
		std::cout << v << std::endl;
		std::cout << "Your candidate: " << std::endl;
		auto i = 1;
		for (const auto& c : v->get_candidates())
		{
			std::cout << i << ") " << c << std::endl;
			i++;
		}

		std::cout << std::endl;
	}

}
