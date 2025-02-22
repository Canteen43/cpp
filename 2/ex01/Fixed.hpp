#include <ostream>
class Fixed
{
	private:
		// •An integer to store the fixed-point number value.
		int value;
		// •A static constant integer to store the number of fractional bits. Its value
		// will always be the integer literal 8.	
		static const int fbits;
	public:
		// •A default constructor that initializes the fixed-point number value to 0.
		Fixed();
		// •A copy constructor.
		Fixed(const Fixed& other);
		// •A copy assignment operator overload.
		Fixed& operator=(const Fixed& other);
		// •A destructor.
		~Fixed();
		// •A member function int getRawBits( void ) const;
		// that returns the raw value of the fixed-point value.
		int getRawBits( void ) const;
		// •A member function void setRawBits( int const raw );
		// that sets the raw value of the fixed-point number.
		void setRawBits( int const raw );
		// •A constructor that takes a constant integer as a parameter.
		// It converts it to the corresponding fixed-point value. The fractional bits value is
		// initialized to 8 like in exercise 00.
		Fixed(const int set_value);
		// •A constructor that takes a constant floating-point number as a parameter.
		// It converts it to the corresponding fixed-point value. The fractional bits value is
		// initialized to 8 like in exercise 00.
		Fixed(const float set_value);
		// •A member function float toFloat( void ) const;
		// that converts the fixed-point value to a floating-point value.
		float toFloat( void ) const;
		// •A member function int toInt( void ) const;
		// that converts the fixed-point value to an integer value.
		int toInt( void ) const;
	};
// •An overload of the insertion («) operator that inserts a floating-point representation
// of the fixed-point number into the output stream object passed as parameter.
std::ostream& operator<<(std::ostream& os, const Fixed& obj);