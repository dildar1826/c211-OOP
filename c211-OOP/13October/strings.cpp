int find(String subStr, int start = 0) {
    int i = start;
    
    // Loop through the main string until the end
    while (data[i] != '\0') {
        int j = 0;
        
        // Compare characters side-by-side:
        // data[i + j] moves through the sliding window in the main string,
        // while subStr.data[j] moves through the substring characters.
        while (subStr.data[j] != '\0' && data[i + j] == subStr.data[j]) {
            j++;
        }
        
        // If j reached the null terminator of subStr, it means 
        // every single character matched successfully!
        if (subStr.data[j] == '\0') {
            return i; // Return the exact starting index of the match
        }
        
        // Otherwise, move to the next position in the main string and try again
        i++;
    }
    
    // If the whole string is searched and no match is found
    return -1;
}
