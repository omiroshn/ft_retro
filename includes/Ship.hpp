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

#ifndef SHIP_HPP
#define SHIP_HPP

# include "AObject.hpp"
# include "Bulet.hpp"

class Ship : public AObject
{
protected:
	std::string	_name;

public:
	Ship();
	Ship(int x, int y, std::string picture, int wPicture, int hPicture, std::string name);
	Ship(Ship const & src);
	~Ship();

	Ship const &	operator=(Ship const & src);

	Bulet*			shot() const;
	std::string		getName() const;
};

#endif
