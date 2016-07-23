#include "Timer.hpp"

#include <cassert>

using namespace Fnd::Test;

Timer::Timer():
	_has_started(false),
	_has_ended(false)
{
}

void Timer::Start()
{
	assert(!_has_ended);
	
	_has_started = true;
	
	_start = Clock::now();
}

void Timer::End()
{
	assert(_has_started);

	_has_ended = true;
	
	_end = Clock::now();
}

bool Timer::IsValid() const
{
	return _has_started && _has_ended;
}

Timer::Duration Timer::GetTimeElapsed() const
{
	assert(IsValid());
	
	return std::chrono::duration_cast<Duration>( _end - _start);
}

Timer::~Timer()
{
}
