/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christian <christian@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:54:41 by candrese          #+#    #+#             */
/*   Updated: 2025/02/12 11:57:38 by christian        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal {
public:
	Dog();
	explicit Dog(const std::string& type);
	Dog(const Dog& other);
	Dog& operator=(const Dog& other);
	~Dog() override;

	void makeSound() const override;
};

#endif