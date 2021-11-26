#include <iostream>
#include <fstream>
#include <string>  
#include <ios>

int	error_and_quit(std::string err)
{
	std::cerr << "Error: " << err << std::endl;
	return (1);
}

std::string	get_modified_line(std::string s1, std::string s2, std::string line, size_t cursor)
{
	std::string	str;
	size_t		i = 0;
	
	while(cursor != std::string::npos)
	{
		str += line.substr(i, (cursor - i));
		str += s2;
		i = cursor + s1.length();
		cursor = line.find(s1, i);
		if (cursor == std::string::npos)
			str += line.substr(i, cursor);
	}
	return (str);
}

int main(int ac, char **argv)
{
	std::string		s1;
	std::string		s2;
	std::ifstream	ifs;
	std::ofstream	ofs;
	std::string		output_filename;
	std::string		line;
	//INIT AND VERIF
	if (ac != 4)
		return (error_and_quit("Bad number of arguments, must have 2 non empty strings and a valid filename"));
	s1 = (argv[1]);
	s2 = (argv[2]);
	if (s1.empty() || s2.empty())
		return (error_and_quit("Must have 2 non empty strings"));
	output_filename = (argv[3]);
	output_filename += ".replace";
	ifs.open(argv[3]);
	if (ifs.fail())
		return (error_and_quit("problem when open infile"));
	ofs.open(output_filename.c_str());
	if (ofs.fail())
	{	
		ifs.close();
		return (error_and_quit("problem when open outfile"));
	}
	//WRITE IN OFS AND REPLACE OCCURENCE OF S1 BY S2
	size_t			cursor;

	while (true)
	{	
		std::getline(ifs,line);
		if (ifs.fail() && !ifs.eof())
			return (error_and_quit("cannot read line correctly"));
		cursor = line.find(s1);
		if (cursor == std::string::npos)
			ofs << line;
		else
			ofs << get_modified_line(s1, s2, line, cursor);
		if (!ifs.eof())
			ofs << std::endl;
		else
			break ;
	}
	ifs.close();
	ofs.close();
	return (0);
}
