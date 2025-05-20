/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:54:38 by candrese          #+#    #+#             */
/*   Updated: 2025/05/20 11:45:25 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << "Dog constructor called" << std::endl;
	brain = new Brain();
}

Dog::Dog(const std::string& type) : Animal(type) {
	std::cout << "Dog parameterized constructor called for " << type << std::endl;
	brain = new Brain();
}

Dog::Dog(const Dog& other) : Animal(other) {
	std::cout << "Dog copy constructor called" << std::endl;
	brain = new Brain(*other.brain); // Deep copy
}

// shallow copyconstructor - just copying the pointer
// Dog::Dog(const Dog& other) : Animal(other) {
// 	this->brain = other.brain;  // Both Dogs now point to the same Brain
// }


Dog& Dog::operator=(const Dog& other) {
	std::cout << "Dog assignment operator called" << std::endl;
	if (this != &other) {
		Animal::operator=(other);
		delete brain;
		brain = new Brain(*other.brain); // Deep copy
	}
	return *this;
}

// shallow copy assignment operator
// This is dangerous because:
// 1. When this Dog is destroyed, it will delete the Brain
// 2. When the other Dog is destroyed, it will try to delete the same Brain again
// 3. This will cause a double free error/crash
// Dog& Dog::operator=(const Dog& other) {
//      std::cout << "Dog assignment operator called (SHALLOW VERSION)" << std::endl;
//      if (this != &other) {
//      Animal::operator=(other);
//      delete brain;
//      brain = other.brain;
//  }
//  return *this;
// }

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
