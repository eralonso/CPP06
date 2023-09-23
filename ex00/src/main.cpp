/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 18:32:20 by eralonso          #+#    #+#             */
/*   Updated: 2023/09/23 17:49:46 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <sstream>

#define C_DEFAULT       "\033[0m"
#define C_RED           "\033[1;91m"
#define C_GREEN         "\033[1;92m"
#define C_YELLOW        "\033[1;93m"
#define C_BLUE          "\033[1;94m"
#define C_PINK          "\033[1;95m"
#define C_CYAN          "\033[1;96m"
#define C_WHITE         "\033[1;97m"
#define C_PURPLE        "\033[1;38;2;150;25;250m"

void	test( unsigned int& testNumber, std::string testName, std::string testString, std::string expectedColor )
{
	ScalarConverter	conv;

	std::cout << C_BLUE << "Test " << testNumber++ << ": ";
	if ( expectedColor.compare( C_RED ) == 0 )
		std::cout << expectedColor << "[ ❌ ] " << C_WHITE;
	else
		std::cout << expectedColor << "[ ✅ ] " << C_WHITE;
	std::cout << C_PINK << testName << " [ \"" << testString << "\" ]" << C_WHITE << std::endl;
	conv.convert( testString );
	std::cout << C_BLUE << "End test\n" << C_WHITE << std::endl;
}

void	testsInfinity( void )
{
	unsigned int	testNumber;

	testNumber = 0;
	std::cout << C_PURPLE << "\n\t\t\t[ DOUBLE ]\n\n" << C_WHITE << std::endl;
	test( testNumber, "Double -> Invalid syntax", "inf", C_RED );
	test( testNumber, "Double -> Valid syntax", "+inf", C_GREEN );
	test( testNumber, "Double -> Valid syntax", "-inf", C_GREEN );
	test( testNumber, "Double -> Invalid syntax", " -inf", C_RED );
	test( testNumber, "Double -> Invalid syntax", "+inf ", C_RED );
	test( testNumber, "Double -> Invalid syntax", "0-inf", C_RED );
	test( testNumber, "Double -> Invalid syntax", "+inf0", C_RED );
	std::cout << C_PURPLE << "\n\t\t\t[ FLOAT ]\n\n" << C_WHITE << std::endl;
	test( testNumber, "Float -> Invalid syntax", "inff", C_RED );
	test( testNumber, "Float -> Valid syntax", "+inff", C_GREEN );
	test( testNumber, "Float -> Valid syntax", "-inff", C_GREEN );
	test( testNumber, "Float -> Invalid syntax", "-inff ", C_RED );
	test( testNumber, "Float -> Invalid syntax", " +inff", C_RED );
	test( testNumber, "Float -> Invalid syntax", "0-inff", C_RED );
	test( testNumber, "Float -> Invalid syntax", "+inff0", C_RED );
}

void	testsNotANumber( void )
{
	unsigned int	testNumber;

	testNumber = 0;
	std::cout << C_PURPLE << "\n\t\t\t[ DOUBLE ]\n\n" << C_WHITE << std::endl;
	test( testNumber, "Double -> Valid syntax", "nan", C_GREEN );
	test( testNumber, "Double -> Invalid syntax", "+nan", C_RED );
	test( testNumber, "Double -> Invalid syntax", "-nan", C_RED );
	test( testNumber, "Double -> Invalid syntax", " nan", C_RED );
	test( testNumber, "Double -> Invalid syntax", "nan ", C_RED );
	test( testNumber, "Double -> Invalid syntax", "0nan", C_RED );
	test( testNumber, "Double -> Invalid syntax", "nan0", C_RED );
	std::cout << C_PURPLE << "\n\t\t\t[ FLOAT ]\n\n" << C_WHITE << std::endl;
	test( testNumber, "Float -> Valid syntax", "nanf", C_GREEN );
	test( testNumber, "Float -> Invalid syntax", "+nanf", C_RED );
	test( testNumber, "Float -> Invalid syntax", "-nanf", C_RED );
	test( testNumber, "Float -> Invalid syntax", "nanf ", C_RED );
	test( testNumber, "Float -> Invalid syntax", " nanf", C_RED );
	test( testNumber, "Float -> Invalid syntax", "0nanf", C_RED );
	test( testNumber, "Float -> Invalid syntax", "nanf0", C_RED );
}

void	testsChar( void )
{
	unsigned int	testNumber;

	testNumber = 0;
	test( testNumber, "Char -> Valid syntax", "'a'", C_GREEN );
	test( testNumber, "Char -> Valid syntax", "'0'", C_GREEN );
	test( testNumber, "Char -> Valid syntax", "'-'", C_GREEN );
	test( testNumber, "Char -> Invalid syntax", "a", C_RED );
	test( testNumber, "Char -> Invalid syntax", "ab", C_RED );
	test( testNumber, "Char -> Invalid syntax", "'ab'", C_RED );
	test( testNumber, "Char -> Invalid syntax", "'11'", C_RED );
	test( testNumber, "Char -> Invalid syntax", "\"a\"", C_RED );
}

void	testsInt( void )
{
	unsigned int		testNumber;
	std::stringstream	num;

	testNumber = 0;
	std::cout << C_PURPLE << "\n\t\t\t[ SYNTAX TESTS ]\n\n" << C_WHITE << std::endl;
	test( testNumber, "Int -> Valid syntax", "1", C_GREEN );
	test( testNumber, "Int -> Valid syntax", "-1", C_GREEN );
	test( testNumber, "Int -> Valid syntax", "+1", C_GREEN );
	test( testNumber, "Int -> Valid syntax", "+00042", C_GREEN );
	test( testNumber, "Int -> Invalid syntax", "0+0001000", C_RED );
	test( testNumber, "Int -> Invalid syntax", "", C_RED );
	test( testNumber, "Int -> Invalid syntax", "-", C_RED );
	test( testNumber, "Int -> Invalid syntax", "+", C_RED );
	test( testNumber, "Int -> Invalid syntax", "-+", C_RED );
	test( testNumber, "Int -> Invalid syntax", "-+10", C_RED );
	test( testNumber, "Int -> Invalid syntax", "+-100", C_RED );
	test( testNumber, "Int -> Invalid syntax] ", " 10", C_RED );
	std::cout << C_PURPLE << "\n\t\t\t[ LIMITS TESTS ]\n\n" << C_WHITE << std::endl;
	num << rand();
	test( testNumber, "Int -> Random Integer", num.str(), C_GREEN );
	num.str("");
	num << std::numeric_limits< int >::max();
	test( testNumber, "Int -> Max Integer", num.str(), C_GREEN );
	num.str("");
	num << std::numeric_limits< int >::lowest();
	test( testNumber, "Int -> Min Integer", num.str(), C_GREEN );
	num.str("");
	num << static_cast< long >( std::numeric_limits< int >::max() ) * 2;
	test( testNumber, "Int -> Max Integer * 2", num.str(), C_RED );
	num.str("");
	num << static_cast< long >( std::numeric_limits< int >::lowest() ) * 2;
	test( testNumber, "Int -> Min Integer * 2", num.str(), C_RED );
}

void	testsFloat( void )
{
	unsigned int		testNumber;
	std::stringstream	num;

	testNumber = 0;
	std::cout << C_PURPLE << "\n\t\t\t[ SYNTAX TESTS ]\n\n" << C_WHITE << std::endl;
	test( testNumber, "Float -> Valid syntax", "1.f", C_GREEN );
	test( testNumber, "Float -> Valid syntax", "-1.f", C_GREEN );
	test( testNumber, "Float -> Valid syntax", "+1.0f", C_GREEN );
	test( testNumber, "Float -> Valid syntax", ".15f", C_GREEN );
	test( testNumber, "Float -> Valid syntax", "+00042.f", C_GREEN );
	test( testNumber, "Float -> Invalid syntax", "1f", C_RED );
	test( testNumber, "Float -> Invalid syntax", "1-.f", C_RED );
	test( testNumber, "Float -> Invalid syntax", "0+0001000f", C_RED );
	test( testNumber, "Float -> Invalid syntax", "", C_RED );
	test( testNumber, "Float -> Invalid syntax", "f", C_RED );
	test( testNumber, "Float -> Invalid syntax", ".f", C_RED );
	test( testNumber, "Float -> Invalid syntax", "..f", C_RED );
	test( testNumber, "Float -> Invalid syntax", ".", C_RED );
	test( testNumber, "Float -> Invalid syntax", "0.f0", C_RED );
	test( testNumber, "Float -> Invalid syntax", "-", C_RED );
	test( testNumber, "Float -> Invalid syntax", "+", C_RED );
	test( testNumber, "Float -> Invalid syntax", "-+", C_RED );
	test( testNumber, "Float -> Invalid syntax", "-+10f", C_RED );
	test( testNumber, "Float -> Invalid syntax", "+-100f", C_RED );
	test( testNumber, "Float -> Invalid syntax] ", " 10f", C_RED );
	std::cout << C_PURPLE << "\n\t\t\t[ LIMITS TESTS ]\n\n" << C_WHITE << std::endl;
	num.precision( 24 );
	num << std::fixed << static_cast< float >( rand() ) + static_cast< float >( rand() ) << "f";
	test( testNumber, "Float -> Random float", num.str(), C_GREEN );
	num.str("");
	num << std::numeric_limits< float >::max() << "f";
	test( testNumber, "Float -> Max Float", num.str(), C_GREEN );
	num.str("");
	num << std::numeric_limits< float >::lowest() << "f";
	test( testNumber, "Float -> Min Float", num.str(), C_GREEN );
	num.str("");
	num << static_cast< double >( std::numeric_limits< float >::max() ) * 2 << "f";
	test( testNumber, "Float -> Max Float * 2", num.str(), C_RED );
	num.str("");
	num << static_cast< double >( std::numeric_limits< float >::lowest() ) * 2 << "f";
	test( testNumber, "Float -> Min Float * 2", num.str(), C_RED );
}

void	testsDouble( void )
{
	unsigned int		testNumber;
	std::stringstream	num;

	testNumber = 0;
	std::cout << C_PURPLE << "\n\t\t\t[ SYNTAX TESTS ]\n\n" << C_WHITE << std::endl;
	test( testNumber, "Double -> Valid syntax", "1.", C_GREEN );
	test( testNumber, "Double -> Valid syntax", "-1.", C_GREEN );
	test( testNumber, "Double -> Valid syntax", "+1.", C_GREEN );
	test( testNumber, "Double -> Valid syntax", ".15", C_GREEN );
	test( testNumber, "Double -> Valid syntax", "+00042.", C_GREEN );
	test( testNumber, "Double -> Invalid syntax", "0+0001000.", C_RED );
	test( testNumber, "Double -> Invalid syntax", "", C_RED );
	test( testNumber, "Double -> Invalid syntax", ".", C_RED );
	test( testNumber, "Double -> Invalid syntax", "..", C_RED );
	test( testNumber, "Double -> Invalid syntax", "-", C_RED );
	test( testNumber, "Double -> Invalid syntax", "+", C_RED );
	test( testNumber, "Double -> Invalid syntax", "-+", C_RED );
	test( testNumber, "Double -> Invalid syntax", "-+10.", C_RED );
	test( testNumber, "Double -> Invalid syntax", "+-100.", C_RED );
	test( testNumber, "Double -> Invalid syntax", " 10.", C_RED );
	std::cout << C_PURPLE << "\n\t\t\t[ LIMITS TESTS ]\n\n" << C_WHITE << std::endl;
	num.precision( 10 );
	num << std::fixed << static_cast< double >( rand() ) + static_cast< double >( rand() );
	test( testNumber, "Double -> Random double", num.str(), C_GREEN );
	num.str("");
	num << std::numeric_limits< double >::max();
	test( testNumber, "Double -> Max Double", num.str(), C_GREEN );
	num.str("");
	num << std::numeric_limits< double >::lowest();
	test( testNumber, "Double -> Min Double", num.str(), C_GREEN );
	num.str("");
	num << std::numeric_limits< double >::max() + static_cast< long double >( std::numeric_limits< double >::max() / 4 );
	test( testNumber, "Double -> Max Double + ( Max Double / 4 )", num.str(), C_RED );
	num.str("");
	num << std::numeric_limits< double >::lowest() - static_cast< long double >( std::numeric_limits< double >::max() / 4 );
	test( testNumber, "Double -> Min Double - ( Max Double / 4 )", num.str(), C_RED );
}

bool    executionQuestion( std::string testsName )
{
        std::string     answer;

        std::cout << C_YELLOW << "Do you want to execute the \"" << testsName << "\" tests [ y / n ]: " << C_WHITE;
        std::getline( std::cin, answer );
        if ( answer.compare( "Y" ) == 0 || answer.compare( "y" ) == 0 )
        {
                std::cout << std::endl;
                return ( true );
        }
        return ( false );
}

void	testing( void )
{
	srand( time( NULL ) );

	if ( executionQuestion( "Infinity ( [ + / - ] inf | [ + / - ] inff )" ) == true )
		testsInfinity();
	std::cout << std::endl;

	if ( executionQuestion( "Not a number ( nan / nanf )" ) == true )
		testsNotANumber();
	std::cout << std::endl;

	if ( executionQuestion( "Char" ) == true )
		testsChar();
	std::cout << std::endl;

	if ( executionQuestion( "Int" ) == true )
		testsInt();
	std::cout << std::endl;

	if ( executionQuestion( "Float" ) == true )
		testsFloat();
	std::cout << std::endl;

	if ( executionQuestion( "Double" ) == true )
		testsDouble();
	std::cout << std::endl;
}

int	main( int ac, char **argv )
{
	ScalarConverter	conv;

	if ( ac > 1 )
	{
		for ( int i = 1; i < ac; i++ )
		{
			conv.convert( argv[ i ] );
			std::cout << std::endl;
		}
	}
	else
		testing();
	return ( 0 );
}