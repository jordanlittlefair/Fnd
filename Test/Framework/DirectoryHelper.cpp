#include "DirectoryHelper.hpp"

#include <algorithm>
#include <sstream>

using namespace Fnd::Test;

namespace
{
	std::vector<std::string> SplitString(const std::string& str, char c)
	{
		std::vector<std::string> to_return;
		std::stringstream ss(str);
		std::string substring;
		
		while( std::getline( ss, substring, c ) )
		{
			if ( !substring.empty() )
			{
				to_return.push_back(substring);
			}
		}
		
		return to_return;
	}
}

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
			std::vector<std::string> directories = SplitString(DirectoryHelper::CanonicalisePath(directory), '/');
			std::string current_directory;
			
			for (const std::string& dir : directories)
			{
				current_directory += dir;
				
				Win32CreateDirectory(current_directory.c_str(), nullptr);
				
				current_directory += '/';
				
			}
		}

		void DeleteDirectory(const std::string& directory, const bool recursive)
		{
			if (recursive)
			{
				WIN32_FIND_DATA find_data;
				HANDLE file_handle = FindFirstFile((directory + "*").c_str(), &find_data);

				if (file_handle != INVALID_HANDLE_VALUE)
				{
					do
					{
						if (!strcmp(find_data.cFileName, ".") || !strcmp(find_data.cFileName, ".."))
						{
							// skip
						}
						else
						{
							const std::string content = directory + find_data.cFileName;

							if (find_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
							{
								DeleteDirectory(content, true);
							}
							else
							{
								DeleteFile(content.c_str());
							}
						}
					}
					while (FindNextFile(file_handle, &find_data));

					FindClose(file_handle);
					file_handle = INVALID_HANDLE_VALUE;

					RemoveDirectory(directory.c_str());
				}
			}
			else
			{
				RemoveDirectory(directory.c_str());
			}
		}
	};
}

typedef WindowsDirectoryHelperImpl DirectoryHelperImpl;

#endif

#ifdef __APPLE__

#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

namespace
{
	class UnixDirectoryHelperImpl:
	public DirectoryHelper::IDirectoryHelperImpl
	{
	public:
		void CreateDirectory(const std::string& directory, const bool recursive)
		{
			std::vector<std::string> directories = SplitString(DirectoryHelper::CanonicalisePath(directory), '/');
			std::string current_directory;
			
			for (const std::string& dir : directories)
			{
				current_directory += dir;
				
				mkdir(current_directory.c_str(), 0777);
				
				current_directory += '/';
				
			}
		}
		
		void DeleteDirectory(const std::string& directory, const bool recursive)
		{
			if (recursive)
			{
				DIR *d = opendir(directory.c_str());
				
				if (d)
				{
					dirent *p;
					
					while (p=readdir(d))
					{
						/* Skip the names "." and ".." as we don't want to recurse on them. */
						if (!strcmp(p->d_name, ".") || !strcmp(p->d_name, ".."))
						{
							continue;
						}
						
						struct stat statbuf;
						
						std::string content = directory + '/' + p->d_name;
							
						if (!stat(content.c_str(), &statbuf))
						{
							if (S_ISDIR(statbuf.st_mode))
							{
								DeleteDirectory(content.c_str(), true);
							}
							else
							{
								unlink(content.c_str());
							}
						}
					}
					
					closedir(d);
				}
				
				rmdir(directory.c_str());
			}
			else
			{
				rmdir(directory.c_str());
			}
		}
	};
}

typedef UnixDirectoryHelperImpl DirectoryHelperImpl;

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

std::string DirectoryHelper::ValidateString(const std::string& directory)
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

std::string DirectoryHelper::CanonicalisePath(const std::string& path_in)
{
	std::string ret;
	
	std::string path = path_in;
	
	std::transform( path.begin(), path.end(), path.begin(), [](char c) { return ( c == '\\' ? '/' : c ); } );
	
	std::vector<std::string> path_vec = SplitString(path, '/');
	
	int parent_count = 0;
	
	for (auto iter = path_vec.rbegin(); iter != path_vec.rend(); ++iter)
	{
		if ( *iter != ".." )
		{
			if ( parent_count == 0 )
			{
				ret = *iter + '/' + ret;
			}
			else
			{
				--parent_count;
			}
		}
		else
		{
			++parent_count;
		}
	}
	
	for ( int i = 0; i < parent_count; ++i )
	{
		ret = "../" + ret;
	}
	
	return ret;
}

std::string DirectoryHelper::RemoveTrailingSlash(const std::string& str)
{
	if (str.empty())
	{
		return str;
	}

	if (
		str.back() == '\\' ||
		str.back() == '/'
		)
	{
		return str.substr(0, str.size() - 1);
	}

	return str;
}