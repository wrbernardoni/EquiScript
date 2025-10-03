// Equi.cpp : Defines the entry point for the application.
//

#include "Equi.h"

#include "EquiConfig.h"
#include "EquiCore.h"
#include "CommandLineParser.h"

using namespace std;

int main(int argc, char* argv[])
{
	CmdLineArgs args = ParseArguments(argc, argv);

	Equi::CoreSettings coreSettings;
	coreSettings.log = args.log;
	coreSettings.errorLog = args.errorLog;
	Equi::Initialize(coreSettings);

	if (args.error)
	{
		*Equi::gErr << "Error: Command line arguments not properly parsed.\n";
		return 1;
	}

	return 0;
}
