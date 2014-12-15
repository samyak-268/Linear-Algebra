#ifndef _COMMANDLINE_CPP
#define _COMMANDLINE_CPP

#include "commandline.h"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

Commandline::Commandline(int argc, char** argv) 
{
    for(int i = 1; i < argc; ++i) {
        args.push_back(argv[i]);
    }
}

string Commandline::getCommandOption(const string& opt)
{
    string answer;
    vector<string>::const_iterator it = find(args.begin(), args.end(), opt);
    if(it != args.end() && (++it != args.end()))
        answer = *it;
    return answer;
}


bool Commandline::doesCmdOptionExist(const string& opt)
{
    vector<string>::const_iterator it = find(args.begin(), args.end(), opt);
    return (it != args.end());
}

#endif
