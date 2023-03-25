/*
 *		file.cpp - file module
 *
 *		Copyright 2010-2012 Maxim Kachur <mcdebugger@duganet.ru>
 *		
 *		This file is part of Arkilloid.
 *
 *		Arkilloid is free software: you can redistribute it and/or modify
 *		it under the terms of the GNU General Public License as published by
 *		the Free Software Foundation, either version 3 of the License, or
 *		(at your option) any later version.
 *
 *		Arkilloid is distributed in the hope that it will be useful,
 *		but WITHOUT ANY WARRANTY; without even the implied warranty of
 *		MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *		GNU General Public License for more details.
 *
 *		You should have received a copy of the GNU General Public License
 *		along with Arkilloid.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "file.hpp"
#include <sys/stat.h>

// Check if file exists
bool file_exists (const std::string filename) {
	struct stat buffer;
	return (stat (filename.c_str(), &buffer) == 0);
}

// Find file in standard directories and return full path
std::string path_construct(std::string dir_shortname, std::string filename)
{
    std::string dir_basename;
	std::string fullpath, path;
	bool last_element = false;
	size_t pos_cur;
	size_t pos_prev = -1;

	// Check if file exists in the current working directory
	fullpath = "./" + dir_shortname + "/" + filename;
	if (file_exists(fullpath)) {
		return fullpath;
	}

	// Check if file exists in directories defined by the build system
	#if defined DATADIR
		fullpath = DATADIR "/" + dir_shortname + "/" + filename;
	if (file_exists(fullpath)) {
		return fullpath;
	}
	#elif defined DATAROOTDIR
		fullpath = DATAROOTDIR "/" PACKAGE "/" + dir_shortname + "/" + filename;
		if (file_exists(fullpath)) {
			return fullpath;
		}
	#endif

	// Check if file exists in directories set by PATH environment variable
	if (std::getenv("PATH")) {
		std::string env_path = std::getenv("PATH");
		while (!last_element) {
			pos_cur = env_path.find(':', pos_prev+1);
			path = env_path.substr(pos_prev+1, pos_cur-pos_prev-1);
			fullpath = path + "/" + dir_shortname + "/" + filename;
			if (file_exists(fullpath)) {
				return fullpath;
			}
			pos_prev = pos_cur;
			if (pos_cur == std::string::npos) {
				last_element = true;
			}
		}
	}

    return "./data/" + dir_shortname + "/" + filename;
}
