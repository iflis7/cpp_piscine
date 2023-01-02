/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsaadi <hsaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 12:29:19 by hsaadi            #+#    #+#             */
/*   Updated: 2023/01/02 13:20:17 by hsaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	print_upper(char *str)
{
	int		j = 0;
	char	c;

	while(str[j])
	{
		if (isalpha(str[j]))
		{
			c = toupper(str[j]);
			std::cout << c;
		}
		else
			std::cout << str[j];
		j++;
	}
}

int	main(int argc, char *argv[])
{
	if (argc > 1)
	{
		for (int i = 1; i < argc; i++)
		{
            print_upper(argv[i]);
		}
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return (0);
}