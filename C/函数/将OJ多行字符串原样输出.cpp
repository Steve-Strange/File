#include <cstdio>
#include <cstring>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

char *infilename, *outfilename;
bool flag; int line = 100;

inline void help(char *name)
{
	cerr << "Usage:" << endl;
	cerr << name << " " << "in_filename" << " " << "[out_filename]" << " " << "[byte_per_line]" << endl;
	exit(-1);
}

ifstream fin;
ofstream fout;

int main(int argc, char** argv)
{
	switch(argc)
	{
	case 4: line = atoi(argv[3]);
	case 3: outfilename = argv[2];
	case 2: infilename = argv[1];
	break;
	default: help(argv[0]);
	}
	fin.open(infilename, ios::in);
	if(!fin)
	{
		cerr << "Cannot read the infile." << endl;
		exit(-1);
	}
	if(outfilename == NULL)
	{
		stringstream ss;
		ss << infilename << ".out";
		fout.open(ss.str().c_str(), ios::out);
	}
	else
	{
		fout.open(outfilename, ios::out);
	}
	if(!fout)
	{
		cerr << "Cannot write the outfile." << endl;
		exit(-1);
	}
	char ch; int cnt = 0;
	while(fin >> noskipws >> ch)
	{
		cnt++;
		fout << "\\x" << hex << (int)(unsigned char)ch;
		if(cnt == line)
		{
			cnt = 0;
			fout << "\\" << endl;
		}
	}
	return 0;
}
