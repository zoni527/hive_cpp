/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:13:17 by jvarila           #+#    #+#             */
/*   Updated: 2025/06/02 16:08:51 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main() {

	std::string stringVAR = "HI THIS IS BRAIN";
	std::string *stringPTR = &stringVAR;
	std::string &stringREF = stringVAR;

	std::cout << "\nAddress of the string variable:		" << &stringVAR << "\n";
	std::cout << "Memory address held by stringPTR:	" << stringPTR << "\n";
	std::cout << "Memory address held by stringREF:	" << &stringREF << "\n\n";

	std::cout << "Value of the string variable:		" << stringVAR << "\n";
	std::cout << "Value pointed to by stringPTR:		" << *stringPTR << "\n";
	std::cout << "Value pointed to by stringREF:		" << stringREF << "\n";
	std::cout << std::endl;

	return 0;
}
