def my_string_index(haystack, needle):
    index = 0
    while index < len(haystack):
        if haystack[index] == needle:
            return index
        index += 1
    return -1
