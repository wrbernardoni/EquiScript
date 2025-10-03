#include "EquiCore.h"

#include <iostream>

std::ostream* Equi::gLog = &std::cout;
std::ostream* Equi::gErr = &std::cerr;

void Equi::Initialize(Equi::CoreSettings settings)
{
	Equi::gLog = settings.log;
	Equi::gErr = settings.errorLog;
}
