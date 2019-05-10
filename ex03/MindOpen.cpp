#include "MindOpen.hpp"

std::string MindOpen::cmds = "><+-.,[]";
bool MindOpen::verbose = false;

MindOpen::MindOpen()
		: data_ptr(0), instruction_ptr(0)
{
	data.push_back(0);
}

MindOpen::~MindOpen()
{
}

MindOpen::MindOpen(MindOpen const &rhs)
		: data_ptr(rhs.data_ptr), instruction_ptr(rhs.instruction_ptr),
			data(rhs.data), instructions(rhs.instructions)
{
	*this = rhs;
}

MindOpen &MindOpen::operator=(MindOpen const &rhs)
{
	data_ptr = rhs.data_ptr;
	instruction_ptr = rhs.instruction_ptr;
	data = rhs.data;
	instructions = instructions;
	return *this;
}

bool MindOpen::parse(std::string &filename)
{
	Instruction dispatch[] = {
			&MindOpen::inc_data_ptr,
			&MindOpen::dec_data_ptr,
			&MindOpen::inc_data,
			&MindOpen::dec_data,
			&MindOpen::out_char,
			&MindOpen::get_char,
			&MindOpen::loop_start,
			&MindOpen::loop_end};
	std::ifstream fin(filename);
	if (!fin)
		return false;
	std::stack<unsigned int> s;
	char c;
	while (fin.get(c))
	{
		size_t pos = cmds.find(c);
		if (pos == std::string::npos)
			continue;

		if (pos == 6)
			s.push(instructions.size());
		else if (pos == 7)
		{
			unsigned int match = s.top();
			m[match] = instructions.size();
			m[instructions.size()] = match;
			s.pop();
		}
		instructions.push_back(dispatch[pos]);
		std::cout << c;
	}
	std::cout << std::endl;
	// std::cout << instructions.size() << std::endl;
	// for (int i = 0, e = instructions.size(); i < e; ++i)
	// 	std::cout << m[i] << std::endl;
	return true;
}

void MindOpen::inc_data_ptr()
{
	++data_ptr;
	if (data_ptr >= data.size())
		data.push_back(0);
	++instruction_ptr;
	if (verbose)
		std::cout << "increment data ptr to " << data_ptr << std::endl;
}

void MindOpen::dec_data_ptr()
{
	--data_ptr;
	++instruction_ptr;
	if (verbose)
		std::cout << "decrement data ptr to " << data_ptr << std::endl;
}

void MindOpen::inc_data()
{
	data[data_ptr]++;
	++instruction_ptr;
	if (verbose)
		std::cout << "increment data at " << data_ptr
							<< " to " << static_cast<int>(data[data_ptr]) << std::endl;
}

void MindOpen::dec_data()
{
	data[data_ptr]--;
	++instruction_ptr;
	if (verbose)
		std::cout << "decrement data at " << data_ptr
							<< " to " << static_cast<int>(data[data_ptr]) << std::endl;
}

void MindOpen::out_char()
{
	std::cout << data[data_ptr];
	++instruction_ptr;
}

void MindOpen::get_char()
{
	char c;
	std::cin.get(c);
	data[data_ptr] = c;
	++instruction_ptr;
}

void MindOpen::loop_start()
{
	if (verbose)
		std::cout << "loop start setting instruction ptr from " << instruction_ptr;
	if (data[data_ptr] == 0)
		instruction_ptr = m[instruction_ptr];
	else
		instruction_ptr++;
	if (verbose)
		std::cout << " to " << instruction_ptr << std::endl;
}

void MindOpen::loop_end()
{
	if (verbose)
		std::cout << "loop end setting instruction ptr from " << instruction_ptr;
	if (data[data_ptr] != 0)
		instruction_ptr = m[instruction_ptr];
	else
		instruction_ptr++;
	if (verbose)
		std::cout << " to " << instruction_ptr << std::endl;
}

void MindOpen::exec()
{
	unsigned int end = instructions.size();
	while (instruction_ptr < end)
	{
		(this->*instructions[instruction_ptr])();
	}
}
