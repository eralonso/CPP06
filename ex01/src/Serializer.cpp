/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:07:43 by eralonso          #+#    #+#             */
/*   Updated: 2023/09/23 18:53:48 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer( void ) {}

Serializer::Serializer( const Serializer& serial )
{
	( void )serial;
}

Serializer::~Serializer( void ) {}

Serializer&	Serializer::operator=( const Serializer& serial )
{
	( void )serial;
	return ( *this );
}

uintptr_t	Serializer::serialize( Data *ptr )
{
	return ( reinterpret_cast< uintptr_t >( ptr ) );
}

Data	*Serializer::deserialize( uintptr_t raw )
{
	return ( reinterpret_cast< Data *>( raw ) );
}
