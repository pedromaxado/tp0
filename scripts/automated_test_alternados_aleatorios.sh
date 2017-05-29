#!/bin/bash

#for f in 50
#do
    for file in testes/aleatorios/*.txt
    do
        echo "$file" >> log_aleatorios.txt
        for i in $(seq 1 10)
        do
            /usr/bin/time -f "%e" -a -o "log_aleatorios.txt" ./tp0 < $file > /dev/null
        done
    done
#done
