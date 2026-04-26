/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssukhija <ssukhija@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 19:01:50 by ssukhija          #+#    #+#             */
/*   Updated: 2026/04/07 19:01:50 by ssukhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main() {
    std::cout << "--- FragTrap Test ---" << std::endl;
    FragTrap frag("HighFiveGuy");

    std::cout << "\n[Test: Stats]" << std::endl;
    std::cout << "EXPECTED: Attack Damage 30." << std::endl;
    frag.attack("a bully");

    std::cout << "\n[Test: Special Ability]" << std::endl;
    std::cout << "EXPECTED: High five request message." << std::endl;
    frag.highFivesGuys();

    std::cout << "\n[Test: Durability]" << std::endl;
    std::cout << "EXPECTED: Survive 99 damage, then die at 101." << std::endl;
    frag.takeDamage(99);
    frag.beRepaired(1);
    frag.takeDamage(101);
    
    std::cout << "EXPECTED: Fail attack due to death." << std::endl;
    frag.attack("the afterlife");

    return 0;
}