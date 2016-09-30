#include "DirectoryHelper.hpp"

using namespace Fnd::Test;

#ifdef _WIN32

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

// Replace some defines in the global namespace
#undef CreateDirectory
#ifdef UNICODE
#define Win32CreateDirectory  CreateDirectoryW
#else
#define Win32CreateDirectory  CreateDirectoryA
#endif // !UNICODE

namespace
{
	class WindowsDirectoryHelperImpl:
		public DirectoryHelper::IDirectoryHelperImpl
	{
	public:
		void CreateDirectory(const std::string& directory, const bool recursive)
		{
			Win32CreateDirectory(directory.c_str(), nullptr);
		}

		void DeleteDirectory(const std::string& directory, const bool recursive)
		{
			RemoveDirectory(directory.c_str());
		}
	};
}

typedef WindowsDirectoryHelperImpl DirectoryHelperImpl;

#endif

DirectoryHelper::DirectoryHelper():
	_impl(std::make_shared<DirectoryHelperImpl>())
{
}

void DirectoryHelper::CreateDirectory(const std::string& directory, const bool recursive)
{
	_impl->CreateDirectory(directory, recursive);
}

void DirectoryHelper::DeleteDirectory(const std::string& directory, const bool recursive)
{
	_impl->DeleteDirectory(directory, recursive);
}

std::string DirectoryHelper::ValidateString(const std::string& directory) const
{
	auto validate_char = [&](const char c) -> char
	{
		switch (c)
		{
		case '/':
		case '\\':
		case '<':
		case '>':
		case '\"':
		case '|':
		case '?':
		case '*':
			return '_';
		default:
			return c;
		}
	};

	std::string validated_string = directory;

	for (char& c : validated_string)
	{
		c = validate_char(c);
	}

	return validated_string;
}
