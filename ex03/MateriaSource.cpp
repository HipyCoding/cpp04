/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 01:45:18 by candrese          #+#    #+#             */
/*   Updated: 2025/05/20 06:51:19 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : count(0) {
	// std::cout << "MateriaSource constructor called" << std::endl;
	for (int i = 0; i < 4; i++) {
		templates[i] = nullptr;
	}
}

MateriaSource::MateriaSource(const MateriaSource& other) : count(other.count) {
	// std::cout << "MateriaSource copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (other.templates[i] != nullptr) {
			templates[i] = other.templates[i]->clone();
		} else {
			templates[i] = nullptr;
		}
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
	// std::cout << "MateriaSource assignment operator called" << std::endl;
	if (this != &other) {
		// delete templats
		for (int i = 0; i < 4; i++) {
			delete templates[i];
			templates[i] = nullptr;
		}
		
		// copy templates
		count = other.count;
		for (int i = 0; i < 4; i++) {
			if (other.templates[i] != nullptr) {
				templates[i] = other.templates[i]->clone();
			}
		}
	}
	return *this;
}

MateriaSource::~MateriaSource() {
	// std::cout << "MateriaSource destructor called" << std::endl;
	for (int i = 0; i < 4; i++) {
		delete templates[i];
	}
}

void MateriaSource::learnMateria(AMateria* m) {
	if (m == nullptr) {
		return;
	}

	if (count < 4) {
		templates[count++] = m;
		// std::cout << "MateriaSource learned " << m->getType() << std::endl;
	} else {
		std::cout << "MateriaSource can't learn more Materias. Memory is full!" << std::endl;
		delete m;
	}
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < count; i++) {
		if (templates[i]->getType() == type) {
			// std::cout << "MateriaSource created a " << type << " Materia" << std::endl;
			return templates[i]->clone();
		}
	}
	std::cout << "MateriaSource couldn't create a " << type << " Materia. Type unknown!" << std::endl;
	return nullptr;
}
