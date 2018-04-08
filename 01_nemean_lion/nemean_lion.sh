#!/bin/bash

apt-get install openssh-server -y
cp /etc/ssh/sshd_config /etc/ssh/sshd_backup
sed -i "s/#Port 22/Port 4345/" /etc/ssh/sshd_config
service ssh restart
