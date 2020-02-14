#include "Folder_viewer.h"
#include <windows.h>
#include <vector>
#include <filesystem>


Folder_viewer::Folder_viewer()
{
}


Folder_viewer::~Folder_viewer()
{
}

void Folder_viewer::read_directory(const string& name, vector<string>& v)
{
	string pattern(name);
	pattern.append("\\*");
	WIN32_FIND_DATA data;
	HANDLE hFind;
	if ((hFind = FindFirstFile(pattern.c_str(), &data)) != INVALID_HANDLE_VALUE) {
		do {
			v.push_back(data.cFileName);
		} while (FindNextFile(hFind, &data) != 0);
		FindClose(hFind);
	}
}
