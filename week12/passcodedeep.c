int passCode(int * code) {

    if ( code[0] == 'C' ) { // N+=1 E+=2
        if ( code[1] == 'R' ) { // N+=1 E+=2
            if ( code[2] == 'E' ) { // N+=1 E+=2
                if ( code[3] == 'D' ) { // N+=1 E+=2
                    if ( code[4] == 'I' ) { // N+=1 E+=2
                        if ( code[5] == 'T' ) { // N+=1 E+=2
                            return 1; // N+=1
                        }
                    }
                }
            }
        }
    }
    return 0; // N+=1
}
