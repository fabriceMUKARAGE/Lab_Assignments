#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
#include<cmath>
using namespace std;

/*
Class for the rectBlocks which will that all blocks from the file called dataBlocks.txt
and it is also the base class
*/
int* NumbersArray = new int[60];  // this array will keep all numbers from the file and it is global
class rectBlocks {
public:
    void MyrectBlocks() {
        //reading the file from the beginning to the ending of the file
        ifstream is("dataBlocks.dat");
        istream_iterator<double> start(is), end;

        // vector which will take all values from the file
        vector<double> numbers(start, end);
        for (int i = 0; i < 60; i++) {
            if (i % 3 == 0) {
                cout << endl << "Block: " << (i / 3) + 1 << endl;
            }
            NumbersArray[i] = numbers[i];
            cout << " " << NumbersArray[i];


        }
        cout << endl;

    }



};




/*
derived class called sqrBaseRectBlock which inherits from rectBlocks class
*/
int* SquareBaseSide = new int[60];  // Array which will be used in derived class
class sqrBaseRectBlocks : public rectBlocks {
public:
    void MysqrBaseRectBlocks() {
        /*
        for loop which will check for the blocks with the square base
        */
        for (int i = 0; i < 60; i++) {
            if ((i % 3 == 0) && (NumbersArray[i] == NumbersArray[i + 1])) {
                cout << endl << "Block: " << (i / 3) + 1 << endl;
                SquareBaseSide[i] = NumbersArray[i];
                SquareBaseSide[i + 1] = NumbersArray[i + 1];
                SquareBaseSide[i + 2] = NumbersArray[i + 2];
                // displaying the lenght, witdth, and height for each block with square base
                cout << " " << NumbersArray[i] << " " << NumbersArray[i + 1] << " " << NumbersArray[i + 2];
            }
            if ((i % 3 == 0) && (NumbersArray[i] != NumbersArray[i + 1])) {
                SquareBaseSide[i] = 0;
            }

        }
        cout << endl;
    }
};




/*
derived class called cuboidBlocks which inherits from sqrBaseRectBlocks class
*/
class  cuboidBlocks : public sqrBaseRectBlocks {
public:
    void MycuboidBlocks() {

        // for loop to check for the blocks with length=width=height
        for (int i = 0; i < 60; i++) {
            if ((i % 3 == 0) && (SquareBaseSide[i] == SquareBaseSide[i + 1]) && (SquareBaseSide[i + 1] == SquareBaseSide[i + 2])) {
                cout << endl << "Block: " << (i / 3) + 1 << endl;
                // displaying the lenght, witdth, and height for each block with square base
                cout << " " << SquareBaseSide[i] << " " << SquareBaseSide[i + 1] << " " << SquareBaseSide[i + 2];
            }
        }
        cout << endl;
    }

};



