#pragma once

#include "libs.h"

class AppException : std::exception
{
private:
	std::string message;
public:
	explicit AppException(const std::string& message = "other exception");
	const char* what() const override;
	~AppException() = default;
};