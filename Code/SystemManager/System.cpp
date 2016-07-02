#include "System.hpp"

using namespace Fnd::SystemManager;

System::System( const SystemId& id ):
	_id(id)
{
}

SystemId System::GetId() const
{
	return _id;
}

void System::AddDependency( const SystemId& dependency )
{
	if ( std::find( _dependencies.begin(), _dependencies.end(), dependency ) == _dependencies.end() )
	{
		_dependencies.push_back( dependency );
	}
}

const std::vector<SystemId>& System::GetDependencies() const
{
	return _dependencies;
}

System::~System()
{
}
