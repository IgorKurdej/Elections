#pragma once

#include "libs.h"
#include "app_exception.h"

enum class Constituency
{
	A, B, C, D, E
};

inline Constituency constituency_to_string(const std::string& constituency)
{
	if (constituency == "A")
	{
		return Constituency::A;
	}
	else if (constituency == "B")
	{
		return Constituency::B;
	}
	else if (constituency == "C")
	{
		return Constituency::C;
	}
	else if (constituency == "D")
	{
		return Constituency::D;
	}
	else
	{
		return Constituency::E;
	}
}

inline std::string constituency_to_str(Constituency constituency)
{
	switch (constituency)
	{
	case Constituency::A:
		return "A";
	case Constituency::B:
		return "B";
	case Constituency::C:
		return "C";
	case Constituency::D:
		return "D";
	default:
		return "E";
	}

}

inline Constituency str_to_constituency(const std::string& constituency_str)
{
	if (constituency_str != "A" && constituency_str != "B" && constituency_str != "C" && constituency_str != "D" && constituency_str != "E")
	{
		throw AppException{ "illegal constituency name" };
	}

	Constituency constituencies[] = { Constituency::A, Constituency::B, Constituency::C, Constituency::D, Constituency::E };
	return constituencies[constituency_str[0] - 'A'];
}