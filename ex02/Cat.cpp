/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:54:32 by candrese          #+#    #+#             */
/*   Updated: 2025/02/12 17:35:17 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : AAnimal("Cat") {
	std::cout << "Cat constructor called" << std::endl;
	brain = new Brain();
}

Cat::Cat(const std::string& type) : AAnimal(type) {
	std::cout << "Cat parameterized constructor called for " << type << std::endl;
	brain = new Brain();
}

Cat::Cat(const Cat& other) : AAnimal(other) {
	std::cout << "Cat copy constructor called" << std::endl;
	brain = new Brain(*other.brain); // Deep copy
}

Cat& Cat::operator=(const Cat& other) {
	std::cout << "Cat assignment operator called" << std::endl;
	if (this != &other) {
		AAnimal::operator=(other);
		delete brain;
		brain = new Brain(*other.brain); // Deep copy
	}
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
	delete brain;
}

void Cat::makeSound() const {
	std::cout << "Meow!" << std::endl;
}

Brain* Cat::getBrain() const {
	return brain;
}
