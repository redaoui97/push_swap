#!/bin/bash

i=1
unset test
declare -A num_array

check_function () {
    for var in num_array
    do
        if [ $num -eq $num_array[$i] ]
        then
            num=$((-10 + $RANDOM % 0))
        fi
        if [ $num -eq $num_array[$i] ]
        then
            check_function
        fi
    done
}

while [ $i -le $1 ]
do
    num=$RANDOM
    num_array[$i]=$num
    check_function
    i=$(( $i + 1 ))
done

i=2
test=$num_array[0]
while [ $i -le $1 ]
do
    test="${test} ${num_array[$i]}"
    i=$(( $i + 1 ))
done
export test