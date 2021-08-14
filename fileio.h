#pragma once
#include <iostream>
#include <vector>

using namespace std;

class FileIO
{
    private:
        string path;
    public:
        FileIO(string _path);
        void setPath(string _path);
        void WriteFile(string contents);
        vector<string> ReadFile();
};
