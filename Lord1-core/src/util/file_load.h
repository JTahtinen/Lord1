#pragma once
#include <string>
#include <fstream>
#include <iostream>

namespace lord { namespace util {

	inline std::string load_file(const std::string& filename)
	{
		std::string output;
		std::string line;

		std::ifstream file(filename);
		if (file.is_open())
		{
			while (getline(file, line))
			{
				output.append(line + "\n");
			}
			file.close();
			return output;
		}
		std::cout << "[ERROR] Could not open file: " << filename << std::endl;
		return "";
	}

}}
