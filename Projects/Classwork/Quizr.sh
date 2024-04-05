#! /bin/bash

strBaseUrl="http://gutendex.com/books/?ids=12,1,14,15"
URLarray="curl $strBaseUrl"
URLL=$(echo "$URLarray" | jq 'length')
count=0
while [ "$count" -lt "$URLL" ];
do
    urg=$(echo "$URLarray" | jq -r .["$x"].title)
    Title=$(echo "$urg" | tr " " _)
    mkdir Test/"$Title"
    ((x++))
done

ls -o