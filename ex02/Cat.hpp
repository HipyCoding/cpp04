/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:32:08 by christian         #+#    #+#             */
/*   Updated: 2025/02/12 17:33:37 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat final : public AAnimal {
private:
	Brain* brain;

public:
	Cat();
	explicit Cat(const std::string& type);
	Cat(const Cat& other);
	Cat& operator=(const Cat& other);
	~Cat() override;

	void makeSound() const override;
	Brain* getBrain() const;
};

#endif
