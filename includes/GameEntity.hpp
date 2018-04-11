/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameEntity.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 01:15:36 by omiroshn          #+#    #+#             */
/*   Updated: 2018/04/08 01:15:36 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAMEENTITY_HPP
#define GAMEENTITY_HPP

#include "Ship.hpp"
#include "EnemyShip.hpp"
#include "AObject.hpp"
#include <fstream>
#include <cstdlib>
#include <unistd.h>

class GameEntity
{
private:
	int 		c;
	int			_score;
	int			_life;
	Bulet		**my_bulet;
	EnemyShip	**enemies;
	AObject		**stars_small;
	int			_cnt_stars;
	int 		_count_my_bulet;
	int 		_count_enemies;
	int			_max_bulets;
	int			keyfunc(int key, Ship &ship);
	void        checkLife(Ship & ship);
	void		checkHit();
	void		showBulet(int speed_cnt);
	void		drawEnemies(const int &speed_cnt, const int &speed);
	void		drawStars(const int &speed_cnt);
	
public:
	GameEntity();
	GameEntity(GameEntity const & src);
	~GameEntity();

	GameEntity &	operator=(GameEntity const & rhs);
	int				getC() const;
	Bulet			**getBulet() const;
	EnemyShip		**getEnemies() const;
	AObject			**getStars() const;
	int				getCntStars() const;
	int				getCntMyBulet() const;
	int				getMaxBulets() const;
	int				getCntMyEnemies() const;
	int				doGame();
	void			add_bulet(Bulet * bulet);
	void			drawHood();
	void			drawGameOver();
	int				getLife() const;
	int				getScore() const;
	void 			setLife(int life);
	void 			setScore(int score);
};

#endif
