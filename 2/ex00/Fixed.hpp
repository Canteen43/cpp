class Fixed
{
	private:
		// 	◦An integer to store the fixed-point number value.
		int value;
		// ◦A static constant integer to store the number of fractional bits. Its value
		// will always be the integer literal 8.	
		static const int fbits;
	public:
		// ◦A default constructor that initializes the fixed-point number value to 0.
		Fixed();
		// ◦A copy constructor.
		Fixed(const Fixed& other);
		// ◦A copy assignment operator overload.
		Fixed& operator=(const Fixed& other);
		// ◦A destructor.
		~Fixed();
		// ◦A member function int getRawBits( void ) const;
		// that returns the raw value of the fixed-point value.
		int getRawBits( void ) const;
		// ◦A member function void setRawBits( int const raw );
		// that sets the raw value of the fixed-point number.
		void setRawBits( int const raw );

};