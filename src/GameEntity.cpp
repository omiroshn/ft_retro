/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameEntity.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 01:15:29 by omiroshn          #+#    #+#             */
/*   Updated: 2018/04/08 01:15:30 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GameEntity.hpp"

GameEntity::GameEntity()
{
	srand(time(0));
	std::cout << "\033[8,60;220t";
	initscr();
	cbreak();
	clear();
	mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, nullptr);
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_GREEN, COLOR_BLACK);
	init_pair(5, COLOR_CYAN, COLOR_BLACK);
	init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
	erase();
	keypad(stdscr,TRUE);
	nodelay(stdscr, TRUE);
	curs_set(0);
	noecho();
	refresh();
	_life = 3;
	_score = 0;
	_count_my_bulet = 0;
	_max_bulets = 100;
	_count_enemies = 50;
	_cnt_stars = 50;
}
	
GameEntity::~GameEntity() 
{
	for (int i = 0; i < _count_enemies; ++i)
		delete enemies[i];
	delete enemies;
	for (int i = 0; i < _count_my_bulet; ++i)
		delete my_bulet[i];
	delete my_bulet;
	for (int i = 0; i < _cnt_stars; ++i)
		delete stars_small[i];
	delete stars_small;
}

GameEntity::GameEntity(GameEntity const & src)
{
	*this = src;
}

GameEntity		&GameEntity::operator=(GameEntity const & rhs)
{
	if (this != &rhs)
	{
		c = rhs.getC();
		_score = rhs.getScore();
		_life = rhs.getLife();
		my_bulet = rhs.getBulet();
		enemies = rhs.getEnemies();
		stars_small = rhs.getStars();
		_cnt_stars = rhs.getCntStars();
		_count_my_bulet = rhs.getCntMyBulet();
		_max_bulets = rhs.getMaxBulets();
		_count_enemies = rhs.getCntMyEnemies();
	}
	return (*this);
}

int				GameEntity::keyfunc(int key, Ship &ship) {
	clear();
	if (key == 'q')
		return (0);
	if (key == ' ')
	{
		if (_count_my_bulet < _max_bulets)
			this->add_bulet(ship.shot());
		else
			for (int i = 0; i < _count_my_bulet; ++i)
			{
				if (!my_bulet[i]->getLive())
				{
					my_bulet[i]->setX(ship.getX());
					my_bulet[i]->setY(ship.getY());
					my_bulet[i]->live();
					break;
				}
			}
			std::cout << '\a';
	}
	if (key == KEY_UP) {
		ship.move(0, -1);
	}
	if (key == KEY_DOWN) {
		ship.move(0, 1);
	}
	if (key == KEY_LEFT) {
		ship.move(-1, 0);
	}
	if (key == KEY_RIGHT) {
		ship.move(1, 0);
	}
	return (1);
}

void	GameEntity::drawStars(const int &speed_cnt) {
	for (int i = 0; i < _cnt_stars; ++i)
	{
		if (!stars_small[i]->getLive() && std::clock() % 4)
			stars_small[i]->live();
		std::string  starPic = stars_small[i]->getPicture();
		if (stars_small[i]->getLive())
		{
			move(stars_small[i]->getY(), stars_small[i]->getX());
			if (stars_small[i]->getX() < COLS) {
				addstr(starPic.c_str());
			}
		}
		if ((speed_cnt * 2) % 500 == 0)
		{
			stars_small[i]->setX(stars_small[i]->getX() - 1);
			if (stars_small[i]->getX() == -1) {
				stars_small[i]->destroy();
			stars_small[i]->setX(COLS + rand() % COLS);
			}
		}
	}
}

void	GameEntity::drawEnemies(const int &speed_cnt, const int &speed) {
	for (int i = 0; i < _count_enemies; ++i)
	{
		if (!enemies[i]->getLive() && std::clock() % 4)
			enemies[i]->live();
		std::string  enemyPic = enemies[i]->getPicture();
		if (enemies[i]->getLive())
		{
			move(enemies[i]->getY(), enemies[i]->getX());
			if (enemies[i]->getX() < COLS) {
				attron(COLOR_PAIR(2));
				addstr(enemyPic.c_str());
				attroff(COLOR_PAIR(2));
			}
		}
		if (speed_cnt == speed)
		{
			enemies[i]->setX(enemies[i]->getX() - 1);
			if (std::clock() % 2)
				enemies[i]->move(0, (std::clock() % 3 - 1));
			if (enemies[i]->getX() == -1) {
				enemies[i]->destroy();
			enemies[i]->setX(COLS + rand() % COLS);
			}
		}
	}
}

void	GameEntity::drawHood()
{
	move(1, 1);
	attron(COLOR_PAIR(3));
	printw("YOUR SCORE: %d   |   LIVES: %d", _score, _life);
	attroff(COLOR_PAIR(3));
	refresh();
}

void	GameEntity::drawGameOver()
{
	move(LINES/4, COLS/2 - 9);
	attron(COLOR_PAIR(2));
	printw("GAME OVER\n");
	move(LINES/4 + 1, COLS/2 - 14);
	printw("YOUR SCORE: %d\n", _score);
	attroff(COLOR_PAIR(2));
	refresh();
	usleep(10000000);
}

int		GameEntity::doGame()
{
	int		speed_cnt = 0;
	int		speed = 500;

	std::string ship_pict = "<>";
	std::string enemy_pict = "{";
	std::string st_sm_pict = ".";

	Ship ship(3, LINES / 2, ship_pict, 2, 1, "my");
	enemies = new EnemyShip*[_count_enemies];
	my_bulet = new Bulet*[_max_bulets];
	stars_small = new AObject*[_cnt_stars];

	for (int i = 0; i < _count_enemies; ++i)
	{
		enemies[i] = new EnemyShip(COLS + rand() % COLS,
			std::clock() % LINES, enemy_pict, 1, 1, "enemy");
		enemies[i]->destroy();
	}

	for (int i = 0; i < _cnt_stars; ++i)
	{
		stars_small[i] = new AObject(rand() % COLS,
			rand() % LINES, "sm_star", st_sm_pict, 1, 1);
		stars_small[i]->destroy();
	}

	while (1)
	{
		drawHood();
		if (!keyfunc(c, ship))
			break ;
		drawStars(speed_cnt);
		drawEnemies(speed_cnt, speed);
		checkHit();
		showBulet(speed_cnt);
		std::string pic = ship.getPicture();
		move(ship.getY(), ship.getX());
		attron(COLOR_PAIR(6));
		addstr(pic.c_str());
		attroff(COLOR_PAIR(6));
		checkHit();
		speed_cnt = (speed_cnt == speed) ? 0 : speed_cnt;
		checkLife(ship);
		speed_cnt++;
		if (getLife() == 0) {
			drawGameOver();
			break ;
		}
		this->c = getch();
	}
	system("reset");
	return (0);
}

void		GameEntity::add_bulet(Bulet * bulet)
{
	if (_count_my_bulet < _max_bulets)
	{
		my_bulet[_count_my_bulet] = bulet;
		_count_my_bulet++;
	}
}

void		GameEntity::checkLife(Ship & ship)
{
	for (int i = 0; i < _count_enemies; ++i)
	{
		int my_x = ship.getX();;
		int my_y = ship.getY();;

		if (enemies[i]->getX() == my_x && enemies[i]->getY() == my_y) {
			setLife(getLife() - 1);
			ship.setX(3);
			ship.setY(LINES / 2);
		}
	}
}

void		GameEntity::checkHit()
{
	for (int i = 0; i < _count_enemies; ++i)
	{
		int en_x = enemies[i]->getX();
		int en_y = enemies[i]->getY();
		for (int j = 0; j < _count_my_bulet; ++j)
		{
			if (my_bulet[j]->getX() == en_x 
				&& my_bulet[j]->getY() == en_y && my_bulet[j]->getLive())
			{
				enemies[i]->destroy();
				enemies[i]->setX(COLS + rand() % COLS);
				my_bulet[j]->destroy();
				setScore(getScore() + 1);
			}
		}
	}
}

void		GameEntity::showBulet(int speed_cnt)
{
	for (int i = 0; i < _count_my_bulet; ++i)
	{
		std::string  bulet = my_bulet[i]->getPicture();
		if (my_bulet[i]->getLive() && my_bulet[i]->getX() < COLS)
		{
			move(my_bulet[i]->getY(), my_bulet[i]->getX());
			attron(COLOR_PAIR(4));
			addstr(bulet.c_str());
			attroff(COLOR_PAIR(4));
		}
		if (speed_cnt % 100 == 0)
		{
			my_bulet[i]->setX(my_bulet[i]->getX() + 1);
			if (my_bulet[i]->getX() == COLS - 1)
				my_bulet[i]->destroy();
		}
	}
}

int 		GameEntity::getScore() const { return (_score); }

int 		GameEntity::getLife() const { return (_life); }

void 		GameEntity::setLife(int life) { this->_life = life; }

void 		GameEntity::setScore(int score) { this->_score = score; }

int         GameEntity::getC() const { return (this->c); }

Bulet		**GameEntity::getBulet() const { return (my_bulet); }

EnemyShip	**GameEntity::getEnemies() const { return (enemies); }

AObject		**GameEntity::getStars() const { return (stars_small); }

int			GameEntity::getCntStars() const { return (_cnt_stars); }

int			GameEntity::getCntMyBulet() const { return (_count_my_bulet); }

int			GameEntity::getMaxBulets() const { return (_max_bulets); }

int			GameEntity::getCntMyEnemies() const { return (_count_enemies); }
