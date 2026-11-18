def my_levenshtein(s1, s2):
    if len(s1) != len(s2):
        return -1
    index=0
    count=0
    while index<len(s1):
        if s1[index] != s2[index]:
            count += 1
        index += 1
    return count
    