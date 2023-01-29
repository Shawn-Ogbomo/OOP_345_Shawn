//Filename: timedtask.cpp
//Name:	Shawn Ogbomo
// Student #022609127
// date: 01/29/2023
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments
//-----------------------------------------------------------
#include "TimedTask.h"
#include <iomanip>
namespace sdds {
	sdds::Task::Task()
		:name{},
		time_unit{},
		duration{}{
	}
	TimedTask::TimedTask()
		: recs{},
		start{},
		stop{}{
	}
	void TimedTask::startClock() {
		start = std::chrono::steady_clock::now();
	}
	void TimedTask::stopClock() {
		stop = std::chrono::steady_clock::now();
	}
	void TimedTask::addTask(const char* task) {
		tasks[recs].name = task;
		tasks[recs].time_unit = "nanoseconds";
		tasks[recs].duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
		++recs;
	}
	std::ostream& operator<<(std::ostream& os, const TimedTask& t) {
		os << "Execution Times:\n" << "--------------------------\n";
		for (const auto& target : t.tasks) {
			os << std::left << std::setw(21) << target.name
				<< std::right << std::setw(13) << target.duration.count()
				<< " " << target.time_unit << "\n";
		}
		os << "--------------------------\n";
		return os;
	}
}