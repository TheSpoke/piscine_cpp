// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Squad.cpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/10 14:56:40 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/10 15:45:26 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

//#include <iostream>
#include "Squad.hpp"

// * STATICS **************************************************************** //
// * CONSTRUCTORS *********************************************************** //
Squad::Squad() :
	ISquad(),
	_count(0),
	_aUnit(NULL)
{
	std::cout << "[Squad]() Ctor called" << std::endl;
	return ;
}
Squad::Squad(Squad const &src) :
	ISquad(),
	_count(0),
	_aUnit(NULL)
{
	std::cout << "[Squad](Squad const&) Ctor called" << std::endl;
	*this = src;
	return ;
}

// * DESTRUCTORS ************************************************************ //
Squad::~Squad()
{
	std::cout << "[Squad]() Dtor called" << std::endl;
	this->deleteUnits();
	return ;
}

// * OPERATORS ************************************************************** //
Squad						&Squad::operator=(Squad const &rhs)
{
	std::cout << "[Squad] operator =" << std::endl;
	this->deleteUnits();
	for (int i = 0; i < rhs.getCount(); i++)		
		this->push(rhs.getUnit(i)->clone());
	return (*this);
}

// * GETTERS **************************************************************** //
int							Squad::getCount(void) const{return this->_count;}
ISpaceMarine				*Squad::getUnit(int id)
{
	ISpaceMarine	*cur = this->_aUnit;

	while (cur != NULL && id-- > 0)
		cur = cur->getNext();
	return (cur);
}
ISpaceMarine				*Squad::getUnit(int id) const
{
	ISpaceMarine	*cur = this->_aUnit;

	while (cur != NULL && id-- > 0)
		cur = cur->getNext();
	return (cur);
}

// * SETTERS **************************************************************** //
// * MEMBER FUNCTIONS / METHODS ********************************************* //
int							Squad::push(ISpaceMarine *ptr)
{
	if (ptr != NULL)
	{
		if (this->_aUnit == NULL)
			this->_aUnit = ptr;
		else
		{
			ISpaceMarine	*cur = this->_aUnit;

			while (cur->getNext() != NULL)
				cur = cur->getNext();
			cur->setNext(ptr);
		}
		this->_count++;
	}
	return (this->_count);
}
void						Squad::deleteUnits(void)
{
	ISpaceMarine		*cur;

	while ((cur = this->_aUnit) != NULL)
	{
		this->_aUnit = cur->getNext();
		delete cur;
	}
	this->_count = 0;
	return ;
}

// * NESTED_CLASSES ********************************************************* //
