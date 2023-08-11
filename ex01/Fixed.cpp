/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 20:02:29 by crepou            #+#    #+#             */
/*   Updated: 2023/08/11 17:05:41 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->setRawBits(0);
}

Fixed::Fixed(const Fixed& num)
{
	std::cout << "Copy constructor called" << std::endl;
	this->fixedPointVal = num.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj) { // Check self-assignment
		fixedPointVal = obj.getRawBits();
	}
	return *this; // Return the modified object
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixedPointVal);
}

void Fixed::setRawBits( int const raw )
{
	this->fixedPointVal = raw;
}

Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called" << std::endl;
	setRawBits(num << this->nbFractionalBits);
}

Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called" << std::endl;
	int		scaled_val = static_cast<int>(num * 256); //256 = 2^8 --> 8 fractional bits
	int		rounded_num = roundf(scaled_val); // rounded to get the main part of num before the .
	int		fractional_part = roundf((scaled_val - rounded_num) * 256); //get fractional part
	int		fixed_point_num = (rounded_num << this->nbFractionalBits) | fractional_part; //combine main part and fractional part
	setRawBits(fixed_point_num); 
}

float Fixed::toFloat( void ) const
{
	int		main_part = this->fixedPointVal >> this->nbFractionalBits;
	int		fractional_part = this->fixedPointVal & ((1 << this->nbFractionalBits) - 1);
	float	fnum = static_cast<float>(main_part) + static_cast<float>(fractional_part) / 256;
	return	(fnum);
}

int Fixed::toInt( void ) const
{
	return (this->fixedPointVal >> this->nbFractionalBits);
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
	os << obj.toFloat();
	return (os);
}