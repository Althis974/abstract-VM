//
// Created by Romeo on 24/06/2020.
//

#include "../includes/Parser.hpp"

std::vector<std::string *> const &	Parser::readFile(const char *filename)
{
	std::ifstream 					file;
	char *							line;
	std::vector<std::string *> *	instructions;


	if (access(filename, F_OK) == -1)
		throw Exception::FileDoesNotExistException();

	line = new char [BUFF_SIZE];
	instructions = new std::vector<std::string *>;

	file.open(filename);
	while (file.getline(line, BUFF_SIZE))
	{
		if (strlen(line))
			instructions->push_back(new std::string(line));

		if (!strncmp(line, "exit", 4))
			break ;
	}
	file.close();
	delete [] (line);

	if (!instructions->empty() && **(instructions->rbegin()) != "exit")
		throw Exception::MissingExitInstructionException();

	return (*instructions);
}

std::vector<std::string *> const &	Parser::readStdin()
{
	bool 							exit;
	char *							line;
	std::vector<std::string *> *	instructions;

	exit = false;
	line = new char [BUFF_SIZE];
	instructions = new std::vector<std::string *>;

	while (strncmp(line, ";;", 2) != 0)
	{
		std::cin.getline(line, BUFF_SIZE);

		if (strlen(line) && strncmp(line, ";;", 2) != 0)
			instructions->push_back(new std::string(line));

		if (!strncmp(line, "exit", 4))
			exit = true;
	}
	delete [] line;

	if (!exit)
		throw Exception::MissingExitInstructionException();

	return (*instructions);
}