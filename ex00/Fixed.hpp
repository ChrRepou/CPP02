#ifndef FIXED_H_
#define FIXED_H_

#include <iostream>

class Fixed {
	private:
		int	fixedPointVal;
		static const int nbFractionalBits = 8;

	public:
		Fixed(); //default constructor
		Fixed(const Fixed& num); //copy constructor
		Fixed& operator=(const Fixed& obj); //copy assignment operator overload.
		~Fixed(); //destructor
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};

#endif