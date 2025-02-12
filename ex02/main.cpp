/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 12:26:45 by christian         #+#    #+#             */
/*   Updated: 2025/02/12 19:22:50 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	// compile test
	// const AAnimal* meta = new AAnimal();
	
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();

	j->makeSound();
	i->makeSound();

	delete j;
	delete i;

	// Testing array of animals
	const int numAnimals = 4;
	AAnimal* animals[numAnimals];

	// Fill array with half dogs and half cats
	for (int i = 0; i < numAnimals; i++) {
		if (i < numAnimals / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	for (int i = 0; i < numAnimals; i++) {
		animals[i]->makeSound();
	}

	for (int i = 0; i < numAnimals; i++) {
		delete animals[i];
	}

	return 0;
}

