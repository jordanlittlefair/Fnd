#pragma once

#include "../../Code/Utility/IFile.hpp"

namespace Fnd
{

namespace Test
{

namespace Modules
{

class MockFile:
	public Fnd::Utility::File::IFile
{
public:
	
	MockFile(const std::string& filename);
	
	MockFile(const std::string& filename, const Fnd::Utility::Buffer& initial_data);
	
	void Open();
	
	void Close();
	
	bool IsOpen() const;
	
	std::string GetFilename() const;
	
	size_t GetSize() const;
	
	Utility::Buffer GetFileBuffer() const;
	
	void SetFileBuffer(const Utility::Buffer& buffer);
	
	void Truncate();
	
	void Delete();
	
private:
	
	const std::string _filename;
	
	bool _is_open;
	
	Fnd::Utility::Buffer _data;
};

}

}

}
