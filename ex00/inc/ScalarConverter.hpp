/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:42:28 by eralonso          #+#    #+#             */
/*   Updated: 2023/09/21 16:06:54 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <limits>

#define NUM_TYPES 5

#define TYPE_CHAR 0
#define TYPE_INT 1
#define TYPE_FLOAT 2
#define TYPE_DOUBLE 3
#define TYPE_INVALID ( NUM_TYPES - 1 )

#define MINUS_INFF_LIMIT 0
#define PLUS_INFF_LIMIT 1
#define NANF_LIMIT 2
#define MINUS_INF_LIMIT 3
#define PLUS_INF_LIMIT 4
#define NAN_LIMIT 5
#define NOT_LIMIT 6

#define	LIMITS_FLOAT 3
#define	LIMITS_DOUBLE 7

#define ERR_MSG_INVALID_TYPE "Invalid type of literal\n\tAllowed literals are: [ Char -> 'a' ] | [ Int -> 1 ] | [ Float -> 1.5f ] | [ Double -> 1.5 ]"

class ScalarConverter
{
	private:
		
		static int8_t		getType( const std::string& str );
		static std::string	itos( int num );
		static int8_t		checkInfNan( const std::string& str, int8_t type );
		static bool			checkCharLiteral( const std::string& str );
		static bool			checkIsChar( const std::string& str, int ( *f )( int ) );
		static bool			isCharType( const std::string& str );
		static bool			isIntType( const std::string& str );
		static bool			isFloatType( const std::string& str );
		static bool			isDoubleType( const std::string& str );
		static bool			isInvalidType( const std::string& str );
		static void			printChar( const std::string& str );
		static void			printInt( const std::string& str );
		static void			printFloat( const std::string& str );
		static void			printDouble( const std::string& str );
	public:
		ScalarConverter( void );
		~ScalarConverter( void );
		ScalarConverter( const ScalarConverter& copy );
		ScalarConverter&	operator=( const ScalarConverter& copy );
		static void			convert( const std::string& toConvert );
};
