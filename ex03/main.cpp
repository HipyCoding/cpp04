/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 02:53:38 by candrese          #+#    #+#             */
/*   Updated: 2025/05/20 14:49:30 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include <iostream>


//main function from subject

// int main()
// {
// IMateriaSource* src = new MateriaSource();
// src->learnMateria(new Ice());
// src->learnMateria(new Cure());
// ICharacter* me = new Character("me");
// AMateria* tmp;
// tmp = src->createMateria("ice");
// me->equip(tmp);
// tmp = src->createMateria("cure");
// me->equip(tmp);
// ICharacter* bob = new Character("bob");
// me->use(0, *bob);
// me->use(1, *bob);
// delete bob;
// delete me;
// delete src;
// return 0;
// }

//more thorough testing

int main()
{
std::cout << "\n-MateriaSource capacity:-" << std::endl;
IMateriaSource* source = new MateriaSource();
source->learnMateria(new Ice());
source->learnMateria(new Cure());
source->learnMateria(new Ice());
source->learnMateria(new Cure());
source->learnMateria(new Ice()); // must fail

// invalid Materia creation
std::cout << "\n-invalid Materia creation:-" << std::endl;
AMateria* invalid = source->createMateria("fire"); // must fail
if (invalid == nullptr) {
	std::cout << "returned NULL for Materia type" << std::endl;
}

// character inventory management
std::cout << "\n-inventory management:-" << std::endl;
ICharacter* hero = new Character("Hero");

// equipping 4 Materias
for (int i = 0; i < 4; i++) {
	if (i % 2 == 0) {
		hero->equip(source->createMateria("cure"));
	} else {
		hero->equip(source->createMateria("ice"));
	}
}

// equip one more
hero->equip(source->createMateria("ice")); // must fail

// unequip
std::cout << "unequip functionality:" << std::endl;
hero->unequip(2);

// eqpui new one in free slot
hero->equip(source->createMateria("cure"));

// use all Materials
std::cout << "\n-try use all equipped Materias:-" << std::endl;
ICharacter* target = new Character("Target");
for (int i = 0; i < 4; i++) {
	hero->use(i, *target);
}

// deep copy
std::cout << "\n-deep copy from Character:-" << std::endl;
Character* original = new Character("original");
original->equip(source->createMateria("ice"));
original->equip(source->createMateria("cure"));

Character* copy = new Character(*original);
std::cout << "original character name: " << original->getName() << std::endl;
std::cout << "copy character name: " << copy->getName() << std::endl;

std::cout << "UMaterias from original:" << std::endl;
original->use(0, *target);
original->use(1, *target);
// delete original;

std::cout << "Materias from copy:" << std::endl;
copy->use(0, *target);
copy->use(1, *target);

std::cout << "\n-cleaning memory:-" << std::endl;
delete target;
delete hero;
delete original;
delete copy;
delete source;

return 0;
}
