/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bulet.hpp    	                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshyshki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 13:55:45 by kshyshki          #+#    #+#             */
/*   Updated: 2018/04/07 13:55:47 by kshyshki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BULET_HPP
#define BULET_HPP

# include "AObject.hpp"

class Bulet : public AObject
{
public:
    Bulet();
    Bulet(int x, int y);
    Bulet(Bulet const &);
    ~Bulet();

    Bulet const &	operator=(Bulet const &);

    bool			move(int dx, int dy);
};

#endif
