/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 18:32:20 by eralonso          #+#    #+#             */
/*   Updated: 2023/09/23 13:22:30 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

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
	std::cout << C_PINK << testName << C_WHITE << std::endl;
	conv.convert( testString );
	std::cout << C_BLUE << "End test\n" << C_WHITE << std::endl;
}

void	testsInfinity( void )
{
	unsigned int	testNumber;

	testNumber = 0;
	std::cout << C_PURPLE << "\n\t\t\t[ DOUBLE ]\n\n" << C_WHITE << std::endl;
	test( testNumber, "Double -> Invalid syntax [ \"inf\" ] ", "inf", C_RED );
	test( testNumber, "Double -> Valid syntax [ \"+inf\" ] ", "+inf", C_GREEN );
	test( testNumber, "Double -> Valid syntax [ \"-inf\" ] ", "-inf", C_GREEN );
	test( testNumber, "Double -> Invalid syntax [ \" -inf\" ] ", " -inf", C_RED );
	test( testNumber, "Double -> Invalid syntax [ \"+inf \" ] ", "+inf ", C_RED );
	test( testNumber, "Double -> Invalid syntax [ \"0-inf\" ] ", "0-inf", C_RED );
	test( testNumber, "Double -> Invalid syntax [ \"+inf0\" ] ", "+inf0", C_RED );
	std::cout << C_PURPLE << "\n\t\t\t[ FLOAT ]\n\n" << C_WHITE << std::endl;
	test( testNumber, "Float -> Invalid syntax [ \"inff\" ] ", "inff", C_RED );
	test( testNumber, "Float -> Valid syntax [ \"+inff\" ] ", "+inff", C_GREEN );
	test( testNumber, "Float -> Valid syntax [ \"-inff\" ] ", "-inff", C_GREEN );
	test( testNumber, "Float -> Invalid syntax [ \"-inff \" ] ", "-inff ", C_RED );
	test( testNumber, "Float -> Invalid syntax [ \" +inff\" ] ", " +inff", C_RED );
	test( testNumber, "Float -> Invalid syntax [ \"0-inff\" ] ", "0-inff", C_RED );
	test( testNumber, "Float -> Invalid syntax [ \"+inff0\" ] ", "+inff0", C_RED );
}

void	testsNotANumber( void )
{
	unsigned int	testNumber;

	testNumber = 0;
	std::cout << C_PURPLE << "\n\t\t\t[ DOUBLE ]\n\n" << C_WHITE << std::endl;
	test( testNumber, "Double -> Valid syntax [ \"nan\" ] ", "nan", C_GREEN );
	test( testNumber, "Double -> Invalid syntax [ \"+nan\" ] ", "+nan", C_RED );
	test( testNumber, "Double -> Invalid syntax [ \"-nan\" ] ", "-nan", C_RED );
	test( testNumber, "Double -> Invalid syntax [ \" nan\" ] ", " nan", C_RED );
	test( testNumber, "Double -> Invalid syntax [ \"nan \" ] ", "nan ", C_RED );
	test( testNumber, "Double -> Invalid syntax [ \"0nan\" ] ", "0nan", C_RED );
	test( testNumber, "Double -> Invalid syntax [ \"nan0\" ] ", "nan0", C_RED );
	std::cout << C_PURPLE << "\n\t\t\t[ FLOAT ]\n\n" << C_WHITE << std::endl;
	test( testNumber, "Float -> Valid syntax [ \"nanf\" ] ", "nanf", C_GREEN );
	test( testNumber, "Float -> Invalid syntax [ \"+nanf\" ] ", "+nanf", C_RED );
	test( testNumber, "Float -> Invalid syntax [ \"-nanf\" ] ", "-nanf", C_RED );
	test( testNumber, "Float -> Invalid syntax [ \"nanf \" ] ", "nanf ", C_RED );
	test( testNumber, "Float -> Invalid syntax [ \" nanf\" ] ", " nanf", C_RED );
	test( testNumber, "Float -> Invalid syntax [ \"0nanf\" ] ", "0nanf", C_RED );
	test( testNumber, "Float -> Invalid syntax [ \"nanf0\" ] ", "nanf0", C_RED );
}

void	testsChar( void )
{
	unsigned int	testNumber;

	testNumber = 0;
	test( testNumber, "Char -> Valid syntax [ \"'a'\" ] ", "nan", C_GREEN );
	// test( testNumber, "Char -> Not a number [ \"+nan\" ] ", "+nan", C_RED );
	// test( testNumber, "Char -> Not a number [ \"-nan\" ] ", "-nan", C_RED );
	// test( testNumber, "Char -> Not a number [ \" nan\" ] ", " nan", C_RED );
	// test( testNumber, "Char -> Not a number [ \"nan \" ] ", "nan ", C_RED );
	// test( testNumber, "Char -> Not a number [ \"0nan\" ] ", "0nan", C_RED );
	// test( testNumber, "Char -> Not a number [ \"nan0\" ] ", "nan0", C_RED );
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
	if ( executionQuestion( "Infinity ( [ + / - ] inf | [ + / - ] inff )" ) == true )
		testsInfinity();
	std::cout << std::endl;

	if ( executionQuestion( "Not a number ( nan / nanf )" ) == true )
		testsNotANumber();
	std::cout << std::endl;

	if ( executionQuestion( "Char" ) == true )
		testsChar();
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