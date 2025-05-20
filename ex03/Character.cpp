/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 01:17:49 by candrese          #+#    #+#             */
/*   Updated: 2025/05/20 06:18:51 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : name("unnamed"), floorCount(0) {
	// std::cout << "Character default constructor called" << std::endl;
	for (int i = 0; i < 4; i++) {
		inventory[i] = nullptr;
	}
	for (int i = 0; i < 10; i++) {
		floor[i] = nullptr;
	}
}

Character::Character(std::string const & name) : name(name), floorCount(0) {
	// std::cout << "Character parameterized constructor called for " << name << std::endl;
	for (int i = 0; i < 4; i++) {
		inventory[i] = nullptr;
	}
	for (int i = 0; i < 10; i++) {
		floor[i] = nullptr;
	}
}

Character::Character(const Character& other) : name(other.name), floorCount(0) {
	// std::cout << "Character copy constructor called" << std::endl;
	// deep copy inventory
	for (int i = 0; i < 4; i++) {
		if (other.inventory[i] != nullptr)
		{
			inventory[i] = other.inventory[i]->clone();
		}
		else
		{
			inventory[i] = nullptr;
		}
	}
	// init floor
	for (int i = 0; i < 10; i++) {
		floor[i] = nullptr;
	}
}

Character& Character::operator=(const Character& other) {
	// std::cout << "Character assignment operator called" << std::endl;
	if (this != &other) {
		name = other.name;

		// delete our inventory
		for (int i = 0; i < 4; i++) {
			delete inventory[i];
			inventory[i] = nullptr;
		}
		// deep copy inventory
		for (int i = 0; i < 4; i++) {
			if (other.inventory[i] != nullptr)
			{
				inventory[i] = other.inventory[i]->clone();
			}
		}
		// clean floor
		for (int i = 0; i < 10; i++) {
			delete floor[i];
			floor[i] = nullptr;
		}
		floorCount = 0;
	}
	return *this;
}

Character::~Character() {
	// std::cout << "Character destructor called for " << name << std::endl;
	// del inventory
	for (int i = 0; i < 4; i++) {
		delete inventory[i];
	}
	// del floor
	for (int i = 0; i < 10; i++) {
		delete floor[i];
	}
}

std::string const & Character::getName() const {
	return name;
}

void Character::equip(AMateria* m) {
	if (m == nullptr) {
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (inventory[i] == nullptr) {
			inventory[i] = m;
			// std::cout << name << " equipped " << m->getType() << " at slot " << i << std::endl;
			return;
		}
	}
	std::cout << name << " couldn't equip " << m->getType() << ". Inventory is full!" << std::endl;
}

void Character::unequip(int idx) {
	if (idx < 0 || idx >= 4 || inventory[idx] == nullptr) {
		return;
	}

	if (floorCount < 10) {
		floor[floorCount++] = inventory[idx];
		std::cout << name << " unequipped " << inventory[idx]->getType() << " from inventory slot " << idx << std::endl;
		inventory[idx] = nullptr;
	} else {
		std::cout << "Floor is a mess. Cannot unequip anymore." << std::endl;
	}
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx >= 4 || inventory[idx] == nullptr) {
		return;
	}
	inventory[idx]->use(target);
}
