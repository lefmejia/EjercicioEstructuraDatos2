#pragma once
#ifndef FIXEDSIZE_REGISTER
#define FIXEDSIZE_REGISTER
#define NAMESIZE 30
#define JOBSIZE 20
#include "DataFile.h"

struct Estructura
{
	int code;
	char job[JOBSIZE];
	double salary;
	char name[NAMESIZE];
};

class FixedSize_Register
{
public:
	FixedSize_Register();
	void print_register();
	char* toChar();
	void fromChar(char*);
	void open_file(char*);
	void write_into_file();
	void read_from_file(int);
	void close_file();
	int get_size();

private:
	DataFile* file;
	int code;
	char* name;
	double salary;
	char* job;
};

#endif // !FIXEDSIZE_REGISTER
