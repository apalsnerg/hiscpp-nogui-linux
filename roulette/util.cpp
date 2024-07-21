bool boolFindInt(int needle, int* haystack, int size) {
    for (int i = 0; i < size; i++) {
        if (needle == haystack[i]) {
            return true;
        }
    }
    return false;
}