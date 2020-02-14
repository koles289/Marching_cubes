#pragma once
#include <vector>
#include <string>
using namespace std;

class Folder_viewer
{
public:
	Folder_viewer();
	~Folder_viewer();
	void read_directory(const string& name, vector<string>& v);

};

