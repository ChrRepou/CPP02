/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 19:02:02 by crepou            #+#    #+#             */
/*   Updated: 2023/08/11 21:15:55 by crepou           ###   ########.fr       */
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
	float	scaled_val = num * 256; //256 = 2^8 --> 8 fractional bits
	int		rounded_num = roundf(scaled_val); // rounded to get the main part of num before the .
	setRawBits(rounded_num);
}

float Fixed::toFloat( void ) const
{
	int		main_part = getRawBits() >> this->nbFractionalBits;
	int		fractional_part = getRawBits() & 255;
	float	fnum = static_cast<float>(main_part) + static_cast<float>(fractional_part) / 256;
	return	(fnum);
}

int Fixed::toInt( void ) const
{
	return (getRawBits() >> this->nbFractionalBits);
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
	os << obj.toFloat();
	return (os);
}

int Fixed::operator<(const Fixed& obj)
{
	if (this->getRawBits() < obj.getRawBits())
		return 1;
	return 0;
}

int Fixed::operator>(const Fixed& obj)
{
	if (this->getRawBits() > obj.getRawBits())
		return 1;
	return 0;
}

int Fixed::operator<=(const Fixed& obj)
{
	if (this->getRawBits() <= obj.getRawBits())
		return 1;
	return 0;
}

int Fixed::operator>=(const Fixed& obj)
{
	if (this->getRawBits() >= obj.getRawBits())
		return 1;
	return 0;
}

int Fixed::operator==(const Fixed& obj)
{
	if (this->getRawBits() == obj.getRawBits())
		return 1;
	return 0;
}

int Fixed::operator!=(const Fixed& obj)
{
	if (this->getRawBits() != obj.getRawBits())
		return 1;
	return 0;
}

Fixed Fixed::operator+(const Fixed& obj)
{
	return ( Fixed( this->toFloat() + obj.toFloat() ) );
}

Fixed Fixed::operator-(const Fixed& obj)
{
	return ( Fixed( this->toFloat() - obj.toFloat() ) );
}

Fixed Fixed::operator*(const Fixed& obj)
{
	return ( Fixed( this->toFloat() * obj.toFloat() ) );
}

Fixed Fixed::operator/(const Fixed& obj)
{
	return ( Fixed( this->toFloat() / obj.toFloat() ) );
}

Fixed Fixed::operator++( void )
{
	Fixed	newObj = Fixed(this->toFloat());
	newObj.setRawBits(this->fixedPointVal++);
	return newObj;
}

Fixed Fixed::operator--( void )
{
	Fixed	newObj = Fixed(this->toFloat());
	newObj.setRawBits(this->fixedPointVal--);
	return newObj;
}

Fixed& Fixed::operator++( int )
{
	this->setRawBits(++this->fixedPointVal);
	return (*this);
}

Fixed& Fixed::operator--( int )
{
	this->setRawBits(--this->fixedPointVal);
	return (*this);
}

Fixed& Fixed::min(Fixed& obj1, Fixed& obj2)
{
	if (obj1.getRawBits() < obj2.getRawBits())
		return (obj1);
	return (obj2);
}

const Fixed& Fixed::min(const Fixed& obj1, const Fixed& obj2)
{
	if (obj1.getRawBits() < obj2.getRawBits())
		return (obj1);
	return (obj2);
}

Fixed& Fixed::max(Fixed& obj1, Fixed& obj2)
{
	if (obj1.getRawBits() > obj2.getRawBits())
		return (obj1);
	return (obj2);
}

const Fixed& Fixed::max(const Fixed& obj1, const Fixed& obj2)
{
	if (obj1.getRawBits() > obj2.getRawBits())
		return (obj1);
	return (obj2);
}