/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 19:02:13 by crepou            #+#    #+#             */
/*   Updated: 2023/08/11 19:51:15 by crepou           ###   ########.fr       */
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
		Fixed operator++( void );
		Fixed operator--( void );
		Fixed& operator++( int );
		Fixed& operator--( int );
		
		~Fixed(); //destructor
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif