#pragma once

#include <string>

namespace Fnd
{

namespace Test
{

class DirectoryHelper
{
public:
	
	static void CreateDirectory(const std::string& directory, const bool recursive);
	
	static void DeleteDirectory(const std::string& directory, const bool recursive);
	
	static std::string ValidateString(const std::string& directory);	// Remove any characters not accepted in a file/directory name
};
	
}

}
