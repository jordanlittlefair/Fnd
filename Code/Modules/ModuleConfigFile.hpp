#pragma once

#include "IConfigProvider.hpp"
#include "../Utility/IFile.hpp"
#include "../Utility/IParser.hpp"

namespace Fnd
{

namespace Modules
{

class ModuleConfigFile:
	public IConfigProvider
{
public:

	ModuleConfigFile(const Utility::ParserPtr& parser, const Utility::File::FilePtr& file);

	Utility::DocumentTree::ObjectNodePtr LoadConfigDocumentTree();

	void SaveConfigDocumentTree(const Utility::DocumentTree::ObjectNodePtr& document_tree);

private:

	Utility::ParserPtr _parser;
	Utility::File::FilePtr _file;
};

}

}
