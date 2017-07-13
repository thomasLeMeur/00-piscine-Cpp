/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/13 12:28:20 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:
	ScavTrap( void );
public:

	ScavTrap( std::string const name );
	ScavTrap( ScavTrap const & other );
	~ScavTrap( void );

	ScavTrap& operator=( ScavTrap const & other );

	unsigned int	challengeNewcomer( std::string const & target );

};

#endif // SCAVTRAP_HPP
