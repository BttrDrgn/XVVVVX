#include "FileSystemUtils.h"
#include "filesystem.h"
#include "Utility.h"
#include <physfs.h>

#include <vector>
#include <string>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <SDL.h>

#include <limits.h>

char* saveDir = "D:\\user\\saves\\";
char* levelDir = "D:\\user\\levels";
std::string dateLog = "D:\\user\\logs\\log.txt";

int FILESYSTEM_init()
{
	/* Log file; printf alternative */
	fs::makedir("D:\\user\\logs");
	if(!fs::exists(dateLog.c_str())) fs::makefile(dateLog.c_str());
	fs::overwritefile(dateLog.c_str(), "");

	if(!fs::exists("D:\\user")) fs::makedir("D:\\user");
	if(!fs::exists("D:\\user\\saves")) fs::makedir("D:\\user\\saves");
	if(!fs::exists("D:\\user\\levels")) fs::makedir("D:\\user\\levels");
	if(!fs::exists("D:\\data")) fs::makedir("D:\\data");

	//Check if data exists; would be better to check for all but ehh
	if(!fs::exists("D:\\data\\VVVVVV.png"))
	{
		fs::makefile("D:\\README.txt", "Please extract your data.zip into the data folder.\nYou may delete this file afterwards if you want to.");
		SDL_assert(0 && "Missing base game files!");
		return 0;
	}
	else
	{
		PHYSFS_init(NULL);
		return 1;
	}
}

char *FILESYSTEM_getUserSaveDirectory()
{
	return saveDir;
}

char *FILESYSTEM_getUserLevelDirectory()
{
	return levelDir;
}

void FILESYSTEM_loadFileToMemory(const char* name, char** mem, size_t* len)
{
	std::ifstream filestream(name, std::ifstream::binary);
	int length = fs::size(name);
	*mem = (char*) malloc(length);
	filestream.read (*mem,length);
	filestream.close();
}

void FILESYSTEM_freeMemory(char **mem)
{
	free(*mem);
	*mem = NULL;
}

std::vector<std::string> FILESYSTEM_getLevelDirFileNames()
{
	return fs::enumdir("D:\\user\\levels\\*");
}
