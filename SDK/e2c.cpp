#include "e2c.hpp"

std::uint8_t* ebin2cbin(std::uint8_t* ebin)
{
	if (((int*)ebin)[0] != 1)
	{
		return nullptr;
	}
	int size = ((int*)ebin)[1];
	std::uint8_t* bin = new std::uint8_t[size];
	for (size_t i = 0; i < size; i++)
	{
		bin[i] = ((std::uint8_t*)ebin)[i + 8];
	}
	MessageBox(NULL, std::format("{}", _msize(bin)).c_str(), "", NULL);
	return bin;
}