#!/usr/bin/env bash
set -euo pipefail

TARGETDIR="generated_code/"
TARGETFILE_RECTS="rects"
TARGETFILE_ORIGS="origins"

mkdir -p ${TARGETDIR}

echo '#include <SFML/Graphics.h>' > ${TARGETDIR}/${TARGETFILE_RECTS}.c
echo '#include <SFML/Graphics.h>' > ${TARGETDIR}/${TARGETFILE_RECTS}.h
echo '#include <SFML/Graphics.h>' > ${TARGETDIR}/${TARGETFILE_ORIGS}.c
echo '#include <SFML/Graphics.h>' > ${TARGETDIR}/${TARGETFILE_ORIGS}.h

for f in data/rectangles/*.csv
do
    if [[ ! $f =~ _all\.csv$ ]]
    then
        awk -v target=${TARGETDIR}/${TARGETFILE_RECTS} -f scripts/generate_rects.awk $f
    fi
done

for f in data/origins/*.csv
do
    if [[ ! $f =~ _all\.csv$ ]]
    then
        awk -v target=${TARGETDIR}/${TARGETFILE_ORIGS} -f scripts/generate_origins.awk $f
    fi
done

echo