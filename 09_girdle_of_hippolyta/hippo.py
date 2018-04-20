# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    hippo.py                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/20 15:49:23 by mhwangbo          #+#    #+#              #
#    Updated: 2018/04/20 16:33:25 by mhwangbo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

from email.MIMEMultipart import MIMEMultipart
from email.MIMEText import MIMEText
from email.header import Header
from email.utils import formataddr
import getpass
import smtplib

fromEmail = raw_input("Your Email address: ")
fromEmailPW = getpass.getpass('Password: ')
fromName = raw_input("Your Name: ")
toEmail = raw_input("To: ")
emailsubject = raw_input("Subject: ")
emailtext = raw_input("Please type your content\n")

msg = MIMEMultipart('alternative')

msg['To'] = toEmail

msg['Subject'] = emailsubject

msg['From'] = formataddr((str(Header(fromName, 'utf-8')), fromEmail))

part1 = MIMEText(emailtext, 'plain')

msg.attach(part1)

server = smtplib.SMTP('smtp.gmail.com', 587)

server.starttls()

server.login(fromEmail, fromEmailPW)

server.sendmail(fromEmail, toEmail, msg.as_string())

print 'EMAIL SENT'

server.quit()
