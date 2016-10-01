#pragma once

#include <memory>
#include <string>
#include <vector>

namespace Fnd
{

namespace Test
{

class DirectoryHelper
{
public:

	DirectoryHelper();
	
	void CreateDirectory(const std::string& directory, const bool recursive);
	
	void DeleteDirectory(const std::string& directory, const bool recursive);
	
	static std::string ValidateString(const std::string& directory);		// Remove any characters not accepted in a file/directory name
	
	static std::string CanonicalisePath(const std::string& path);

	static std::string RemoveTrailingSlash(const std::string& str);
public:

	class IDirectoryHelperImpl
	{
	public:

		virtual void CreateDirectory(const std::string& directory, const bool recursive) = 0;

		virtual void DeleteDirectory(const std::string& directory, const bool recursive) = 0;

		virtual ~IDirectoryHelperImpl() {}
	};

	typedef std::shared_ptr<IDirectoryHelperImpl> DirectoryHelperImplPtr;

private:

	DirectoryHelperImplPtr _impl;
};
	
}

}
