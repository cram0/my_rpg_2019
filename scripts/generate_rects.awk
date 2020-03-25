BEGIN {
    FS=","
    line = 0
    struct_name = ARGV[1]
    cfile = target ".c"
    hfile = target ".h"

    gsub(".csv", "", struct_name)
    gsub("data/", "", struct_name)

    printf "%s... ", struct_name

    printf "const sfIntRect %s[];\n", struct_name >> hfile

    printf "const sfIntRect %s[] = {\n", struct_name >> cfile
}

{
    if (line > 0) {
        printf "    { .left = %4s, .top = %4s, .width = %4s, .height = %4s, },\n", $1, $2, $3, $4 >> cfile
    }
    line++
}

END {
    printf "    { .left =    0, .top =    0, .width =    0, .height =    0, },\n", $1, $2, $3, $4 >> cfile
    print "};\n" >> cfile
}