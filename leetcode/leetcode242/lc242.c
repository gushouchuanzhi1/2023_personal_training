bool isAnagram(char* s, char* t) {
    if (strlen(s) != strlen(t)) {
        return false;
    }
    int note[26] = { 0 };
    for (int i = 0; i < strlen(s); i++) {
        note[s[i] - 'a']++;
    }
    for (int j = 0; j < strlen(t); j++) {
        note[t[j] - 'a']--;
    }
    for (int p = 0; p < 26; p++) {
        if (note[p] != 0) {
            return false;
        }
    }
    return true;
}