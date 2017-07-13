/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CentralBureaucracy.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/XX/XX XX:XX:XX by tle-meur          #+#    #+#             */
/*   Updated: 2017/XX/XX XX:XX:XX by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CENTRALBUREAUCRACY_HPP
# define CENTRALBUREAUCRACY_HPP

#include "OfficeBlock.hpp"
#include "Bureaucrat.hpp"

class CentralBureaucracy
{
private :
	OfficeBlock _blocks[20];
	std::string	_queue;
	int			_nbWorkers;

	CentralBureaucracy( CentralBureaucracy const & other );
	CentralBureaucracy& operator=( CentralBureaucracy const & other );

public:

	CentralBureaucracy( void );
	virtual ~CentralBureaucracy( void );

	void	feed( Bureaucrat & man );
	void	queueUp( std::string const & target );
	void	doBureaucracy( void );

};

#endif // CENTRALBUREAUCRACY_HPP
