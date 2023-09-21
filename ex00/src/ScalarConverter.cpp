/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:42:28 by eralonso          #+#    #+#             */
/*   Updated: 2023/09/21 13:36:01 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter( void ) {}

ScalarConverter::~ScalarConverter( void ) {}

ScalarConverter::ScalarConverter( const ScalarConverter& copy )
{
	( void )copy;
}

ScalarConverter&	ScalarConverter::operator=( const ScalarConverter& copy )
{
	( void )copy;
	return ( *this );
}

std::string	ScalarConverter::itos( int num )
{
	std::string                     str;
	std::stringstream       ss;

	ss << num;
	str = ss.str();
	return ( str );
}

bool	ScalarConverter::isDoubleType( const std::string& str )
{
}

bool	ScalarConverter::isFloatType( const std::string& str )
{
}

bool	ScalarConverter::isIntType( const std::string& str )
{
	std::string::size_type	i;
	int8_t					info;
	std::string				max_int = itos( std::numeric_limits<int>::max() );
	std::string				min_int = itos( std::numeric_limits<int>::min() );

	i = ( str[ 0 ] == '-' || str[ 0 ] == '+' ) ? 1 : 0;
	info = ( str[ 0 ] == '-' || str[ 0 ] == '+' ) ? 1 : 0;
	info |= ( str[ 0 ] == '-' ? 1 : 0 ) << 1;
	for ( ; i < str.length(); i++ )
		if ( std::isdigit( str[ i ] ) == 0 )
			return ( false );
	if ( i - ( info & 1 ) > max_int.length() )
	return (true);
}

bool	ScalarConverter::isCharType( const std::string& str )
{
	if ( str.length() == 3 && str[ 0 ] == '\'' && str[ 2 ] == '\'' && isprint( str[ 1 ] ) )
		return ( true );
	else if ( str.length() == 1 && isprint( str[ 0 ] ) )
		return ( true );
	return ( false );
}

int8_t	ScalarConverter::getType( const std::string& str )
{
	int		i;
	bool	( *checkType[ NUM_TYPES - 1 ] )( const std::string& ) = { \
										&ScalarConverter::isCharType, \
										&ScalarConverter::isIntType, \
										&ScalarConverter::isFloatType, \
										&ScalarConverter::isDoubleType };

	for ( i = 0; i < NUM_TYPES - 1 && checkType[ i ]( str ) == false; i++ )
		;
	return ( i );
}

void	ScalarConverter::convert( const std::string& toConvert )
{
	int8_t	type;

	type = getType( toConvert );
	if ( type == TYPE_INVALID )
	{
		std::cerr << ERR_MSG_INVALID_TYPE << std::endl;
		return ;
	}
}
