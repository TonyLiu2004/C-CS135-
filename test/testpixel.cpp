#include <iostream>
#include <cassert>
#include <cstdlib>
#include <fstream>
#include <cmath>


using namespace std;

const int MAX_H = 512;
const int MAX_W = 512;

void readImage(int image[MAX_H][MAX_W], int &height, int &width) {
	char c;
	int x;
	ifstream instr;
	instr.open("inImage.pgm");

	// read the header P2
	instr >> c;
	assert(c == 'P');
	instr >> c;
	assert(c == '2');

	// skip the comments (if any)
	while ((instr>>ws).peek() == '#') {
		instr.ignore(4096, '\n');
	}

	instr >> width;
	instr >> height;

	assert(width <= MAX_W);
	assert(height <= MAX_H);
	int max;
	instr >> max;
	assert(max == 255);

	for (int row = 0; row < height; row++)
		for (int col = 0; col < width; col++)
			instr >> image[row][col];
	instr.close();
	return;
}


// Writes a PGM file
// Need to provide the array data and the image dimensions
void writeImage(int image[MAX_H][MAX_W], int height, int width) {
	ofstream ostr;
	ostr.open("outImage.pgm");
	if (ostr.fail()) {
		cout << "Unable to write file\n";
		exit(1);
	};

	// print the header
	ostr << "P2" << endl;
	// width, height
	ostr << width << ' ';
	ostr << height << endl;
	ostr << 255 << endl;

	for (int row = 0; row < height; row++) {
		for (int col = 0; col < width; col++) {
			assert(image[row][col] < 256);
			assert(image[row][col] >= 0);
			ostr << image[row][col] << ' ';
			ostr << endl;
		}
	}
	ostr.close();
	return;
}
void pixelate(std::string fileimg) {
    int height; 
    int width; 
    int image[MAX_H][MAX_W];
    int average;

    readImage(image, height, width);

    for(int i = 0;i < height; i+=2){
        for(int j = 0;j < width;j+=2){
            average = round(((image[i][j] + image[i+1][j] + image[i][j+1] + image[i+1][j+1]) / 4) + 0.5);
            image[i][j] = average;
            image[i + 1][j] = average;
            image[i][j + 1] = average;
            image[i + 1][j + 1] = average;
        }
    }

    writeImage(image, height, width);
}

int main(){
    pixelate("inImage.pgm");
}