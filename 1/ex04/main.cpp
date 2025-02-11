#include <iostream>
#include <fstream>
#include <string>
#include <sstream>


int main(int argc, char **argv)
{
	// Checking arg nbr
	if (argc != 4)
	{
		std::cerr << "Wrong nbr of args, bro! Try './winner_sed <filename> <replaced> <replacer>' if you're a true alpha!\n";
		return 1;
	}

	// Converting replaced and replacer
	std::string replaced = argv[2];
	std::string replacer = argv[3];

	// Checking string to be replaced
	if (replaced == "")
	{
		std::cerr << "WTF! String to be replaced can't be empty man!\n";
		return 1;
	}	

	// Opening infile 
	std::ifstream infile(argv[1]);
	if (!infile)
	{
		std::cerr << "Infile not open, dude!\n";
		return 1;
	}

	// Converting infile to a string that can be manipulated
	std::stringstream buffer;
	buffer << infile.rdbuf();
	std::string fileContents = buffer.str();

	// Closing infile
	infile.close();

	// Core: Manipulating the string
	{
		int start = 0;
		while (1)
		{
			size_t pos = fileContents.find(replaced, start);
			if (pos == std::string::npos)
				break;
			fileContents.erase(pos, replaced.length());
			fileContents.insert(pos, replacer);
			start = pos + replacer.length();
		}
	}

	// Opening outfile
	std::string outfileName = argv[1];
	outfileName += ".replace";
	std::ofstream outfile(outfileName.c_str());
	if (!outfile) {
		std::cerr << "Outfile not open, dude!\n";
		return 1;
	}

	// Writing to and closing outfile
	outfile << fileContents;
	outfile.close();

	// Cocky success message
	std::cout << "We nailed it!\n";
}