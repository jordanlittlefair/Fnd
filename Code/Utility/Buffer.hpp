#pragma once

#include <vector>

namespace Fnd
{

namespace Utility
{

typedef std::vector<unsigned char> Buffer;
	
static_assert(sizeof(Buffer::value_type) == 1, "Size of buffer element must be one");

}

}
