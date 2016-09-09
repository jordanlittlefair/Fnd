#pragma once

#include "../Utility/DocumentTreeNodes.hpp"

namespace Fnd
{

namespace Modules
{

class IConfigProvider
{
public:

	virtual Utility::DocumentTree::ObjectNodePtr LoadConfigDocumentTree() = 0;

	virtual void SaveConfigDocumentTree(const Utility::DocumentTree::ObjectNodePtr& document_tree) = 0;
	
	virtual ~IConfigProvider() {}
};

typedef std::shared_ptr<IConfigProvider> ConfigProviderPtr;

}

}
