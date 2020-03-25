BEGIN {
    FS=","
    line = 0
    struct_name = ARGV[1]
    gsub(".csv", "", struct_name)
    gsub("data/", "", struct_name)
    printf "const sfRectInt %s[] = {\n", struct_name
}

{
    if (line > 0) {
        printf "    { .x = %4s, .y = %4s, .width = %4s, .height = %4s, },\n", $1, $2, $3, $4
    }
    line++
}

END {
    printf "    { .x =    0, .y =    0, .width =    0, .height =    0, },\n", $1, $2, $3, $4
    print "};"
}