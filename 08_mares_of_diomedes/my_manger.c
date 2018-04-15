/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_manger.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 15:55:07 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/04/14 19:28:18 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

void	we_are_horses()
{
	printf(RED "                                                                -=._\n");
	printf(GRN "                                                            .oo0P~GPjo.\n");
	printf(YEL "                                                       .o0o0000P'.?P   `jo.'.\n");
	printf(BLU "                                                __     .000000P.;'   .dP.dPo) ,\n");
	printf(MAG "                                           . '0000oo.00d00b.P'        X^V  P<<\n");
	printf(CYN "                                             '~~',`0.d'd;V'.8      '(       o)K\n");
	printf(WHT "                       . -  ~  ~  -  .   _  _ - '  .d'd(   8'     ' :      .' X\n");
	printf(CYN "        _.oo00oo._ . `                             V' `?   ?'  .'   ;    .'\n");
	printf(MAG "     .C000000000000o=K                             '   `  `   `.   {  .  ;\n");
	printf(BLU "    C00000000000P~'   '             `                          )-.  `'J o,\n");
	printf(YEL "    `?000000P~' `     '              '                         ;. `.   `'\n");
	printf(GRN "      )0000D'   `      `            .'                       .'_.`-.`.\n");
	printf(RED "  .oo00000P'     `.'`.  `.                           `.    .'       ) `.\n");
	printf(GRN ".o00P~~'  .   - '  . - . _`(      .'` `  -  .  -  ` - -`.  ' _ .-   '`. ,\n");
	printf(YEL "  ~j   .'         '   _          .'                      `'~     ' ' /'-,\n");
	printf(BLU "      . .' ' '  ' `  `  `~'`~--~'                              .' '  `-.,\n");
	printf(MAG "      , ,          ` `                                      .',. '\n");
	printf(CYN "      . .           ` `                                     U,'\n");
	printf(WHT "    . '.'         _ .`.`\n");
	printf(CYN "  ,-,'           bd_.'\n");
	printf(MAG "  U,'\n");
	printf(RESET "\n");
}

int		main(void)
{
	int	i;

	i = 0;
	while (i == 0)
	{
		if (!fork())
		{
			we_are_horses();
			sleep(2);
		}
		else
		{
			system("say -v yuna 히잉 히잉 히잉 히잉 히잉");
			sleep(2);
		}
	}
	return (0);
}
