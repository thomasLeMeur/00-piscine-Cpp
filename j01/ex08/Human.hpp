/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 14:53:50 by tle-meur          #+#    #+#             */
/*   Updated: 2017/01/10 14:55:51 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_HPP
# define HUMAN_HPP

class Human
{

private:
	void meleeAttack( std::string const & target );
	void rangedAttack( std::string const & target );
	void intimidatingShout( std::string const & target );

public:
	void action( std::string const & action_name, std::string const & target );

};

#endif // HUMAN_HPP
