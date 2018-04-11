/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnemyShip.hpp    	                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshyshki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 13:55:45 by kshyshki          #+#    #+#             */
/*   Updated: 2018/04/07 13:55:47 by kshyshki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMYSHIP_HPP
# define ENEMYSHIP_HPP

# include "Ship.hpp"

class EnemyShip : public Ship
{
protected:
	std::string	_name;

public:
	EnemyShip();
	EnemyShip(int x, int y, std::string picture, int wPicture, int hPicture, std::string name);
	EnemyShip(Ship const & src);
	~EnemyShip();

	EnemyShip const &	operator=(EnemyShip const & src);

	bool				move(int dx, int dy);
};

#endif
