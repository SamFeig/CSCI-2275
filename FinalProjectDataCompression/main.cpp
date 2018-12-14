#include <iostream>
#include <fstream>
#include <sstream>
#include "RunLength.h"
#include "LZW.h"
#include "Huffman.h"
#include "Util.cpp"
using namespace std;

int main(int argc, char* argv[]) {
    try {
        string repeattxt = argv[1];
        string repeatout = "Out/rle_repeatOut.bin";
        string repeatout2 = "Out/lzw_repeatOut.bin";
        string repeatout3 = "Out/huff_repeatOut.bin";

        string shorttxt = argv[2];
        string shortout = "Out/rle_shortOut.bin";
        string shortout2 = "Out/lzw_shortOut.bin";
        string shortout3 = "Out/huff_shortOut.bin";

        string longtxt = argv[4];
        string longout = "Out/rle_longOut.bin";
        string longout2 = "Out/lzw_longOut.bin";
        string longout3 = "Out/huff_longOut.bin";



        ifstream rtext(repeattxt), stext(shorttxt), ltext(longtxt);
        if(!rtext.is_open() || !stext.is_open() || !ltext.is_open()) {
            throw runtime_error("Exception: Unable to open file.");
        }

        stringstream rstream, sstream, lstream, mstream;
        rstream << rtext.rdbuf();
        sstream << stext.rdbuf();
        lstream << ltext.rdbuf();

        rtext.close();
        stext.close();
        ltext.close();


        cout<<endl;
        cout<<"-------------------------------------------------------------------------------------"<<endl;
        cout<<"Run Length Encoding"<<endl;
        cout<<endl<<"Repeats:"<<endl;

        try {
            const string file_content = rstream.str();
            int file_size = FileUtil::getFileSize(repeattxt);

            RunLength rle;
            const string encoded = rle.encode(file_content);

            FileUtil::writeString(repeatout, encoded);

            int after_size = FileUtil::getFileSize(repeatout);

            const string output_data = FileUtil::readString(repeatout);

            cout << "Before compression: " << file_size << " bytes" << endl;
            cout << "After compression: " << after_size << " bytes" << endl;
            cout << "Delta: " << file_size - after_size << " bytes" << endl;
            cout << "Compression Ratio: " << ((double) file_size / after_size) << endl;
        }
        catch(exception& e) {
            cout << e.what() << endl;
        }

        cout<<endl<<"Short:"<<endl;

        try {
            const string file_content = sstream.str();
            int file_size = FileUtil::getFileSize(shorttxt);

            RunLength rle;
            const string encoded = rle.encode(file_content);

            FileUtil::writeString(shortout, encoded);

            int after_size = FileUtil::getFileSize(shortout);

            const string output_data = FileUtil::readString(shortout);

            cout << "Before compression: " << file_size << " bytes" << endl;
            cout << "After compression: " << after_size << " bytes" << endl;
            cout << "Delta: " << file_size - after_size << " bytes" << endl;
            cout << "Compression Ratio: " << ((double) file_size / after_size) << endl;
        }
        catch(exception& e) {
            cout << e.what() << endl;
        }

        cout<<endl<<"Long:"<<endl;

        try {
            const string file_content = lstream.str();
            int file_size = FileUtil::getFileSize(longtxt);

            RunLength rle;
            const string encoded = rle.encode(file_content);

            FileUtil::writeString(longout, encoded);

            int after_size = FileUtil::getFileSize(longout);

            const string output_data = FileUtil::readString(longout);

            cout << "Before compression: " << file_size << " bytes" << endl;
            cout << "After compression: " << after_size << " bytes" << endl;
            cout << "Delta: " << file_size - after_size << " bytes" << endl;
            cout << "Compression Ratio: " << ((double) file_size / after_size) << endl;
        }
        catch(exception& e) {
            cout << e.what() << endl;
        }

        cout<<endl;
        cout<<"-------------------------------------------------------------------------------------"<<endl;
        cout<<"LZW Compression"<<endl;
        cout<<endl<<"Repeats:"<<endl;

        try {
            string file_content = rstream.str();
            int file_size = FileUtil::getFileSize(repeattxt);

            LZW lzw;
            const string encoded = lzw.encode(file_content);
            const auto bytes = TransformUtils::transformStringToBytes(encoded);

            FileUtil::write(repeatout2, bytes);
            int after_size = FileUtil::getFileSize(repeatout2);

            string output_data = FileUtil::read(repeatout2, 100);

            cout << "Before compression: " << file_size << " bytes" << endl;
            cout << "After compression: " << after_size << " bytes" << endl;
            cout << "Delta: " << file_size - after_size << " bytes" << endl;
            cout << "Compression Ratio: " << ((double) file_size / after_size) << endl;

        }
        catch(exception& e) {
            cout << e.what() << endl;
        }

        cout<<endl<<"Short:"<<endl;

        try {
            const string file_content = sstream.str();
            int file_size = FileUtil::getFileSize(shorttxt);

            LZW lzw;
            const string encoded = lzw.encode(file_content);
            const auto bytes = TransformUtils::transformStringToBytes(encoded);

            FileUtil::write(shortout2, bytes);
            int after_size = FileUtil::getFileSize(shortout2);

            const string output_data = FileUtil::read(shortout2, 100);

            cout << "Before compression: " << file_size << " bytes" << endl;
            cout << "After compression: " << after_size << " bytes" << endl;
            cout << "Delta: " << file_size - after_size << " bytes" << endl;
            cout << "Compression Ratio: " << ((double) file_size / after_size) << endl;

        }
        catch(exception& e) {
            cout << e.what() << endl;
        }

        cout<<endl<<"Long:"<<endl;

        try {
            const string file_content = lstream.str();
            int file_size = FileUtil::getFileSize(longtxt);

            LZW lzw;
            const string encoded = lzw.encode(file_content);
            const auto bytes = TransformUtils::transformStringToBytes(encoded);

            FileUtil::write(longout2, bytes);
            int after_size = FileUtil::getFileSize(longout2);

            const string output_data = FileUtil::read(longout2, 100);

            cout << "Before compression: " << file_size << " bytes" << endl;
            cout << "After compression: " << after_size << " bytes" << endl;
            cout << "Delta: " << file_size - after_size << " bytes" << endl;
            cout << "Compression Ratio: " << ((double) file_size / after_size) << endl;
        }
        catch(exception& e) {
            cout << e.what() << endl;
        }

        cout<<endl;
        cout<<"-------------------------------------------------------------------------------------"<<endl;
        cout<<"Huffman Compression"<<endl;
        cout<<endl<<"Repeats:"<<endl;

        try {
            const string file_content = rstream.str();
            int file_size = FileUtil::getFileSize(repeattxt);

            Huffman huffman_tree(file_content);
            const string encoded = huffman_tree.encode(file_content);
            const auto bytes = TransformUtils::transformStringToBytes(encoded);

            FileUtil::write(repeatout3, bytes);
            int after_size = FileUtil::getFileSize(repeatout3);

            const string output_data = FileUtil::read(repeatout3, 100);

            cout << "Before compression: " << file_size << " bytes" << endl;
            cout << "After compression: " << after_size << " bytes" << endl;
            cout << "Delta: " << file_size - after_size << " bytes" << endl;
            cout << "Compression Ratio: " << ((double) file_size / after_size) << endl;
        }
        catch(exception& e) {
            cout << e.what() << endl;
        }

        cout<<endl<<"Short:"<<endl;

        try {
            const string file_content = sstream.str();
            int file_size = FileUtil::getFileSize(shorttxt);

            Huffman huffman_tree(file_content);
            const string encoded = huffman_tree.encode(file_content);
            const auto bytes = TransformUtils::transformStringToBytes(encoded);

            FileUtil::write(shortout3, bytes);
            int after_size = FileUtil::getFileSize(shortout3);

            const string output_data = FileUtil::read(shortout3, 100);

            cout << "Before compression: " << file_size << " bytes" << endl;
            cout << "After compression: " << after_size << " bytes" << endl;
            cout << "Delta: " << file_size - after_size << " bytes" << endl;
            cout << "Compression Ratio: " << ((double) file_size / after_size) << endl;
        }
        catch(exception& e) {
            cout << e.what() << endl;
        }

        cout<<endl<<"Long:"<<endl;

        try {
            const string file_content = lstream.str();
            int file_size = FileUtil::getFileSize(longtxt);

            Huffman huffman_tree(file_content);
            const string encoded = huffman_tree.encode(file_content);
            const auto bytes = TransformUtils::transformStringToBytes(encoded);

            FileUtil::write(longout3, bytes);
            int after_size = FileUtil::getFileSize(longout3);

            const string output_data = FileUtil::read(longout3, 100);

            cout << "Before compression: " << file_size << " bytes" << endl;
            cout << "After compression: " << after_size << " bytes" << endl;
            cout << "Delta: " << file_size - after_size << " bytes" << endl;
            cout << "Compression Ratio: " << ((double) file_size / after_size) << endl;

//            cout << huffman_tree.decode(output_data);
        }
        catch(exception& e) {
            cout << e.what() << endl;
        }
    }
    catch(exception& e) {
        cout << e.what() << endl;
    }

    return 0;

}

