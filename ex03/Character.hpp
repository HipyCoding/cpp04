/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 01:17:52 by candrese          #+#    #+#             */
/*   Updated: 2025/05/20 05:07:30 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include <string>

class Character : public ICharacter {
private:
	std::string name;
	AMateria* inventory[4];
	AMateria* floor[10]; // unequiped
	int floorCount;

public:
	Character();
	explicit Character(std::string const & name);
	Character(const Character& other);
	Character& operator=(const Character& other);
	~Character();

	std::string const & getName() const override;
	void equip(AMateria* m) override;
	void unequip(int idx) override;
	void use(int idx, ICharacter& target) override;
};

#endif
