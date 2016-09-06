#pragma once

#include "Buffer.hpp"

#include <string>

namespace Fnd
{

namespace Utility
{

namespace File
{

class IFile
{
public:
	
	virtual void Open() = 0;
	
	virtual void Close() = 0;
	
	virtual bool IsOpen() const = 0;
	
	virtual std::string GetFilename() const = 0;
	
	virtual size_t GetSize() const = 0;
	
	virtual Buffer GetFileBuffer() const = 0;
	
	virtual void SetFileBuffer(const Buffer& buffer) = 0;
	
	virtual void Truncate() = 0;
	
	virtual void Delete() = 0;
	
	virtual ~IFile() {}
};
	
typedef std::shared_ptr<IFile> FilePtr;
	
}
	
}

}
