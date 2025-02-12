/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:54:41 by candrese          #+#    #+#             */
/*   Updated: 2025/02/12 17:33:41 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal {

private:
	Brain* brain;	

public:
	Dog();
	explicit Dog(const std::string& type);
	Dog(const Dog& other);
	Dog& operator=(const Dog& other);
	~Dog() override;

	void makeSound() const override;
	Brain* getBrain() const;
};

#endif
