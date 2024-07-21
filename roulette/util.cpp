/**
 * Checks if an integer is present in an integer array
 * 
 * @param needle The integer to search for
 * @param haystack A pointer to an array of integers
 * @param size The size of the array
 * 
 * @return true if the integer is present, else false
 */
bool boolFindInt(int needle, int* haystack, int size) {
    for (int i = 0; i < size; i++) {
        if (needle == haystack[i]) {
            return true;
        }
    }
    return false;
}