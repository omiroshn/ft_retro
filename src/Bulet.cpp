/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bulet.cpp    	                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshyshki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 13:55:45 by kshyshki          #+#    #+#             */
/*   Updated: 2018/04/07 13:55:47 by kshyshki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bulet.hpp"

std::string bulet = "--" ;

Bulet::Bulet()
{

}

Bulet::Bulet(int x, int y) : AObject(x, y, "Bulet", bulet, 1, 1)
{

}

Bulet::Bulet(Bulet const & src)
{
	*this = src;
}

Bulet::~Bulet()
{

}

Bulet const &	Bulet::operator=(Bulet const & src)
{
    AObject::operator=(src);

    return *this;
}

bool			Bulet::move(int dx, int dy)
{
    if (AObject::move(dx, dy))
    {
	   _live = false;
	   return true;
    }
    return false;
}
