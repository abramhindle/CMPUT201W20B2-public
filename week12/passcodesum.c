int passCode(int * code) {
    int sum = 0; // N+=1 E+=1
    sum += code[0] == 'C'; // N+=1 E+=1
    sum += code[1] == 'R'; // N+=1 E+=1
    sum += code[2] == 'E'; // N+=1 E+=1
    sum += code[3] == 'D'; // N+=1 E+=1
    sum += code[4] == 'I'; // N+=1 E+=1
    sum += code[5] == 'T'; // N+=1 E+=1
    return sum==6; // N+=1
}
