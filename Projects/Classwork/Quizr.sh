#! /bin/bash
mkdir Books
cd Books || exit
counter=0
while [ "$counter" -lt "$1" ];
do
    read -rp "Please enter a book id here: " UsrInput
    URL="http://gutendex.com/books/?ids="
    URLarray="$URL$UsrInput"
    Download=$(curl "${URLarray})" | jq -r .results[0].download_count)
    Time=$(date +"%Y-%m-%d")
    ID=$(curl "${URLarray}" | jq -r .results[0].id)
    mkdir "$ID"
    cd "$ID" || exit
    Title=$(curl "${URLarray}" | jq -r .results[0].title)
    touch "$Title.txt"
    echo "$Time:$Download" >> "$Title.txt"
    for f in *\ *; do mv "$f" "${f// /_}"; done
    cd ..
    ((counter++))
done