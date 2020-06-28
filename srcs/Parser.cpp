//
// Created by Romeo on 24/06/2020.
//

#include "../includes/Parser.hpp"

/*
void 								Parser::clean()
{
	std::cout << "clean" << std::endl;
	delete [] Parser::tmp;
}*/

Parser::Parser()
{

}

Parser::~Parser()
{
	auto it = this->_instructions->begin();
	while (this->_instructions->end() != it)
	{
		delete *it;
		++it;
	}
	delete this->_instructions;
	this->_instructions = nullptr;
}

std::vector<std::string *> const &	Parser::readFile(const char *filename)
{
	std::ifstream 					file;
	char *							line;
	//std::vector<std::string *> *	instructions;


	if (access(filename, F_OK) == -1)
		throw Exception::FileDoesNotExistException();

	line = new char [BUFF_SIZE];
	this->_instructions = new std::vector<std::string *>;

	file.open(filename);
	while (file.getline(line, BUFF_SIZE))
	{
		if (strlen(line))
		{
			//Parser::tmp = new std::string(line);
			//instructions->push_back(Parser::tmp);
			this->_instructions->push_back(new std::string(line));
		}

		if (!strncmp(line, "exit", 4))
			break ;
	}
	file.close();
	delete [] (line);

	//std::cout << "begin= " << **(instructions->rbegin()) << std::endl;
	if (!this->_instructions->empty() && **(this->_instructions->rbegin()) != "exit")
		throw Exception::MissingExitInstructionException();

	return (*this->_instructions);
}

std::vector<std::string *> const &	Parser::readStdin()
{
	bool 							exit;
	char *							line;
	//std::vector<std::string *> *	instructions;

	exit = false;
	line = new char [BUFF_SIZE];
	this->_instructions = new std::vector<std::string *>;

	while (strncmp(line, ";;", 2) != 0)
	{
		std::cin.getline(line, BUFF_SIZE);

		if (strlen(line) && strncmp(line, ";;", 2) != 0)
			this->_instructions->push_back(new std::string(line));

		if (!strncmp(line, "exit", 4))
			exit = true;
	}
	delete [] line;

	if (!exit)
		throw Exception::MissingExitInstructionException();

	return (*this->_instructions);
}