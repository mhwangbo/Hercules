/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 17:03:58 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/03/03 18:40:16 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

void	error_handling(char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}

int		main(int ac, char **av)
{
	int 	sock;
	struct	sockaddr_in    serv_addr;
	char	message[30];
	int		str_len;

	if (ac != 4)
	{
		printf("Usage : %s <IP> <port> ping\n", av[0]);
		exit(1);
	}

/* Creat socket */
	sock = socket(PF_INET, SOCK_STREAM, 0);
	if (sock == -1)
		error_handling("error: socket()");

	memset(&serv_addr, 0, sizeof(serv_addr));
/* Set as AF_INET IPv4 Internet protocol */
	serv_addr.sin_family = AF_INET;
/* Convert into 32bit IP address */
	serv_addr.sin_addr.s_addr = inet_addr(av[1]);
/* Port number */
	serv_addr.sin_port = htons(atoi(av[2]));

/* Connect to remote server */
	if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1)
		error_handling("error: connect()");

/* Receive data from server */
	str_len = read(sock, message, sizeof(message)-1);
	if(str_len == -1)
		error_handling("error: read()");
	message[str_len] = 0;
	printf("%s", message);
	return (0);
}
