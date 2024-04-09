#! /bin/bash
mkdir Books
cd Books || exit
counter=0
while [ "$counter" -lt "$1" ];
do
    read -rp "Please enter a book id here: " ID
    URL="http://gutendex.com/books/?ids="
    URLarray="$URL$ID"
    mkdir "$ID"
    cd "$ID" || exit
    Title=$(curl "${URLarray}" | jq -r .results[0].title)
    touch "$Title.txt"
    Download=$(curl "${URLarray}" | jq .results[0].download_count)
    Time=$(date +%Y-%m-%d)
    echo "$Time:$Download" >> "$Title.txt"
    for f in *\ *; do mv "$f" "${f// /_}"; done
    cd ..
    ((counter++))
done