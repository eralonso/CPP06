/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:42:28 by eralonso          #+#    #+#             */
/*   Updated: 2023/09/21 13:29:21 by eralonso         ###   ########.fr       */
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

#define ERR_MSG_INVALID_TYPE "Invalid type of literal\n\tAllowed literals are: [ Char -> 'a' ] | [ Int -> 1 ] | [ Float -> 1.5f ] | [ Double -> 1.5 ]"

class ScalarConverter
{
	private:
		static int8_t		getType( const std::string& str );
		static std::string	itos( int num );
		static bool			isCharType( const std::string& str );
		static bool			isIntType( const std::string& str );
		static bool			isFloatType( const std::string& str );
		static bool			isDoubleType( const std::string& str );
		static bool			isInvalidType( const std::string& str );
	public:
		ScalarConverter( void );
		~ScalarConverter( void );
		ScalarConverter( const ScalarConverter& copy );
		ScalarConverter&	operator=( const ScalarConverter& copy );
		static void			convert( const std::string& toConvert );
};
