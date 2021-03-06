// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/06 11:47:28 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/06 12:05:13 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <Contact.class.hpp>
#include <iostream>
#include <string>
#include <sstream>

static void	add_requested(Contact contacts[8])
{
	if (Contact::getNbIUsed() >= 8)
		std::cout << "My Phone Book is full." << std::endl;
	else
		contacts[Contact::getNbIUsed()].initInstance();
	return ;
}

static int	request_index(void)
{
	std::string			buf;
	std::istringstream	iss;
	int					in;

	do
	{
		std::cout << "Who should I look into: ";
		std::getline(std::cin, buf);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return (-1);
		}
		iss.clear();
		iss.str(buf);
	} while ((iss >> in).fail() || in < 0 || in >= Contact::getNbIUsed());
	return (in);
}

static void	search_requested(Contact contacts[8])
{
	int		index;

	if (Contact::getNbIUsed() == 0)
	{
		std::cout << "My Phone Book is empty." << std::endl;
		return ;
	}
	std::cout << "*__________ __________ __________ __________*" << std::endl;
	for (int i = 0; i < Contact::getNbIUsed(); i++)
		contacts[i].selfDecribe_Row();
	std::cout << "*__________ __________ __________ __________*" << std::endl;
	index = request_index();
	if (index >= 0)
		contacts[index].selfDecribe_Full();
	return ;
}
int			main(void)
{
	std::string		buf;
	Contact			contacts[8];

	std::cout << "My Awesome Phone Book:" << std::endl;
	while (1)
	{
		std::cout << "> ";
		std::getline(std::cin, buf);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			break ;
		}
		if (buf == "ADD")
			add_requested(contacts);
		else if (buf == "SEARCH")
			search_requested(contacts);
		else if (buf == "EXIT")
			break ;
		else
			std::cout << "Input discarded." << std::endl;
	}
	std::cout << "Adios..." << std::endl;
	return (0);
}
