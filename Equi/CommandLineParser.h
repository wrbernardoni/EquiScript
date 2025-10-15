#ifndef COMMAND_LINE_PARSER_H_
#define COMMAND_LINE_PARSER_H_

#include <iostream>

struct CmdLineArgs
{
	bool run = true;
	bool error = false;
	bool dumpTokens = false;
	std::istream* input = &std::cin;
	std::ostream* log = &std::cout;
	std::ostream* errorLog = &std::cerr;
};

CmdLineArgs ParseArguments(int argc, char* argv[]);

#endif
