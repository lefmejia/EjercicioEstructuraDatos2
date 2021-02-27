#pragma once
#ifndef KNOWNVARSIZE_REGISTER
#define KNOWNVARSIZE_REGISTER
#include "DataFile.h"

class  KnownVarSize_Register
{
public:
	KnownVarSize_Register();
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
	int sizeName;
	char* name;
	double salary;
	int sizeJob;
	char* job;
};

#endif // !KNOWNVARSIZE_REGISTER
