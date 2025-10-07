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
		EQUI_ERR << "ERROR: Command line arguments not properly parsed.\n";
		return 1;
	}

	// TODO: Tokenize input & record debugging info (line nums ect.)

	// TODO: Parse into AST

	// TODO: Turn AST into EquiCode

	// TODO: Run EquiCode on an engine.

	return 0;
}
