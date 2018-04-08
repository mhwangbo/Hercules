/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 17:04:37 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/03/03 18:40:23 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

void    error_handling(char *message)
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}

int    main(int ac, char **av)
{
    int serv_sock;
    int clnt_sock;
    struct sockaddr_in serv_addr;
    struct sockaddr_in clnt_addr;
    int clnt_addr_size;
    char message[] = "Pong Pong\n";

    if (ac != 2)
    {
        printf("Usage : %s <port>\n", av[0]);
        exit(1);
    }
	
/* Create socket */
    serv_sock = socket(PF_INET, SOCK_STREAM, 0);
    if (serv_sock == -1)
        error_handling("error: socket()");

/* Prepare the sockaddr_in structrue */
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(atoi(av[1]));

/* Bind */
    if (bind(serv_sock, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) == -1)
        error_handling("error: bind()");

/* Listen */
    if (listen(serv_sock, 5) == -1)
        error_handling("error: listen()");

/* Accept and incoming connection */
    clnt_addr_size = sizeof(clnt_addr);
    clnt_sock = accept(serv_sock, (struct sockaddr*) &clnt_addr, &clnt_addr_size);
    if (clnt_sock == -1)
        error_handling("error: accept()");

/* Return message to client */
    write(clnt_sock, message, sizeof(message));
    close(clnt_sock);

    return (0);
}
