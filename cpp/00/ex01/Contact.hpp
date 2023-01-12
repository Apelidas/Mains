
#include <iostream>

class Contact
{
	public:
		std::string get_first();
		std::string get_last();
		std::string get_nick();
		std::string get_number();
		std::string get_secret();
		void		set_first(std::string in);
		void		set_last(std::string in);
		void		set_nick(std::string in);
		void		set_number(std::string in);
		void		set_secret(std::string in);

	private:
		std::string first;
		std::string last;
		std::string nick;
		std::string number;
		std::string secret;
};