/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christian <christian@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:54:28 by candrese          #+#    #+#             */
/*   Updated: 2025/02/12 11:57:03 by christian        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostream>

class Animal {
protected:
	std::string type;

public:
	Animal();
	explicit Animal(const std::string& type); // explicit to prevent implicit conversions
	Animal(const Animal &other);
	Animal& operator=(const Animal& other);
	virtual ~Animal();
	
	virtual void makeSound() const;
	std::string getType() const;
};

#endif
