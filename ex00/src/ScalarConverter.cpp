/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:42:28 by eralonso          #+#    #+#             */
/*   Updated: 2023/09/22 13:36:42 by eralonso         ###   ########.fr       */
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

int8_t	ScalarConverter::checkInfNan( const std::string& str, int8_t type )
{
	int8_t		limit;
	std::string	arr[ 6 ] = { \
							"-inff", "+inff", "nanf", \
							"-inf", "+inf", "nan" };
	int8_t		types[ 8 ] = { \
								MINUS_INFF_LIMIT, PLUS_INFF_LIMIT, NANF_LIMIT, \
								NOT_LIMIT, \
								MINUS_INF_LIMIT, PLUS_INF_LIMIT, NAN_LIMIT, \
								NOT_LIMIT };
	
	for ( limit = type - 3; limit < type && str.compare( arr[ limit ] ); limit++ )
		;
	return ( types[ limit ] );
}

bool	ScalarConverter::isDoubleType( const std::string& str )
{
	std::string::size_type	i;
	int8_t					dot;

	if ( checkInfNan( str, LIMITS_DOUBLE ) != NOT_LIMIT )
		return ( true );
	i = ( str[ 0 ] == '-' || str[ 0 ] == '+' ) ? 1 : 0;
	dot = 0;
	for ( ; i < str.length(); i++ )
	{
		if ( std::isdigit( str[ i ] ) == 0 || str[ i ] == '.' )
			return ( false );
		if ( str[ i ] == '.' && dot )
			return ( false );
		else if ( str[ i ] == '.' )
			dot = 1;
	}
	if ( dot == 0 || str.length() < 2 )
		return ( false );
	return ( true );
}

bool	ScalarConverter::isFloatType( const std::string& str )
{
	std::string::size_type	i;
	int8_t					dot;

	if ( checkInfNan( str, LIMITS_FLOAT ) != NOT_LIMIT )
		return ( true );
	i = ( str[ 0 ] == '-' || str[ 0 ] == '+' ) ? 1 : 0;
	dot = 0;
	for ( ; i < str.length() && str[ i ] != 'f'; i++ )
	{
		if ( std::isdigit( str[ i ] ) == 0 || str[ i ] == '.' )
			return ( false );
		if ( str[ i ] == '.' && dot )
			return ( false );
		else if ( str[ i ] == '.' )
			dot = 1;
	}
	if ( str[ i ] != 'f' || str[ i + 1 ] != '\0' || dot == 0 || str.length() < 3 )
		return ( false );
	return ( true );
}

bool	ScalarConverter::isIntType( const std::string& str )
{
	std::string::size_type	i;

	i = ( str[ 0 ] == '-' || str[ 0 ] == '+' ) ? 1 : 0;
	for ( ; i < str.length(); i++ )
		if ( std::isdigit( str[ i ] ) == 0 )
			return ( false );
	return (true);
}

// bool	ScalarConverter::checkIsChar( const std::string& str, int ( *f )( int ) )
// {
// 	int	value;

// 	if ( str.length() > 0 && str.length() < 4 && isIntType( str ) )
// 	{
// 		value = std::stoi( str );
// 		return ( f( value ) );
// 	}
// 	return ( false );
// }

bool	ScalarConverter::checkCharLiteral( const std::string& str )
{
	return ( ( str.length() == 3 && str[ 0 ] == '\'' && str[ 2 ] == '\'' ) );
}

bool	ScalarConverter::isCharType( const std::string& str )
{
	return ( checkCharLiteral( str ) );
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
	t_types	t;
	bool	( *convert[ NUM_TYPES - 1 ] )( const std::string&, t_types& ) = { \
										&ScalarConverter::convertChar, \
										&ScalarConverter::convertInt, \
										&ScalarConverter::convertFloat, \
										&ScalarConverter::convertDouble };

	type = getType( toConvert );
	if ( type == TYPE_INVALID )
	{
		std::cerr << ERR_MSG_INVALID_TYPE << std::endl;
		return ;
	}
	bzero( &t, sizeof( t_types ) );
	if ( convert[ type ]( toConvert, t ) == true )
		printTypes( t );
}

