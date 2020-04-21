#include <xtl.h>
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <vector>

class fs
{
	public:
		static bool exists(const char* name)
		{
			WIN32_FIND_DATA data;
			HANDLE hFile = FindFirstFile(name, &data);

			if(hFile != INVALID_HANDLE_VALUE)
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		static int makedir(const char* name)
		{
			if(CreateDirectory(name, NULL) != NULL)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}

		static int deletedir(const char* name)
		{
			if(exists(name) == 1)
			{
				RemoveDirectory(name);
				return 1;
			}
			else
			{
				return 0;
			}
		}

		static void makefile(const char* name, const char* contents = "")
		{
			std::ofstream File;
			File.open(name);
			if(strlen(contents) > 0) File << contents;
			File.close();
		}
		
		static void overwritefile(const char* name, const char* contents)
		{
			if(exists(name) == true)
			{
				std::ofstream File;
				File.open(name);
				File << contents;
				File.close();
			}
			else
			{
				return;
			}
		}

		static void appendfile(const char* name, const char* contents)
		{
			if(exists(name) == true)
			{
				std::ofstream File;
				File.open(name, std::ios_base::app);
				File << contents;
				File.close();
			}
			else
			{
				return;
			}
		}

		static size_t filesize(const char* name)
		{
			HANDLE hFile = CreateFile(name, GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
			if (hFile==INVALID_HANDLE_VALUE) return 0;

			LARGE_INTEGER size;
			if (!GetFileSizeEx(hFile, &size))
			{
				CloseHandle(hFile);
				return 0;
			}

			CloseHandle(hFile);
			return size.QuadPart;
		}

		static void log(const char* contents)
		{
			fs::appendfile("D:\\user\\logs\\log.txt", contents);
		}

		static void slog(std::string contents)
		{
			fs::appendfile("D:\\user\\logs\\log.txt", contents.c_str());
		}

		static size_t size(const char* name)
		{
			struct stat results;

			if(stat(name, &results) != 0)
			{
				std::string file = name;
				fs::slog("An error occured when getting size of file: " + file + "\n");
				return 0;
			}

			return results.st_size;

		}

		static std::vector<std::string> enumdir(std::string dir)
		{
			std::vector<std::string> list;

			WIN32_FIND_DATA data;
			HANDLE hFile = FindFirstFile(dir.c_str(), &data);

			dir.erase(dir.end()-1);
			do list.push_back(dir + data.cFileName);
			while (FindNextFile(hFile, &data) != 0);

			FindClose(hFile);
			return list;
		}
};