/*
-------------------------------------------------------------------------------------
Run Length Encoding

Repeats:
Before compression: 85 bytes
After compression: 16 bytes
Delta: 69 bytes
Compression Ratio: 5.3125

Short:
Before compression: 111 bytes
After compression: 218 bytes
Delta: -107 bytes
Compression Ratio: 0.509174

Long:
Before compression: 506781 bytes
After compression: 991798 bytes
Delta: -485017 bytes
Compression Ratio: 0.510972

-------------------------------------------------------------------------------------
LZW Compression

Repeats:
Before compression: 85 bytes
After compression: 10 bytes
Delta: 75 bytes
Compression Ratio: 8.5

Short:
Before compression: 111 bytes
After compression: 30 bytes
Delta: 81 bytes
Compression Ratio: 3.7

Long:
Before compression: 506781 bytes
After compression: 76339 bytes
Delta: 430442 bytes
Compression Ratio: 6.63856

-------------------------------------------------------------------------------------
Huffman Compression

Repeats:
Before compression: 85 bytes
After compression: 26 bytes
Delta: 59 bytes
Compression Ratio: 3.26923

Short:
Before compression: 111 bytes
After compression: 59 bytes
Delta: 52 bytes
Compression Ratio: 1.88136

Long:
Before compression: 506781 bytes
After compression: 267850 bytes
Delta: 238931 bytes
Compression Ratio: 1.89203
 */