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
#include "DiamondTrap.hpp"

void printHeader(std::string title) {
    std::cout << "\n==================== " << title << " ====================" << std::endl;
}

int main() {
    printHeader("CONSTRUCTION");
    std::cout << "EXPECTED: Clap -> Frag -> Scav -> Diamond (Reverse for destructors)" << std::endl;
    DiamondTrap monster("Monster");

    printHeader("IDENTITY CHECK");
    std::cout << "EXPECTED: Name: Monster, ClapName: Monster_clap_name" << std::endl;
    monster.whoAmI();

    printHeader("STAT CHECK (FRAG HP/AD, SCAV EP)");
    std::cout << "EXPECTED: Damage should be 30. Energy should be 50." << std::endl;
    monster.attack("a target"); // Should use ScavTrap message but 30 damage
    
    printHeader("EDGE CASE: ENERGY EXHAUSTION");
    std::cout << "EXPECTED: Perform actions until EP hits 0. Then failure message." << std::endl;
    for (int i = 0; i < 50; i++) {
        std::cout << "[" << i << "] ";
        monster.beRepaired(1); // Consumes 1 EP each
    }
    std::cout << "EXPECTED: Out of Energy message:" << std::endl;
    monster.attack("a final fly");

    printHeader("EDGE CASE: DEATH");
    std::cout << "EXPECTED: Take 200 damage. Then fail to Repair/Attack." << std::endl;
    monster.takeDamage(200);
    std::cout << "EXPECTED: 'Already dead' or 'Unable' messages:" << std::endl;
    monster.beRepaired(10);
    monster.attack("ghost");

    printHeader("DESTRUCTION");
    return 0;
}