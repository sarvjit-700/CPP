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

#include "ClapTrap.hpp"

int main()
{
    std::cout << "--- CONSTRUCTING ---" << std::endl;
    ClapTrap clippy("Clippy");
    ClapTrap trappy("Trappy");

    std::cout << "\n--- TEST 1: Basic Actions ---" << std::endl;
    clippy.attack("a training dummy");
    trappy.takeDamage(5);
    trappy.beRepaired(3);

    std::cout << "\n--- TEST 2: Energy Depletion ---" << std::endl;
    // Clippy already used 1 energy. Let's use the remaining 9.
    for (int i = 0; i < 10; i++) {
        clippy.attack("the air");
    }
    clippy.beRepaired(5); // Should fail: no energy left

    std::cout << "\n--- TEST 3: Death Logic ---" << std::endl;
    trappy.takeDamage(20); // Massive damage
    trappy.attack("revenge"); // Should fail: no HP left
    trappy.beRepaired(10); // Should fail: no HP left

    std::cout << "\n--- TEST 4: Canonical Form (Independence) ---" << std::endl;
    ClapTrap original("Original");
    ClapTrap clone(original); // Copy constructor
    
    original.takeDamage(5);
    std::cout << "Original should have 5 HP, Clone should still have 10 HP:" << std::endl;
    // If your logic is correct, damaging the original doesn't hurt the clone!

    std::cout << "\n--- DESTRUCTORS ---" << std::endl;
    return 0;
}