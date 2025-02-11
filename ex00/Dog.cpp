/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:54:38 by candrese          #+#    #+#             */
/*   Updated: 2025/02/11 19:14:29 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << "Dog constructor" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
	std::cout << "Cat copy constructor" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
	if (this != &other) {
		Animal::operator=(other);
		std::cout << "Dog assignment operator" << std::endl;
	}
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog destructor" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "baarrrk" << std::endl;
}
