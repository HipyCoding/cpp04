/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:36:11 by candrese          #+#    #+#             */
/*   Updated: 2025/05/20 01:50:32 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : type("Generic Animal") {
	std::cout << "Animal constructor called" << std::endl;
}

AAnimal::AAnimal(const std::string& type) : type(type) {
	std::cout << "Animal parameterized constructor called for " << type << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) : type(other.type) {
	std::cout << "Animal copy constructor called" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other) {
	std::cout << "Animal assignment operator called" << std::endl;
	if (this != &other) {
		type = other.type;
	}
	return *this;
}

AAnimal::~AAnimal() {
	std::cout << "AAnimal destructor called" << std::endl;
}

std::string AAnimal::getType() const {
	return type;
}
