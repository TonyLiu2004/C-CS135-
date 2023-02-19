#include <iostream>
#include "transcriptase.h"

int main(){
    std::cout << transcriptase("CCTCTAAGATTTGTTTGATACGTTACTTGTGCAGTCGAAGCTTTG") << "\n";
    std::cout << transcriptase("GTAGGCTTACGCTAAGCCTACGTTACTTGTGCAGTCGAAGCTTTG") << "\n";

    return 0;
}