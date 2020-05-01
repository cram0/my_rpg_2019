BEGIN {
    FS=","
    struct_name = ARGV[1]
    cfile = target ".c"
    hfile = target ".h"

    gsub(".csv", "", struct_name)
    gsub("data/origins/", "", struct_name)

    printf "%s... ", struct_name

    printf "const sfVector2f %s_origs[] = {\n", struct_name >> cfile

    i = 0
}

/^[0-9]+,[0-9]+$/ {
    i += 1
    printf "    { .x = %4s, .y = %4s },\n", $1, $2 >> cfile
}

END {
    printf "    { .x =    0, .y =    0 },\n", $1, $2 >> cfile
    print "};\n" >> cfile

    printf "const sfVector2f %s_origs[%d];\n", struct_name, i + 1 >> hfile
}