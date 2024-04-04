#! /bin/bash

strBaseUrl="http://gutendex.com/books/?ids="
URLarray=curl "$strBaseUrl"
URLL="$urlArray" | jq 'Length'
while [ x -lt "$URLL" ];
do
    Title="$URLarray" | jq -r ".[$x].title
    mkdir "$Title"
    ((x++))
done
