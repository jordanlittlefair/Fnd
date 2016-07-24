#pragma once

#include <chrono>

namespace Fnd
{

namespace Test
{

class Timer
{
public:
	
	typedef std::chrono::high_resolution_clock Clock;
	typedef std::chrono::microseconds Duration;
	
	template<typename T>
	static T ToSeconds(const Duration& duration)
	{
		return ( ((T)Duration::period::num) * ((T)duration.count()) ) / ((T)Duration::period::den);
	}
	
	Timer();
	
	void Start();
	
	void End();
	
	bool IsValid() const;
	
	Duration GetTimeElapsed() const;
	
	virtual ~Timer();
	
private:
	
	bool _has_started;
	bool _has_ended;
	
	std::chrono::time_point<Clock> _start;
	std::chrono::time_point<Clock> _end;
};

}

}
