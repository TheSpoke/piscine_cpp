// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Fixed.class.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/08 12:35:04 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/09 06:38:14 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

# include <iostream>

class Fixed
{
public:
	Fixed();
	~Fixed();
	Fixed(Fixed const & src);
	Fixed(int const raw);
	Fixed(float const raw);
	Fixed				&operator=(Fixed const & rhs);
	
	int					getRawBits(void) const;
	void				setRawBits(int const raw);
	float				toFloat(void) const;
	int					toInt(void) const;
private:
	int					_rawBits;
	static int const	_fb;
};

std::ostream			&operator<<(std::ostream & o, Fixed const & rhs);

#endif
