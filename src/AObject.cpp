/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AObject.cpp  	                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshyshki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 13:55:45 by kshyshki          #+#    #+#             */
/*   Updated: 2018/04/07 13:55:47 by kshyshki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AObject.hpp"

AObject::AObject()
{

}

AObject::AObject(int x, int y, std::string type, std::string picture, int wPicture, int hPicture)
{
	_x = x;
	_y = y;
	_type = type;
	_picture = picture;
	_wPicture = wPicture;
	_hPicture = hPicture;
	_live = true;
}

AObject::AObject(AObject const & src)
{
	*this = src;
}

AObject::~AObject()
{

}

AObject const & AObject::operator=(AObject const & rhs)
{
	if (this != &rhs)
	{
		_x = rhs.getX();
		_y = rhs.getY();
		_type = rhs.getType();
		_live = rhs.getLive();
		_picture = rhs.getPicture();
		_wPicture = rhs.getWPicture();
		_hPicture = rhs.getHPicture();
	}
	return (*this);
}

bool		AObject::move(int x, int y)
{
	bool    out = false;

	if (x)
	{
		if (((this->_x + this->_wPicture) + x) > COLS)
		{
			this->_x = COLS - this->_wPicture;
			out = true;
		}
		else if (this->_x + x < 0)
		{
			this->_x = 0;
			out = true;
		}
		else
			this->_x += x;
	}
	if (y)
	{
		if (((this->_y + _hPicture) + y) > LINES)
		{
			this->_y = LINES - _hPicture;
			out = true;
		}
		else if (this->_y + y < 0)
		{
			this->_y = 0;
			out = true;
		}
		else
			this->_y += y;
	}
	return (out);
}

int 		AObject::getX() const { return (_x); }

int 		AObject::getY() const { return (_y); }

void         AObject::setX(int x) { this->_x = x; }

void         AObject::setY(int y) { this->_y = y; }

std::string	AObject::getType() const { return (_type); }

bool		AObject::getLive() const { return (_live); }

void        AObject::live() { _live = true; }

void		AObject::destroy() { _live = false; }

std::string	AObject::getPicture() const { return (_picture); }

int 		AObject::getWPicture() const { return (_wPicture); }

int 		AObject::getHPicture() const { return (_hPicture); }
