# patterns=(
#     ".DS_Store"
#     "tempCodeRunnerFile"
#     "a.out"
#     "*.dSYM"
#     "*.gch"
#     "*.obj"
#     "*.o"
#     "*.d"
#     "tempCodeRunnerFile"
# )

# find . \( -name "${patterns[0]}" $(printf -- '-o -name "%s" ' "${patterns[@]:1}") \) -exec rm {} +
find . \( -name ".DS_Store" -o -name "tempCodeRunnerFile" -o -name "a.out" -o -name "*.dSYM" -o -name "*.gch" -o -name "*.obj" -o -name "*.o" -o -name "*.d" -o -name "*tempCodeRunnerFile" \) -exec rm {} \;