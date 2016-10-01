#pragma once

#include "IFile.hpp"

#include <fstream>
#include <mutex>

namespace Fnd
{

namespace Utility
{

namespace File
{

class StdFile:
	public IFile
{
public:
		
	StdFile(const std::string& filename);
	
	void Open();
	
	void Close();
	
	bool IsOpen() const;
	
	std::string GetFilename() const;
	
	size_t GetSize() const;
	
	Buffer GetFileBuffer() const;
	
	void SetFileBuffer(const Buffer& buffer);
	
	void Truncate();
	
	void Delete();
	
	~StdFile();
	
protected:
	
	void Open(const int flags);
	
private:
	
	StdFile(const StdFile&);
	StdFile& operator=(const StdFile&);
	
	mutable std::recursive_mutex _mutex;
	
	std::string _filename;
	
	mutable std::fstream _fstream;
};

}

}

}
