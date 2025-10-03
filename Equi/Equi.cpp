// Equi.cpp : Defines the entry point for the application.
//

#include "Equi.h"

#include "EquiConfig.h"
#include "EquiCore.h"

using namespace std;

int main(int argc, char* argv[])
{
    std::cout << "EquiLang Version " << EQUI_VERSION_MAJOR << "."
        << EQUI_VERSION_MINOR << std::endl;
	Equi::HelloWorld();

	return 0;
}
