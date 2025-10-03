#include "CommandLineParser.h"
#include "EquiConfig.h"

#include <cstring>

CmdLineArgs ParseArguments(int argc, char* argv[])
{
	CmdLineArgs args;

	for (int head = 1; head < argc; head++)
	{
		if (strcmp(argv[head], "-v") == 0 || strcmp(argv[head], "-VERSION") == 0)
		{
			std::cout << "Equi version " << EQUI_VERSION_MAJOR << "."
				<< EQUI_VERSION_MINOR << std::endl;
		}
	}

	return args;
}