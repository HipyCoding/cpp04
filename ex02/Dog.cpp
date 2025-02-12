/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:54:38 by candrese          #+#    #+#             */
/*   Updated: 2025/02/12 17:35:00 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : AAnimal("Dog") {
	std::cout << "Dog constructor called" << std::endl;
	brain = new Brain();
}

Dog::Dog(const std::string& type) : AAnimal(type) {
	std::cout << "Dog parameterized constructor called for " << type << std::endl;
	brain = new Brain();
}

Dog::Dog(const Dog& other) : AAnimal(other) {
	std::cout << "Dog copy constructor called" << std::endl;
	brain = new Brain(*other.brain); // Deep copy
}

Dog& Dog::operator=(const Dog& other) {
	std::cout << "Dog assignment operator called" << std::endl;
	if (this != &other) {
		AAnimal::operator=(other);
		delete brain;
		brain = new Brain(*other.brain); // Deep copy
	}
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
	delete brain;
}

void Dog::makeSound() const {
	std::cout << "Woof!" << std::endl;
}

Brain* Dog::getBrain() const {
	return brain;
}
