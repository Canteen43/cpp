#include <iostream>
#include <sstream>








class Contact {
private:
	std::string firstname;
	std::string lastname;
	std::string nickname;
	std::string phonenumber;
	std::string secret;

public:
	void overwrite(const std::string& first, const std::string& last, const std::string& nick, const std::string& phone, const std::string& sec) {
		
		firstname = first;
		lastname = last;
		nickname = nick;
		phonenumber = phone;
		secret = sec;
	}
	std::string get_first() const { return firstname; }  
	std::string get_last() const { return lastname; }  
	std::string get_nick() const { return nickname; }  
	std::string get_phone() const { return phonenumber; }  
	std::string get_sec() const { return secret; }  
};


















class PhoneBook {
private:
	Contact contacts[8];
	int		index_next;
	int		nbr_of_contacts;

public:

	PhoneBook() : index_next(0), nbr_of_contacts(0) {}

	void add(const std::string& first, const std::string& last, const std::string& nick, const std::string& phone, const std::string& sec)
	{	
		contacts[index_next].overwrite(first, last, nick, phone, sec);
		if (nbr_of_contacts < 8)
			nbr_of_contacts ++;
		index_next++;
		index_next %= 8;
	}

	std::string ten_chars(std::string str)
	{
		int	len = str.length();
		if (len < 10)
			str.insert(0, 10 - len, ' ');
		else if (len > 10)
		{
			str.resize(9);
			str += ".";
		}
		return str;
	}

	void print_overview()
	{
		std::cout << "     INDEX|FIRST NAME| LAST NAME|  NICKNAME\n";
		for (int i = 0; i < nbr_of_contacts; i++)
		{
			std::cout << "         " << i << "|";
			std::cout << ten_chars(contacts[i].get_first()) << "|";
			std::cout << ten_chars(contacts[i].get_last()) << "|"; 
			std::cout << ten_chars(contacts[i].get_nick()) << "\n";
		}
	}

	void print_contact(int index)
	{
		if (index >= nbr_of_contacts)
		{
			std::cout <<"No contact with that index.\n";
			return ;
		}
		std::cout << contacts[index].get_first() << "\n";
		std::cout << contacts[index].get_last() << "\n";
		std::cout << contacts[index].get_nick() << "\n";
		std::cout << contacts[index].get_phone() << "\n";
		std::cout << contacts[index].get_sec() << "\n";
	}

	bool is_empty()
	{
		if (nbr_of_contacts == 0)
			return true;
		return false;
	}
	
};


























void get_non_empty_line(std::string prompt, std::string& line)
{
	std::cout << prompt;
	std::getline(std::cin, line);
	while (line.empty())
	{
		std::cout << "Line cannot be empty. Try again: ";
		std::getline(std::cin, line);
	}
}

int main() {
	std::string input = "";
	std::string first = "";
	std::string last = "";
	std::string nick = "";
	std::string phone = "";
	std::string sec = "";
	PhoneBook book;
	int		index;


	while (1)
	{
		std::cout << "What should a phonebook do: ";
		if (!std::getline(std::cin, input) && std::cin.eof())
		{
			std::cout << "EXIT\n";
			break;
		}
		if (input == "EXIT")
			break;
		else if (input == "MULTIADD")
		{
			for (int i = 0; i < 9; i++)
			{
				std::stringstream ss;
				ss << i;
				sec = ss.str();
				book.add(sec, sec, sec, sec, sec);
			}
		}
		else if (input == "ADD")
		{
			get_non_empty_line("Enter first name: ", first);
			get_non_empty_line("Enter last name: ", last);
			get_non_empty_line("Enter nickname: ", nick);
			get_non_empty_line("Enter phone number: ", phone);
			get_non_empty_line("Enter their darkest secret: ", sec);
			book.add(first, last, nick, phone, sec);
		}
		else if (input == "SEARCH")
		{
			if (book.is_empty())
			{
				std::cout << "Phonebook is empty. Try ADD.\n";
				continue ;
			}
			book.print_overview();
			std::cout << "Enter index of desired contact: ";
			std::getline(std::cin, input);
			while (1)
			{
				std::stringstream ss(input);
				ss >> index;
				if (ss.fail())
				{

					std::cout << "Try entering a valid number, Sherlock: ";
					std::getline(std::cin, input);
				}
				else
					break;
			}
			book.print_contact(index);
		}
		else
			std::cout << "Try ADD, SEARCH or EXIT :)\n";

	}
	std::cout << "Thank you for using Phonebook :)\n";
	return 0;
}
