#include "app_exception.h"

AppException::AppException(const std::string& message) : message{ message } {}

const char* AppException::what() const
{
	return message.c_str();
}