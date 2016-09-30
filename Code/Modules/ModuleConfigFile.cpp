#include "ModuleConfigFile.hpp"


using namespace Fnd::Modules;
using namespace Fnd::Utility;
using namespace Fnd::Utility::DocumentTree;
using namespace Fnd::Utility::File;

ModuleConfigFile::ModuleConfigFile(const ParserPtr& parser, const FilePtr& file):
	_parser(parser),
	_file(file)
{
}

ObjectNodePtr ModuleConfigFile::LoadConfigDocumentTree()
{
	if (!_file->IsOpen())
	{
		_file->Open();
	}

	Buffer file_buffer = _file->GetFileBuffer();

	ObjectNodePtr document_tree = _parser->Parse(file_buffer);

	return document_tree;
}

void ModuleConfigFile::SaveConfigDocumentTree(const ObjectNodePtr& document_tree)
{
	if (!_file->IsOpen())
	{
		_file->Open();
	}

	Buffer file_buffer = _parser->Serialise(document_tree);

	_file->SetFileBuffer(file_buffer);
}
