/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 19:02:13 by crepou            #+#    #+#             */
/*   Updated: 2023/08/11 21:23:58 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H_
#define FIXED_H_

#include <iostream>
#include <cmath>

class Fixed {
	private:
		int	fixedPointVal;
		static const int nbFractionalBits = 8;

	public:
		Fixed(); //default constructor
		Fixed(const int num);
		Fixed(const float num);
		Fixed(const Fixed& num); //copy constructor
		~Fixed(); //destructor
		Fixed& operator=(const Fixed& obj); //copy assignment operator overload.
		
		//comparison operators
		int operator<(const Fixed& obj);
		int operator>(const Fixed& obj);
		int operator<=(const Fixed& obj);
		int operator>=(const Fixed& obj);
		int operator==(const Fixed& obj);
		int operator!=(const Fixed& obj);

		//arithmetic operators
		Fixed operator+(const Fixed& obj);
		Fixed operator-(const Fixed& obj);
		Fixed operator*(const Fixed& obj);
		Fixed operator/(const Fixed& obj);

		//increament/decreament operators
		Fixed operator++( int );
		Fixed operator--( int );
		Fixed& operator++( void );
		Fixed& operator--( void );
		
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
		static Fixed& min(Fixed& obj1, Fixed& obj2);
		static const Fixed& min(const Fixed& obj1, const Fixed& obj2);
		static Fixed& max(Fixed& obj1, Fixed& obj2);
		static const Fixed& max(const Fixed& obj1, const Fixed& obj2);
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif