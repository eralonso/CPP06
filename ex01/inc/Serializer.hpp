/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:00:42 by eralonso          #+#    #+#             */
/*   Updated: 2023/09/23 18:55:49 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdint>

typedef struct	s_Data
{
	char	c;
	int		i;
	int		*ptr;
}				Data;

class Serializer
{
	public:
		Serializer( void );
		Serializer( const Serializer& serial );
		~Serializer( void );
		Serializer&	operator=( const Serializer& serial );
		static uintptr_t	serialize( Data* ptr );
		static Data			*deserialize( uintptr_t raw );
};
