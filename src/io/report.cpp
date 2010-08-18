#include "report.hpp"
#include <fstream>

std::ofstream logfile("arkilloid.log");
void log(std::string message)
{
	report(message, MSG_UNDEF);
}

void report(std::string message, int msgtype)
{
	switch(msgtype)
	{
		case MSG_DEBUG:
			#ifdef DEBUG
				logfile << "DEBUG: " << message << std::endl;
			#endif
			break;
		case MSG_ERROR:
			logfile << "ERROR: " << message << std::endl;
			break;
		case MSG_UNDEF:
			logfile << message << std::endl;
			break;
	}	
	logfile.flush();
}
