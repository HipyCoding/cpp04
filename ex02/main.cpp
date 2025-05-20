/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 12:26:45 by christian         #+#    #+#             */
/*   Updated: 2025/05/20 15:23:56 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

//---mainly tests for abstract---

// int main()
// {
// 	// compile test
// 	// const AAnimal* meta = new AAnimal();

// 	// AAnimal test;
	
// 	const AAnimal* j = new Dog();
// 	const AAnimal* i = new Cat();

// 	j->makeSound();
// 	i->makeSound();

// 	delete j;
// 	delete i;

// 	// Testing array of animals
// 	const int numAnimals = 4;
// 	AAnimal* animals[numAnimals];

// 	// Fill array with half dogs and half cats
// 	for (int i = 0; i < numAnimals; i++) {
// 		if (i < numAnimals / 2)
// 			animals[i] = new Dog();
// 		else
// 			animals[i] = new Cat();
// 	}

// 	for (int i = 0; i < numAnimals; i++) {
// 		animals[i]->makeSound();
// 	}

// 	for (int i = 0; i < numAnimals; i++) {
// 		delete animals[i];
// 	}

// 	return 0;
// }

 // --- also tests for stuff from before ---


 int main() {

	//compile test:
	// const AAnimal* meta = new AAnimal();

	// AAnimal test;

	std::cout << "=== Creating animals array ===" << std::endl;
	const int numAnimals = 4;
	AAnimal* animals[numAnimals];

	for (int i = 0; i < numAnimals; i++) {
		if (i < numAnimals / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	std::cout << "\n=== Testing sounds ===" << std::endl;
	for (int i = 0; i < numAnimals; i++) {
		animals[i]->makeSound();
	}

	std::cout << "\n=== Testing deep copy ===" << std::endl;
	Dog originalDog;
	originalDog.getBrain()->setIdea(0, "i am good boy");
	
	Dog copyDog = originalDog; 
	std::cout << "Original dog idea: " << originalDog.getBrain()->getIdea(0) << std::endl;
	std::cout << "Copy dog idea: " << copyDog.getBrain()->getIdea(0) << std::endl;

	copyDog.getBrain()->setIdea(0, "i am cat");
	std::cout << "\nAfter modifying copy:" << std::endl;
	std::cout << "Original dog first idea: " << originalDog.getBrain()->getIdea(0) << std::endl;
	std::cout << "Copy dog first idea: " << copyDog.getBrain()->getIdea(0) << std::endl;

	std::cout << "\n=== Cleaning up animals ===" << std::endl;
	for (int i = 0; i < numAnimals; i++) {
		delete animals[i];
	}

	return 0;
}
