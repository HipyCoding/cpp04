/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 01:17:37 by candrese          #+#    #+#             */
/*   Updated: 2025/05/20 06:18:40 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria() : type("Generic AMateria") {
	// std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const & type) : type(type) {
	// std::cout << "AMateria parameterized constructor called for " << type << std::endl;
}

AMateria::AMateria(const AMateria& other) : type(other.type) {
	// std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& other) {
	// std::cout << "AMateria assignment operator called" << std::endl;
	if (this != &other) {
		type = other.type;
	}
	return *this;
}

AMateria::~AMateria() {
	// std::cout << "AMateria destructor called" << std::endl;
}

std::string const & AMateria::getType() const {
	return type;
}

void AMateria::use(ICharacter& target) {
	std::cout << "* uses an unknown materia on " << target.getName() << " *" << std::endl;
}
