#ifndef EQUI_TOKENIZER_H_
#define EQUI_TOKENIZER_H_

#include <vector>
#include <iostream>
#include <string>

namespace Equi
{
	namespace Tokenizer
	{
		class Token
		{
		private:
			unsigned int lineNum;
			unsigned int charNum;
			std::string token;
		public:
			Token(std::string t, unsigned int lN = 0, unsigned int cN = 0) : lineNum(lN), charNum(cN)
			{
				token = t;
			};
		};

		std::vector<Token> Tokenize(std::istream* input);
	};
};

#endif
