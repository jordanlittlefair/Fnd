#include "StdFile.hpp"

using namespace Fnd::Utility;
using namespace Fnd::Utility::File;

namespace
{
	class ScopedFilePos
	{
	public:
		
		ScopedFilePos(std::fstream& fstream):
			_fstream(fstream)
		{
			_file_pos = _fstream.tellg();
		}
		
		~ScopedFilePos()
		{
			_fstream.seekg(_file_pos);
		}
		
	private:
		
		ScopedFilePos();
		ScopedFilePos(const ScopedFilePos&);
		ScopedFilePos& operator=(const ScopedFilePos&);
		
	private:
		
		std::fstream& _fstream;
		std::streampos _file_pos;
	};
}

StdFile::StdFile(const std::string& filename):
	_filename(filename)
{
}

void StdFile::Open()
{
	std::lock_guard<std::recursive_mutex> lock(_mutex);
	
	Open(std::ios::binary | std::ios::beg);
}

void StdFile::Close()
{
	std::lock_guard<std::recursive_mutex> lock(_mutex);
	
	_fstream.close();
}

bool StdFile::IsOpen() const
{
	std::lock_guard<std::recursive_mutex> lock(_mutex);
	
	return _fstream.is_open();
}

std::string StdFile::GetFilename() const
{
	std::lock_guard<std::recursive_mutex> lock(_mutex);
	
	return _filename;
}

size_t StdFile::GetSize() const
{
	std::lock_guard<std::recursive_mutex> lock(_mutex);
	
	if (!IsOpen())
	{
		throw std::runtime_error("File isn't open");
	}
	
	ScopedFilePos scoped_pos(_fstream);
		
	_fstream.seekg(0, std::ios::end);

	return _fstream.tellg();
}

Buffer StdFile::GetFileBuffer() const
{
	std::lock_guard<std::recursive_mutex> lock(_mutex);
	
	if (!IsOpen())
	{
		throw std::runtime_error("File isn't open");
	}
	
	ScopedFilePos scoped_pos(_fstream);
	
	_fstream.seekg(0, std::ios::beg);
	
	Buffer buffer;
	buffer.resize(GetSize());
	
	if (buffer.empty())
	{
		if (!_fstream.read((char*)&buffer.front(), buffer.size()))
		{
			throw std::runtime_error("Failed to read file");
		}
	}
	
	return buffer;
}

void StdFile::SetFileBuffer(const Buffer& buffer)
{
	std::lock_guard<std::recursive_mutex> lock(_mutex);
	
	if (!IsOpen())
	{
		throw std::runtime_error("File isn't open");
	}
	
	Close();
	
	Open(std::ios::binary | std::ios::beg | std::ios::trunc);
	
	if (buffer.empty())
	{
		if (!_fstream.write((char*)&buffer.front(), buffer.size()))
		{
			throw std::runtime_error("Failed to write file");
		}
	}
}

void StdFile::Truncate()
{
	std::lock_guard<std::recursive_mutex> lock(_mutex);
	
	if (!IsOpen())
	{
		throw std::runtime_error("File isn't open");
	}
	
	Close();
	
	Open(std::ios::binary | std::ios::beg | std::ios::trunc);
}

void StdFile::Delete()
{
	std::lock_guard<std::recursive_mutex> lock(_mutex);
	
	if (IsOpen())
	{
		Close();
	}
	
	std::remove(_filename.c_str());
}

StdFile::~StdFile()
{
	if (IsOpen())
	{
		Close();
	}
}

void StdFile::Open(const int flags)
{
	std::lock_guard<std::recursive_mutex> lock(_mutex);
	
	_fstream.open(_filename, flags);
}
