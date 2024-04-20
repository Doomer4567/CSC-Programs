#! /bin/bash
intbookAmount=0
while [ "$intbookAmount" -lt "$1" ];
do
read -rp "Please enter a book ID to add: " bookID
strBaseurl="http://gutendex.com/books/?ids="
strCurlUrl="$strBaseurl$bookID"
mkdir "$bookID"
cd "$bookID" || exit
fileName=$(curl "$strCurlUrl" | jq -r .results[0].title)
fileName="${fileName// /_}"
touch "$fileName.txt"
date=$(date +"%Y-%m-%d") >> "$fileName.txt"
download=$(curl "$strCurlUrl" | jq -r .results[0].download_count) 
echo "$date:$download" >> "$fileName.txt"

cd ..
((intbookAmount++))
done