bool	ScalarConverter::convertChar( const std::string& str, t_types& t)
{
	t.c = str[ 1 ];
	t.i = static_cast< int >( t.c );
	t.f = static_cast< float >( t.c );
	t.d = static_cast< double >( t.c );
	if ( !isprint( t.c ) )
		t.c_flag = NON_DISPLAYABLE;
	return ( true );
}

bool	ScalarConverter::convertInt( const std::string& str, t_types& t )
{
	try
	{
		t.i = std::stoi( str );
	}
	catch ( std::exception& e )
	{
		std::cerr << "Invalid range: int -> overflow/underflow " << std::endl;
		return ( false );
	}
	t.c = static_cast< char >( t.i );
	t.f = static_cast< float >( t.i );
	t.d = static_cast< double >( t.i );
	if ( !isascii( t.i ) )
		t.c_flag = IMPOSSIBLE_CONV;
	else if ( !isprint( t.c ) )
		t.c_flag = NON_DISPLAYABLE;
	return ( true );
}

bool	ScalarConverter::convertFloat( const std::string& str, t_types& t )
{
	try
	{
		t.f = std::stof( str );
	}
	catch ( std::exception& e )
	{
		std::cerr << "Invalid range: float -> overflow/underflow " << std::endl;
		return ( false );
	}
	if ( t.f > std::numeric_limits< int >::max() || t.f > std::numeric_limits< int >::min() )
		t.i_flag = IMPOSSIBLE_CONV;
	else
		t.i = static_cast< int >( t.f );
	if ( t.f > std::numeric_limits< char >::max() || t.f < 0 )
		t.c_flag = IMPOSSIBLE_CONV;
	else if ( !isprint( t.i ) )
		t.c_flag = NON_DISPLAYABLE;
	else 
		t.c = static_cast< char >( t.f );
	t.d = static_cast< double >( t.f );
	return ( true );
}

bool	ScalarConverter::convertDouble( const std::string& str, t_types& t )
{
	try
	{
		t.d = std::stod( str );
	}
	catch ( std::exception& e )
	{
		std::cerr << "Invalid range: double -> overflow/underflow " << std::endl;
		return ( false );
	}
	t.c = static_cast< char >( t.f );
	if ( t.f > std::numeric_limits< int >::max() || t.f > std::numeric_limits< int >::min() )
		t.i_flag = IMPOSSIBLE_CONV;
	else
		t.i = static_cast< int >( t.f );
	t.d = static_cast< double >( t.f );
	if ( !isascii( t.i ) )
		t.c_flag = IMPOSSIBLE_CONV;
	else if ( !isprint( t.c ) )
		t.c_flag = NON_DISPLAYABLE;
	return ( true );
}

void	ScalarConverter::printTypes( const t_types& t )
{
	void	( *print[ NUM_TYPES - 1 ] )( const t_types& ) = { \
										&ScalarConverter::printChar, \
										&ScalarConverter::printInt, \
										&ScalarConverter::printFloat, \
										&ScalarConverter::printDouble };

	std::cout.precision( 1 );
	std::cout << std::fixed;
	for ( int i = 0; i < NUM_TYPES - 1; i++ )
		print[ i ]( t );
}

void	ScalarConverter::printChar( const t_types& t )
{
	std::cout << "char: ";
	switch ( t.c_flag )
	{
		case NON_DISPLAYABLE:
			std::cout << "Non displayable";			
			break;
		case IMPOSSIBLE_CONV:
			std::cout << "impossible";	
			break;
		default:
			std::cout << t.c;
			break;
	}
	std::cout << std::endl;
}

void	ScalarConverter::printInt( const std::string& str )
{
	std::cout << str << std::endl;
}

void	ScalarConverter::printFloat( const std::string& str )
{
	std::cout << str << std::endl;
}

void	ScalarConverter::printDouble( const std::string& str )
{
	std::cout << str << std::endl;
}
