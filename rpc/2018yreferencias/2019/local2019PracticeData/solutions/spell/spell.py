#!/usr/bin/env python

import sys

def one_deleted(word, dictword):
    if missing_one(dictword, word):
        print("ONE LETTER OMITTED FROM " + dictword)
        return True
    return False

def one_added(word, dictword):
    if missing_one(word, dictword):
        print("ONE LETTER ADDED TO " + dictword)
        return True
    return False

def one_changed(word, dictword):
    if len(word) != len(dictword):
        return False

    wrong = 0
    for i in range(0, len(word)):
        if word[i] != dictword[i]:
            wrong += 1

    if wrong == 1:
        print("ONE LETTER DIFFERENT FROM " + dictword)
        return True

    return False

def transposed(word, dictword):
    if len(word) != len(dictword):
        return False

    wrong = 0
    i = 0

    while i < len(dictword) - 1:
        if word[i] == dictword[i]:
            i += 1
            continue

        if word[i] == dictword[i+1] and dictword[i] == word[i+1]:
            i += 2
            wrong += 1
            continue

        return False

    if wrong == 1:
        print("TWO LETTERS TRANSPOSED IN " + dictword)
        return True

    return False

def missing_one(longer, shorter):
    if len(longer) != 1 + len(shorter):
        return False

    i = 0
    for ch in longer:
        if i < len(shorter) and shorter[i] == ch:
            i += 1

    return i + 1 == len(longer)

d = int(sys.stdin.readline())
dictwords = [sys.stdin.readline().strip() for x in range(0, d)]
n = int(sys.stdin.readline())
words = [sys.stdin.readline().strip() for x in range(0, n)]

for word in words:
    print(word)
    if word in dictwords:
        print("CORRECT")
    else:
        unknown = True
        for dw in dictwords:
            if one_deleted(word, dw) or \
                one_added(word, dw) or \
                one_changed(word, dw) or \
                transposed(word, dw):
                    unknown = False

        if unknown:
            print("UNKNOWN")
    print()

