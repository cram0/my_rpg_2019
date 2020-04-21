#!/usr/bin/env bash
set -euo pipefail

make fclean

SCENES_DIR='scenes/'
SCENE_NAME=$(echo ${1} | tr '[:upper:]' '[:lower:]')
SCENE_PATH=${SCENES_DIR}${SCENE_NAME}
echo "Path is: '${SCENE_PATH}'"

UPPERCASE_NAME=$(echo ${1} | tr '[:lower:]' '[:upper:]')

read -p "Are you sure this path is correct? " -n 1 -r
echo    # (optional) move to a new line
if [[ $REPLY =~ ^[Yy]$ ]]
then
    rm -rf ${SCENE_PATH}
    echo "Removed ${SCENE_PATH}"
    cp -r template_scene ${SCENE_PATH}
    echo "Copied template into ${SCENE_PATH}"

    find ${SCENE_PATH} -type f -print0 |
        xargs -0 sed -i "s/xxxxx/${SCENE_NAME}/g"

    find ${SCENE_PATH} -type f -print0 |
        xargs -0 sed -i "s/XXXXX/${UPPERCASE_NAME}/g"

    echo "Filled in scene name in all the files"

    bash scripts/register_all_scenes.sh
fi

echo "Exited safely"