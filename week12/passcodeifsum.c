int passCode(int * code) {
    int sum = 0; // N+=1 E+=1
    if (code[0] == 'C') sum++; // N+=2 E+=3
    // it's E+3 because:
    // the if statement condition is false is 1 path
    // and you need 2 edges to, 1 to reach sum++ and 1 
    // to exit the if statement
    if (code[1] == 'R') sum++; // N+=2 E+=3
    if (code[2] == 'E') sum++; // N+=2 E+=3
    if (code[3] == 'D') sum++; // N+=2 E+=3
    if (code[4] == 'I') sum++; // N+=2 E+=3
    if (code[5] == 'T') sum++; // N+=2 E+=3
    return sum==6; // N+=1
}
