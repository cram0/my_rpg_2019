#!/usr/bin/env bash

TARGETDIR="generated_code/"
TARGETFILE="rects"

mkdir -p $TARGETDIR
rm -f ${TARGETDIR}/${TARGETFILE}.*

for f in data/*.csv
do
    if [[ ! $f =~ _all\.csv$ ]]
    then
        awk -v target=${TARGETDIR}/${TARGETFILE} -f scripts/generate_rects.awk $f
    fi
done

echo