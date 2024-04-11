#!/bin/bash
#Author: Ethan Byker
#Description: Grabs error code data from the url and outputs it into log files

# Safe keep Url and makes a variable that holds the curl output of said website
Url="https://simplefarm.thesimplehomestead.com/errorlogs.php"
ArrResults=$(curl "$Url")

# finds the length for our while loop
length=$(echo "$ArrResults" | jq 'length')

# intialization of a counter for while loop
count=0

# using the length given from jq allows the while loop 
# to run through each item in the array
while [ "$count" -lt "$length" ];
do
    # Grabs the Error code from the URL and make it into a directory
    Error=$(echo "$ArrResults" | jq -r .[$count].code)
    mkdir "Code-$Error" && cd "Code-$Error" || exit

    # Grabs today's time from system and turns it into a file
    currentTime=$(date +%d-%b-%Y) && touch "$currentTime".log

    # Grabs the Message and the reporter's FirstName and LastName 
    # from the URL with the user input of their Operator Name
    # and outputs it to the log file
    Message=$(echo "$ArrResults" | jq -r .[$count].message)
    FName=$(echo "$ArrResults" | jq -r .[$count].reportingfirstname)
    LName=$(echo "$ArrResults" | jq -r .[$count].reportinglastname)
    #Output Statements
    echo "Operator Name: $1" >> "$currentTime".log
    echo "$Message. Reported by: $LName, $FName" >> "$currentTime".log

    cd ..
    ((count++))
done