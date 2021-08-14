#include <iostream>
#include <fstream>
#include <vector>
#include "fileio.h"

using namespace std;

FileIO::FileIO(string _path)
{
    setPath(_path);
}

void FileIO::setPath(string _path)
{
    path = _path;
}

void FileIO::WriteFile(string contents)
{
    ofstream ofs(path, ios_base::app);
    ofs << contents << endl;
    ofs.close();
}

vector<string> FileIO::ReadFile()
{
    vector<string> lines;
    ifstream ifs(path);
    for(string line; getline(ifs, line);)
    {
        lines.push_back(line);
    }
    ifs.close();
    return lines;
}
