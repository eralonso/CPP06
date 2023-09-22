/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 18:32:20 by eralonso          #+#    #+#             */
/*   Updated: 2023/09/22 19:34:24 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main( int, char **argv )
{
	ScalarConverter	conv;

	if ( argv[ 1 ] != NULL )
		conv.convert( argv[ 1 ] );
	return ( 0 );
}