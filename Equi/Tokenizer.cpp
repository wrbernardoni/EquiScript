#include "Tokenizer.h"

#include "EquiCore.h"

std::vector<Equi::Tokenizer::Token> Equi::Tokenizer::Tokenize(std::istream* input)
{
	std::vector<Equi::Tokenizer::Token> tokens;

	unsigned int line = 1;
	unsigned int character = 1;

	char c;
	EQUI_LOG << "[1]: ";
	while (input->get(c))
	{
		
		EQUI_LOG << c;
		character++;
		if (c == '\n')
		{
			line++;
			character = 1;
			EQUI_LOG << "[" << line << "]: ";
		}
	}

	return tokens;
}

