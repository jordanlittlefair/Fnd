#include "MockFile.hpp"

using namespace Fnd::Test::Modules;
using namespace Fnd::Utility;
using namespace Fnd::Utility::File;

MockFile::MockFile(const std::string& filename):
	_filename(filename),
	_is_open(false)
{
	
}

MockFile::MockFile(const std::string& filename, const Fnd::Utility::Buffer& initial_data):
	_filename(filename),
	_is_open(false),
	_data(initial_data)
{
	
}

void MockFile::Open()
{
	_is_open = true;
}

void MockFile::Close()
{
	_is_open = false;
}

bool MockFile::IsOpen() const
{
	return _is_open;
}

std::string MockFile::GetFilename() const
{
	return _filename;
}

size_t MockFile::GetSize() const
{
	return _data.size();
}

Buffer MockFile::GetFileBuffer() const
{
	return _data;
}

void MockFile::SetFileBuffer(const Buffer& buffer)
{
	_data = buffer;
}

void MockFile::Truncate()
{
	_data.clear();
}

void MockFile::Delete()
{
	_data.clear();
	Close();
}
