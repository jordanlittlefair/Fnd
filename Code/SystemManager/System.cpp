#include "System.hpp"

using namespace Fnd::SystemManager;

System::System( const Id& id ):
	_id(id)
{
}

System::Id System::GetId() const
{
	return _id;
}

void System::AddDependency( const Id& dependency )
{
	if ( std::find( _dependencies.begin(), _dependencies.end(), dependency ) == _dependencies.end() )
	{
		_dependencies.push_back( dependency );
	}
}

const std::vector<System::Id>& System::GetDependencies() const
{
	return _dependencies;
}

System::~System()
{
}
