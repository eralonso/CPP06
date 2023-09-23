/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 18:32:20 by eralonso          #+#    #+#             */
/*   Updated: 2023/09/23 18:58:46 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int	main( void )
{
	Data		*ptr;
	Data		*newPtr;
	uintptr_t	raw;
	int			number;

	number = 49;
	ptr = new Data;
	ptr->c = number;
	ptr->i = number;
	ptr->ptr = &number;
	std::cout << "[ BEFORE ] Data *ptr stats -> ptr: " << ptr \
				<< " && ptr->c: " << ptr->c \
				<< " && ptr->i: " << ptr->i \
				<< " && ptr->ptr: " << ptr->ptr \
				<< " && *( ptr->ptr ): " << *( ptr->ptr ) \
				<< std::endl;
	raw = Serializer::serialize( ptr );
	newPtr = Serializer::deserialize( raw );
	std::cout << "[ AFTER  ] Data *newPtr stats -> ptr: " << newPtr \
				<< " && newPtr->c: " << newPtr->c \
				<< " && newPtr->i: " << newPtr->i \
				<< " && newPtr->ptr: " << newPtr->ptr \
				<< " && *( newPtr->ptr ): " << *( newPtr->ptr ) \
				<< std::endl;
	std::cout << "uintptr_t raw: " << raw \
				<< " && hexadecimal raw: 0x" << std::hex << raw \
				<< std::endl;
	delete ptr;
	return ( 0 );
}
/*
	Note: If do any type of operation with the result of serialize function \
		before call deserialize function the info store in raw (uintptr_t) may change.
*/