#!/usr/bin/ruby

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    hind.rb                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/09 20:48:07 by mhwangbo          #+#    #+#              #
#    Updated: 2018/03/09 20:48:07 by mhwangbo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

require	"oauth2"

UID = "6414c02a008787e1590d454ad60f129e681d3fa5e46efb50ce64d4ac3838bb8e"
SECRET = "d015e48c721c212984885948a95242b031f1d75c33fb957e116eda1c85060632"

$client = OAuth2::Client.new(UID, SECRET, site: "https://api.intra.42.fr")

$token = $client.client_credentials.get_token

def ft_find(login)
	begin
		response = $token.get("/v2/users/#{login}/locations")
		while response.status != 200
			puts ("server down")
			sleep(5)
			if responses.status == 200
				break
			end
		end
		if !response.parsed[0]["end_at"]
			puts (login.ljust(10, ' ') + ": " + response.parsed[0]["host"])
		else
			puts (login.ljust(10, ' ') + ": not here")
			puts ("(last login: " + response.parsed[0]["host"] + ")")
		end
	rescue
		puts (login.ljust(10) + ": it is no one")
	end
end

if ARGV[0]
	if File.file?(ARGV[0]) and File.extname(ARGV[0]) == ".txt"
		file = File.open(ARGV[0], "r").each_line do |line|
			line == "\n" ? next : login = line.strip
			ft_find(login)
		end
		file.close
	else
		puts "invalid file"
	end
else
	puts "usage: " + $PROGRAM_NAME + " [file.txt]"
end
