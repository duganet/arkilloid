#include "file.h"


std::string path_construct(std::string dir_shortname, std::string filename)
{
    std::string dir_basename;
    #ifdef _WIN32
		dir_basename = ".";
    #else
		#ifdef DATAROOTDIR
			dir_basename = DATAROOTDIR "/" PACKAGE;
		#else
			dir_basename = DATADIR;
		#endif
    #endif
    return dir_basename + '/' + dir_shortname + "/" + filename;
}
