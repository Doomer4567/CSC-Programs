#! /bin/bash
#Author: Ethan Byker
#Date: APR 19th, 2024
#Description: This code logs any errors,info,or warnings the
# web service has created.

#Makes logs directory and moves into that directory, exiting should it fail
mkdir logs
cd logs || exit

#create base variables needed for the program
strUrl="https://www.swollenhippo.com/ITSecurity/criticalLogs.php"
arrResult=$(curl "$strUrl" )
intLength=$(echo "$arrResult" | jq 'length')
strDate=$(date +"%d-%b-%Y")
intCounter=0
#this makes the file once, I had a bad feeling about looping a touch command
touch "$strDate$1.log"

#This makes sure we run throught the whole program
while [ "$intCounter" -lt "$intLength" ];
do
    #This grabs the log type from each object in the array
    logTypestr=$(echo "$arrResult" | jq -r .[$intCounter].logType)
    #This checks if the log pulled is the same log the user requested
    if [ "$logTypestr" = "$1" ]; then
        #This outputs every log with the requested logtype into the file
        #touch "$strDate$logTypestr.log"
        strServer=$(echo "$arrResult" | jq .[$intCounter].server)
        strErrorContent=$(echo "$arrResult" | jq .[$intCounter].contents)
        echo "$logTypestr,$strServer,$strErrorContent" >> "$strDate$logTypestr.log"
    fi
    #adds one to our counter
    ((intCounter++))
done
