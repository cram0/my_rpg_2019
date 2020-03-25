#!/usr/bin/env bash

for f in data/*.csv
do
    if [[ ! $f =~ _all\.csv$ ]]
    then
        awk -f scripts/generate_rects.awk $f
        echo
    fi
done