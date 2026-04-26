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

#include "ScavTrap.hpp"

int main() {
    std::cout << "--- ScavTrap Test ---" << std::endl;
    ScavTrap scav("GateGuardian");

    std::cout << "\n[Test: Overridden Attack]" << std::endl;
    std::cout << "EXPECTED: ScavTrap unique attack message with 20 damage." << std::endl;
    scav.attack("an intruder");

    std::cout << "\n[Test: Special Ability]" << std::endl;
    std::cout << "EXPECTED: Gate keeper mode message." << std::endl;
    scav.guardGate();

    std::cout << "\n[Test: Stamina]" << std::endl;
    std::cout << "EXPECTED: Start with 50 EP. Use all and fail." << std::endl;
    for(int i = 0; i < 51; i++) scav.attack("training post");

    return 0;
}