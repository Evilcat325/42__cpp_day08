#ifndef FT_MINDOPEN_HPP
#define FT_MINDOPEN_HPP

#include <vector>
#include <stack>
#include <map>
#include <string>
#include <fstream>
#include <iostream>

class MindOpen
{
	typedef void (MindOpen::*Instruction)();

private:
	unsigned int data_ptr;
	unsigned int instruction_ptr;
	std::vector<char> data;
	std::vector<Instruction> instructions;
	std::map<int, int> m;

public:
	static std::string cmds;
	static bool verbose;
	MindOpen();
	~MindOpen();
	MindOpen(MindOpen const &rhs);
	MindOpen &operator=(MindOpen const &rhs);
	bool parse(std::string &filename);
	void inc_data_ptr();
	void dec_data_ptr();
	void inc_data();
	void dec_data();
	void out_char();
	void get_char();
	void loop_start();
	void loop_end();
	void exec();
};

#endif /* FT_MindOpen_HPP */
