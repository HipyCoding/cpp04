/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christian <christian@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:32:08 by christian         #+#    #+#             */
/*   Updated: 2025/02/12 11:58:05 by christian        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat final : public Animal {
public:
	Cat();
	explicit Cat(const std::string& type);
	Cat(const Cat& other);
	Cat& operator=(const Cat& other);
	~Cat() override;

	void makeSound() const override;
};

#endif