/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnemyShip.cpp    	                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshyshki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 13:55:45 by kshyshki          #+#    #+#             */
/*   Updated: 2018/04/07 13:55:47 by kshyshki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "EnemyShip.hpp"

EnemyShip::EnemyShip()
{

}

EnemyShip::EnemyShip(int x, int y, std::string picture, int wPicture, int hPicture, std::string name)
	   : Ship(x, y, picture, wPicture, hPicture, name)
{
    _name = name;
}

EnemyShip::EnemyShip(Ship const & src) : Ship(src)
{

}

EnemyShip::~EnemyShip()
{

}

EnemyShip const & EnemyShip::operator=(EnemyShip const & rhs)
{
    AObject::operator=(rhs);
    _name = rhs.getName();
    return *this;
}

bool			EnemyShip::move(int dx, int dy)
{
    if (AObject::move(dx, dy))
    {
	   _live = false;
	   return true;
    }
    return false;
}
