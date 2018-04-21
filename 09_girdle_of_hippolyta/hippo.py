# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    hippo.py                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/20 15:49:23 by mhwangbo          #+#    #+#              #
#    Updated: 2018/04/20 17:32:53 by mhwangbo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

from email.MIMEMultipart import MIMEMultipart
from email.MIMEText import MIMEText
from email.header import Header
from email.utils import formataddr
import getpass
import smtplib
import poplib
from email import parser

yes = {'yes', 'y', 'ye', ''}
no = {'no', 'n'}
print('             ___           ___           ___                       ___\n            /\  \         /\__\         /\  \          ___        /\__\\\n           /::\  \       /::|  |       /::\  \        /\  \      /:/  /\n          /:/\:\  \     /:|:|  |      /:/\:\  \       \:\  \    /:/  /\n         /::\~\:\  \   /:/|:|__|__   /::\~\:\  \      /::\__\  /:/  /\n        /:/\:\ \:\__\ /:/ |::::\__\ /:/\:\ \:\__\  __/:/\/__/ /:/__/\n        \:\~\:\ \/__/ \/__/~~/:/  / \/__\:\/:/  / /\/:/  /    \:\  \\\n         \:\ \:\__\         /:/  /       \::/  /  \::/__/      \:\  \\\n          \:\ \/__/        /:/  /        /:/  /    \:\__\       \:\  \\\n           \:\__\         /:/  /        /:/  /      \/__/        \:\__\\\n            \/__/         \/__/         \/__/                     \/__/')
print('\n          __________-------____                 ____-------__________\n          \------____-------___--__---------__--___-------____------/\n           \//////// / / / / / \   _-------_   / \ \ \ \ \ \\\\\\\\/\n             \////-/-/------/_/_| /___   ___\ |_\_\------\-\-\\\\/\n               --//// / /  /  //|| (O)\ /(O) ||\\  \  \ \ \\\\--\n                    ---__/  // /| \_  /V\  _/ |\ \\  \__---\n                         -//  / /\_ ------- _/\ \  \\-\n                           \_/_/ /\---------/\ \_\_/\n                               ----\   |   /----\n                                    | -|- |\n                                   /   |   \\\n                                   ---- \___|')

fromEmail = raw_input("Your Email address: ")
fromEmailPW = getpass.getpass('Password: ')
print('Do you want to check your email? (yes/no)')
answer = raw_input().lower()
if answer in yes:
    mailbox = poplib.POP3_SSL('pop.gmail.com')
    mailbox.user(fromEmail)
    mailbox.pass_(fromEmailPW)
    messages = [mailbox.retr(i) for i in range(1, len(mailbox.list()[1]) + 1)]
    messages = ["\n".join(mssg[1]) for mssg in messages]
    messages = [parser.Parser().parsestr(mssg) for mssg in messages]
    for message in messages:
        print message['subject']
    mailbox.quit()
elif answer in no:
    print("If so, let's send email")
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
else:
    print("Please respond with 'yes' or 'no'")
