#!/bin/bash

# Usage: ./push_test.sh ./path/to/push_swap ./path/to/checker argument_count test_count
# Example: ./push_test.sh ./push_swap ./checker_linux 100 100

push_swap=$1
checker=$2
number_count=$3
iteration_count=$4

numbers="$(dirname $0)/numbers.py"

declare -i best_result=9999999999
declare -i worst_result=0
declare -i average_sum=0
declare -i average_result=0

ko="false"

run_main_test() {
    argv=$($numbers $number_count)
    program=$($push_swap $argv 2>/dev/null)
    result=$($push_swap $argv | $checker $argv 2>&1)
    instruction_count=$(wc -l <<< "$program")

    if [ $result == "KO" ] || [ $result == "Error" ]
    then
        ko="true"
        printf "\e[0;0J"
        printf "\e[0;36m> Running push_swap test $1: \e[0;31m$result ($instruction_count instructions)\n"
        printf "  KO/Error detected, stoppig.\n"
        printf "  Argument list used: $argv\n"
    else
        printf "\e[0;0J"
        printf "\e[0;36m> Running push_swap test $1: \e[0;37m$result ($instruction_count instructions)\r"

        if (($instruction_count > $worst_result))
        then
            worst_result=$instruction_count
        fi

        if (($instruction_count < $best_result))
        then
            best_result=$instruction_count
        fi

        ((average_sum = $average_sum + $instruction_count))
    fi
}

run_all_tests() {
    for (( i = 1; i <= $iteration_count; i++ ))
    do
        run_main_test "#$i/$iteration_count"

        if [ $ko == "true" ]
        then
            break
        fi
    done

    if [ $ko == "false" ]
    then
        ((average_result = $average_sum / $iteration_count))

        printf "\e[0;0J"
        printf "\e[0;36m> Testing complete: ($number_count items / $iteration_count samples)\n"
        printf "\e[0;32m  Best result:    $best_result\n"
        printf "\e[0;31m  Worst result:   $worst_result\n"
        printf "\e[0;33m  Average result: $average_result\n"
    fi
}

handle_interrupt() {
    trap SIGINT

    ((average_result = $average_sum / $i))

    printf "\e[0;0J\n"
    printf "\e[0;36m> Testing interrupted! ($number_count items / $i samples)\n"
    printf "\e[0;32m  Best result:    $best_result\n"
    printf "\e[0;31m  Worst result:   $worst_result\n"
    printf "\e[0;33m  Average result: $average_result\n"

    exit
}

trap "handle_interrupt" INT

run_all_tests

trap SIGINT