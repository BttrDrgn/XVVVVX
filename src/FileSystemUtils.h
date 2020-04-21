#pragma once

#include <string>
#include <vector>
#include <physfs.h>

int FILESYSTEM_init();

char *FILESYSTEM_getUserSaveDirectory();
char *FILESYSTEM_getUserLevelDirectory();

void FILESYSTEM_loadFileToMemory(const char *name, char **mem, size_t *len);
void FILESYSTEM_freeMemory(char **mem);

std::vector<std::string> FILESYSTEM_getLevelDirFileNames();
