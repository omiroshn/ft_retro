/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AObject.hpp  	                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshyshki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 13:55:45 by kshyshki          #+#    #+#             */
/*   Updated: 2018/04/07 13:55:47 by kshyshki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AOBJECT_HPP
#define AOBJECT_HPP

# include <iostream>
# include <ncurses.h>

class AObject
{
protected:
	int				_x;
	int				_y;
	bool			_live;
	std::string		_type;
	std::string		_picture;
	int				_wPicture;
	int				_hPicture;

public:
	AObject();
	AObject(int x, int y, std::string type, std::string picture, int wPicture, int hPicture);
	AObject(AObject const &);
	virtual ~AObject();

	AObject const & operator=(AObject const &);
	
	virtual bool	 move(int dx, int dy);
	int 		 getX() const;
	int 		 getY() const;
	void         setX(int x);
	void         setY(int y);

	std::string  getPicture() const;
	int          getWPicture() const;
	int          getHPicture() const;
	std::string  getType() const;
	bool         getLive() const;
	void         destroy();
	void         live();
};

#endif