/*
derived class called cylindricalBlocks which inherits from sqrBaseRectBlocks class
*/
class cylindricalBlocks : public sqrBaseRectBlocks {
public:
    void MycylindricalBlock() {
        double ArrayDiameter[60]; // array to take the diameter's cylindrical block
        double ArrayLength[60]; //array to take the height's cylindrical block
        double ArraySurfaceArea[60]; // array to take the surface Area's cylindrical block

        // variables called temp to swapp the diameter, height, and surface Area when sorting the values on ascending order
        double temp1;
        double temp2;
        double temp3;
        const double pi = 3.14;
        cout << endl << "The Diameter, length, and Surface Area of Cylinderical block are: " << endl;

        // for loop to take the assign the diameter, height, and surface area for every cylinderical block in their arrays
        for (int i = 0; i < 60; i++) {
            if ((i % 3 == 0) && (SquareBaseSide[i] == SquareBaseSide[i + 1])) {
                cout << endl << "Block: " << (i / 3) + 1 << endl;
                ArrayDiameter[i] = SquareBaseSide[i] * 4 / pi;
                ArrayLength[i] = SquareBaseSide[i + 2];
                ArraySurfaceArea[i] = ArrayDiameter[i] * pi * (ArrayLength[i] + (ArrayDiameter[i] / 2));
                cout << " " << "Diameter: " << ArrayDiameter[i] << ", Length: " << ArrayLength[i] << ", Surface Area: " << ArraySurfaceArea[i];
            }
        }
        cout << endl;
        cout << endl;

        // for loop to sort the diameter of cylindrical block on ascending order
        for (int i = 0; i < 60; i++)
        {
            for (int j = 0; j < 60 - i - 1; j++)
            {
                if (ArrayDiameter[j] > ArrayDiameter[j + 1]) {
                    temp1 = ArrayDiameter[j];
                    ArrayDiameter[j] = ArrayDiameter[j + 1];
                    ArrayDiameter[j + 1] = temp1;
                }
            }
        }
        cout << "The Diameter of cylindrical Blocks on ascending order are: " << endl;
        for (int i = 0; i < 60; i++)
        {
            if (ArrayDiameter[i] > 0) {

                cout << ArrayDiameter[i] << endl;

            }
        }

        // for loop to sort the height of cylindrical block on ascending order
        for (int i = 0; i < 60; i++)
        {
            for (int j = 0; j < 60 - i - 1; j++)
            {
                if (ArrayLength[j] > ArrayLength[j + 1]) {
                    temp2 = ArrayLength[j];
                    ArrayLength[j] = ArrayLength[j + 1];
                    ArrayLength[j + 1] = temp2;
                }
            }
        }
        cout << "The length of cylindrical Blocks on ascending order are: " << endl;
        for (int i = 0; i < 60; i++)
        {
            if (ArrayLength[i] > 0) {

                cout << ArrayLength[i] << endl;

            }
        }

        // for loop to sort the surface Area of cylindrical block on ascending order
        for (int i = 0; i < 60; i++)
        {
            for (int j = 0; j < 60 - i - 1; j++)
            {
                if (ArraySurfaceArea[j] > ArraySurfaceArea[j + 1]) {
                    temp3 = ArraySurfaceArea[j];
                    ArraySurfaceArea[j] = ArraySurfaceArea[j + 1];
                    ArraySurfaceArea[j + 1] = temp3;
                }
            }
        }
        cout << "The Surface Area of cylindrical Blocks on ascending order are: " << endl;
        for (int i = 0; i < 60; i++) {
            if (ArraySurfaceArea[i] > 0) {

                cout << ArraySurfaceArea[i] << endl;

            }
        }

        cout << endl;
    }
};





/*
derived class called sphericalBlock which inherits from cuboidBlocks class
*/
class  sphericalBlocks : public cuboidBlocks {
public:
    void MysphericalBlock() {
        double ArraySphereDiameter[60];
        double pi = 3.14;
        double temp;
        // for loop to assign the diameters of spherical block to the array
        for (int i = 0; i < 60; i++) {
            if ((i % 3 == 0) && (SquareBaseSide[i] == SquareBaseSide[i + 1]) && (SquareBaseSide[i + 1] == SquareBaseSide[i + 2])) {
                ArraySphereDiameter[i] = SquareBaseSide[i] * 4 / pi;
            }
        }
        cout << endl;

        //for loop to sort the diameter of spherical block on ascending order
        for (int i = 0; i < 60; i++)
        {
            for (int j = 0; j < 60 - i - 1; j++)
            {
                if (ArraySphereDiameter[j] > ArraySphereDiameter[j + 1]) {
                    temp = ArraySphereDiameter[j];
                    ArraySphereDiameter[j] = ArraySphereDiameter[j + 1];
                    ArraySphereDiameter[j + 1] = temp;
                }
            }
        }
        cout << "The ascending order of spherical blocks' diameters, spherical surface, and volume are: " << endl << endl;

        //for loop to display both spherical blocks' diameters, spherical surface area, and volume on ascending order
        // both spherical area and volume will be on ascending order since they depend on their diameters
        for (int i = 0; i < 60; i++)
        {
            if (ArraySphereDiameter[i] > 0) {
                double volume = (4 / 3) * pi * (ArraySphereDiameter[i] / 2) * (ArraySphereDiameter[i] / 2) * (ArraySphereDiameter[i] / 2);
                double surfaceArea = 4 * pi * (ArraySphereDiameter[i] / 2) * (ArraySphereDiameter[i] / 2);
                cout << "The Diameter: " << ArraySphereDiameter[i] << ", Surface Area: " << surfaceArea << ", Volume: " << volume << endl;

            }
        }
    }

};





// main function which will execute the code from the classes.
int main() {
    cout << "All Blocks: " << endl;
    rectBlocks blocks;
    blocks.MyrectBlocks();

    cout << endl;
    cout << "Blocks with The Square Base: " << endl;
    sqrBaseRectBlocks squareBase;
    squareBase.MysqrBaseRectBlocks();

    cout << endl;
    cout << "Blocks for Cuboid: " << endl;
    cuboidBlocks  cuboid;
    cuboid.MycuboidBlocks();

    cylindricalBlocks cylinder;
    cylinder.MycylindricalBlock();

    sphericalBlocks sphere;
    sphere.MysphericalBlock();
}


