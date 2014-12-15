#ifndef _COMMANDLINE_H
#define _COMMANDLINE_H

#include <string>
#include <vector>
using namespace std;

class Commandline {
    private:
        vector<string> args;

    public:
        Commandline(int, char**);
        string getCommandOption(const string&);
        bool doesCmdOptionExist(const string&);
};


#endif
