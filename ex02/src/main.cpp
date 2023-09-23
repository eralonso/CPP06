/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 18:32:20 by eralonso          #+#    #+#             */
/*   Updated: 2023/09/23 19:13:25 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>

Base	*generate( void )
{
	Base	*res;

	res = NULL;
	srand( time(NULL) );
	switch ( rand() % 3 )
	{
		case 0:
			res = new A();
			break ;
		case 1:
			res = new B();
			break ;
		case 2:
			res = new C();
			break ;
		default:
			break ;
	}
	return ( res );
}

void	identify( Base *p )
{
	if ( dynamic_cast< A *>( p ) != NULL )
		std::cout << "Indentified by pointer, is: A" << std::endl;
	else if ( dynamic_cast< B *>( p ) != NULL )
		std::cout << "Indentified by pointer, is: B" << std::endl;
	else if ( dynamic_cast< C *>( p ) != NULL )
		std::cout << "Indentified by pointer, is: C" << std::endl;
}

void	identify( Base& p )
{
	try
	{
		A& a = dynamic_cast< A& >( p );
		( void )a;
		std::cout << "Indentified by reference, is: A" << std::endl;
		return ;
	}
	catch ( std::exception& e ) {}
	try
	{
		B& b = dynamic_cast< B& >( p );
		( void )b;
		std::cout << "Indentified by reference, is: B" << std::endl;
		return ;
	}
	catch ( std::exception& e ) {}
	try
	{
		C& c = dynamic_cast< C& >( p );
		( void )c;
		std::cout << "Indentified by reference, is: C" << std::endl;
		return ;
	}
	catch ( std::exception& e ) {}
}

int	main( void )
{
	Base	*base;

	base = generate();
	identify( base );
	identify( *base );
	return ( 0 );
}