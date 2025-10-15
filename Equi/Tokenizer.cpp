#include "Tokenizer.h"

#include "EquiCore.h"

#include <ctype.h>
#include <set>

const std::set<char> PUNCTUATION = {
	'/','\\','{','}','(',')','.',',','+','-','*','@','>','<',':',';','\`','^','$','%','&','|','=','?','"','\'', '[',']'
};

// Checks if a token is a punctuation token
bool IsPunctuation(char c)
{
	return PUNCTUATION.count(c) != 0;
}

std::vector<Equi::Tokenizer::Token> Equi::Tokenizer::Tokenize(std::istream* input)
{
	std::vector<Equi::Tokenizer::Token> tokens;

	unsigned int line = 1;
	unsigned int character = 1;
	unsigned int startChar = 1;

	bool lineComment = false;
	bool spanComment = false;

	std::string tk = "";

	char c;
	EQUI_LOG << "[1]: ";
	while (input->get(c))
	{
		if (c == '#')
		{
			lineComment = true;
			if (tk != "")
			{
				tokens.push_back(Equi::Tokenizer::Token(tk, line, startChar));
				tk = "";
			}

			startChar = character;
		}

		if (c == '~')
		{
			spanComment = !spanComment;
			if (tk != "")
			{
				tokens.push_back(Equi::Tokenizer::Token(tk, line, startChar));
				tk = "";
			}

			startChar = character;
			character++;
			continue;
		}

		if (!lineComment && !spanComment)
		{
			if (IsPunctuation(c) || isspace(c))
			{
				if (tk != "")
				{
					tokens.push_back(Equi::Tokenizer::Token(tk, line, startChar));
					tk = "";
				}

				startChar = character;
			}

			if (IsPunctuation(c))
			{
				tk = "";
				tk = tk + c;
				tokens.push_back(Equi::Tokenizer::Token(tk, line, character));
				tk = "";
				startChar = character;
			}
			else if (!isspace(c))
			{
				tk = tk + c;
			}
		}

		character++;
		if (c == '\n')
		{
			lineComment = false;
			line++;
			character = 1;
			startChar = 1;
			EQUI_LOG << "[" << line << "]: ";
		}
	}

	for (int i = 0; i < tokens.size(); i++)
	{
		EQUI_LOG << tokens[i].DebugToken() << " ";
	}

	return tokens;
}

