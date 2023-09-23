/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:42:28 by eralonso          #+#    #+#             */
/*   Updated: 2023/09/23 16:21:58 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <limits>

// Number of type
#define NUM_TYPES 5

// Format types
#define TYPE_CHAR 0
#define TYPE_INT 1
#define TYPE_FLOAT 2
#define TYPE_DOUBLE 3
#define TYPE_INVALID ( NUM_TYPES - 1 )

// Limits exceptions
#define MINUS_INFF_LIMIT -1
#define PLUS_INFF_LIMIT -2
#define NANF_LIMIT -3
#define MINUS_INF_LIMIT -4
#define PLUS_INF_LIMIT -5
#define NAN_LIMIT -6
#define NOT_LIMIT -7

// Flags for Limits exceptions
#define	LIMITS_FLOAT 3
#define	LIMITS_DOUBLE 7

// Error message
#define ERR_MSG_INVALID_TYPE "Invalid type of literal\n\tAllowed literals are: [ Char -> 'a' ] | [ Int -> 1 ] | [ Float -> 1.5f ] | [ Double -> 1.5 ]"

// Flags for non displayable and impossible conversions
#define PRINT_OK 0
#define NON_DISPLAYABLE 1
#define IMPOSSIBLE_CONV ( 1 << 1 )
#define PLUS_INFINIT_CASE ( 1 << 2 )
#define MINUS_INFINIT_CASE ( 1 << 3 )
#define NAN_CASE ( 1 << 4 )
#define OVER_UNDER_FLOW ( 1 << 5 )

typedef struct	s_types
{
	char	c;
	int		c_flag;
	int		i;
	int		i_flag;
	float	f;
	int		f_flag;
	double	d;
	int		d_flag;
}	t_types;

class ScalarConverter
{
	private:
		
		static int		getType( const std::string& str );
		static int		checkInfNan( const std::string& str, int type );
		static bool			controlExceptions( const std::string& str, t_types& t, int limits );
		static bool			isCharType( const std::string& str );
		static bool			isIntType( const std::string& str );
		static bool			isFloatType( const std::string& str );
		static bool			isDoubleType( const std::string& str );
		// static bool			isInvalidType( const std::string& str );
		static bool			convertChar( const std::string& str, t_types& t );
		static bool			convertInt( const std::string& str, t_types& t );
		static bool			convertFloat( const std::string& str, t_types& t );
		static bool			convertDouble( const std::string& str, t_types& t );
		static void			printTypes( const t_types& t );	
		static bool			checkPrint( std::string type, int flag );
	public:
		ScalarConverter( void );
		~ScalarConverter( void );
		ScalarConverter( const ScalarConverter& copy );
		ScalarConverter&	operator=( const ScalarConverter& copy );
		static void			convert( const std::string& toConvert );
};
