//Filename: timedtask.h
//Name:	Shawn Ogbomo
// Student #022609127
// date: 01/29/2023
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments
//-----------------------------------------------------------
#ifndef SDDS_TIMEDTASK_H_
#define SDDS_TIMEDTASK_H_
#include <chrono>
#include <iostream>
#include <string>
namespace sdds {
	struct Task {
		Task();
		std::string name;
		std::string time_unit;
		std::chrono::steady_clock::duration duration;
	};
	class  TimedTask {
		static constexpr int event_objects_max = 10;
	public:
		TimedTask();
		void startClock();
		void stopClock();
		void addTask(const char* task);
		friend std::ostream& operator<<(std::ostream& os, const TimedTask& t);
	private:
		Task tasks[event_objects_max];
		int recs;
		std::chrono::steady_clock::time_point start;
		std::chrono::steady_clock::time_point stop;
	};
}
#endif//!SDDS_TIMEDTASK_H