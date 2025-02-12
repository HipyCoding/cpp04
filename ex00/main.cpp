/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christian <christian@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:54:44 by candrese          #+#    #+#             */
/*   Updated: 2025/02/12 11:51:44 by christian        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "=== Testing Default Constructors ===" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << "\nTypes:" << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	
	std::cout << "\nSounds:" << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	std::cout << "\nCleaning up animals..." << std::endl;
	delete meta;
	delete j;
	delete i;

	std::cout << "\n=== Testing Parameterized Constructors ===" << std::endl;
	std::string custom_type = "Special";
	Animal* special_animal = new Animal(custom_type);
	Dog* special_dog = new Dog(custom_type);
	Cat* special_cat = new Cat(custom_type);

	std::cout << "\nCustom Types:" << std::endl;
	std::cout << special_animal->getType() << std::endl;
	std::cout << special_dog->getType() << std::endl;
	std::cout << special_cat->getType() << std::endl;

	delete special_animal;
	delete special_dog;
	delete special_cat;

	std::cout << "\n=== Testing Wrong Animal Class ===" << std::endl;
	const WrongAnimal* wrong_meta = new WrongAnimal();
	const WrongAnimal* wrong_cat = new WrongCat();

	std::cout << "\nWrong Types:" << std::endl;
	std::cout << wrong_cat->getType() << " " << std::endl;

	std::cout << "\nWrong Sounds:" << std::endl;
	wrong_cat->makeSound(); // Will output WrongAnimal sound, not WrongCat sound
	wrong_meta->makeSound();

	std::cout << "\nCleaning up wrong animals..." << std::endl;
	delete wrong_meta;
	delete wrong_cat;

	return 0;
}

// int main()
// {
// const Animal* meta = new Animal();
// const Animal* j = new Dog();
// const Animal* i = new Cat();
// std::cout << j->getType() << " " << std::endl;
// std::cout << i->getType() << " " << std::endl;
// i->makeSound(); //will output the cat sound!
// j->makeSound();
// meta->makeSound();
// //...
// return 0;
// }
