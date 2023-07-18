bool isPalindome(char *s, int i, int j) {
    while (i < j) {
        if (s[i] != s[j]) {
            return false;
        }
        i += 1, j -= 1;
    }
    return true;
}

char * longestPalindrome(char * s) {
    int size = strlen(s);

    // Max length palindome I could get:
    for (int length = size; length != 0; length--) {
        // starting point for that max length:
        // Example: length = 4
        // isPalindome(0, 3)?
        // isPalindome(1, 4)?
        // isPalindome(2, 5)? -> If this is True, we ended.
        for (int start = 0; start < (size - length + 1); start++) {
            if (isPalindome(s, start, start + length -1)) {
                s[start + length] ='\0';
                return s + start;
            }
        }
    }
    return NULL;
}
