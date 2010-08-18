#include <string>

extern std::string message;
extern std::ofstream logfile;
extern int msgtype;
enum msgtypes
{
	MSG_DEBUG,
	MSG_ERROR,
	MSG_UNDEF,
	MSG_WARN
};

void log(std::string message);
void report(std::string message, int msgtype);
