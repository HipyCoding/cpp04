/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 12:26:45 by christian         #+#    #+#             */
/*   Updated: 2025/02/12 15:13:20 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
	std::cout << "=== Creating animals array ===" << std::endl;
	const int numAnimals = 4;
	Animal* animals[numAnimals];

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
