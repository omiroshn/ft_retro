/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ship.cpp    	                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshyshki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 13:55:45 by kshyshki          #+#    #+#             */
/*   Updated: 2018/04/07 13:55:47 by kshyshki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ship.hpp"


Ship::Ship()
{

}

Ship::Ship(int x, int y, std::string picture, int wPicture, int hPicture, std::string name)
    : AObject(x, y, "Ship", picture, wPicture, hPicture)
{
	_name = name;
}

Ship::Ship(Ship const & src) : AObject(src)
{

}

Ship::~Ship()
{

}

Ship const & Ship::operator=(Ship const & rhs)
{
    AObject::operator=(rhs);
    _name = rhs.getName();
    return *this;
}

Bulet*		Ship::shot() const
{
    int x;
    int y;

    x = _x + 1;
    y = _y;

    Bulet *	bullet = new Bulet(x, y);
    bullet->live();
    return bullet;
}

std::string	Ship::getName() const
{
    return _name;
}

