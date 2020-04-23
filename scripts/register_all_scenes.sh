#!/usr/bin/env bash
set -euo pipefail

IFACES='generated_code/scenes_interfaces.h'
SCENEDB='generated_code/scenes_db.h'

echo -ne '' > ${IFACES}
echo -ne '' > ${SCENEDB}

SCENES=$(ls scenes/ | grep -v lib)

cat >> ${SCENEDB} << EOF
#ifndef SCENES_DB_H
#define SCENES_DB_H

#define ALL_SCENES \\
    { \\
EOF

for scene in ${SCENES}
do
    echo -ne "Processing ${scene}..."
    echo "#include \"../scenes/${scene}/interface.h\"" >> ${IFACES}
    echo "SCENE_DB_ENTRY(${scene}), \\" >> ${SCENEDB}
    echo " Done!"
done



cat >> ${SCENEDB} << EOF
    }

#endif
EOF