/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:36:15 by candrese          #+#    #+#             */
/*   Updated: 2025/02/12 19:13:22 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <string>
# include <iostream>

class AAnimal {
protected:
	std::string type;

public:
	AAnimal();
	explicit AAnimal(const std::string& type);
	AAnimal(const AAnimal &other);
	AAnimal& operator=(const AAnimal& other);
	virtual ~AAnimal();
	
	virtual void makeSound() const = 0; // Made pure virtual
	std::string getType() const;
};

#endif
