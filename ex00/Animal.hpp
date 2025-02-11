/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:54:28 by candrese          #+#    #+#             */
/*   Updated: 2025/02/11 19:02:34 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostring>

class Animal {

protected:
	std::string type;

public;
	Animal();
	Animal(std::string& name);
	Animal(const Animal &other);
	~Animal();
	
	void makeSound();
	std::string getType();
}
