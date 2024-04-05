#! /bin/bash
mkdir Test
cd Test || exit
arrResult=$(curl https://swollenhippo.com/crockett.php/peppers?APIKey=0BE51E93-631C-4D26-A81E-BF0F7A9E2D1B)
intLength=$(echo "${arrResult}" | jq '.|length')
intCurrent=0
while [ "$intCurrent" -lt "$intLength" ];
do
    Title=$(echo "${arrResult}" | jq -r .[${intCurrent}].PepperName)
    mkdir $Title
    ((intCurrent++))
done