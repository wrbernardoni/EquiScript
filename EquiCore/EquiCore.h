#ifndef EQUI_CORE_H_
#define EQUI_CORE_H_

#include <iostream>

#define EQUI_LOG (*Equi::gLog)
#define EQUI_ERR (*Equi::gErr)

namespace Equi
{
	extern std::ostream* gLog;
	extern std::ostream* gErr;

	struct CoreSettings
	{
		std::ostream* log;
		std::ostream* errorLog;
	};

	void Initialize(CoreSettings);
};

#endif