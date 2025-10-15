#include "CommandLineParser.h"
#include "EquiConfig.h"
#include "EquiCore.h"

#include <cstring>
#include <fstream>

CmdLineArgs ParseArguments(int argc, char* argv[])
{
	CmdLineArgs args;

	int parsedArgs = 0;
	for (int head = 1; head < argc; head++)
	{
		if (strcmp(argv[head], "-v") == 0 || strcmp(argv[head], "-VERSION") == 0)
		{
			if (parsedArgs != 0 || (head < (argc-1)))
			{
				std::cerr << "ERROR: Too many arguments, -v|-VERSION must be the only argument.\n";
				args.error = true;
				break;
			}

			args.run = false;

			std::cout << "Equi version " << EQUI_VERSION_MAJOR << "."
				<< EQUI_VERSION_MINOR << std::endl;
			parsedArgs++;
			
		}
		else if (strcmp(argv[head], "-DEBUG_TOKENS") == 0)
		{
			args.dumpTokens = true;

		}
		else if (strcmp(argv[head], "-f") == 0)
		{
			if (args.input != &std::cin)
			{
				std::cerr << "Input file already specified.\n";
				args.error = true;
				break;
			}
			if (head == argc - 1)
			{
				std::cerr << "Need additional input to specify the file to read.\n";
				args.error = true;
				break;
			}

			args.input = new std::ifstream(argv[head+1]);
			if (!args.input->good())
			{
				std::cerr << "Failed to open file" << argv[head + 1] << "\n";
				args.error = true;
				break;
			}
			head++;
		}
	}

	return args;
}