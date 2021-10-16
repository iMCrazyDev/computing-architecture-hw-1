#include <stdio.h>
#include <process.h>
#include <vector>
#include <chrono>
#include <string>
#include <iostream>

int main() {
    using std::chrono::duration_cast;
    using std::chrono::high_resolution_clock;
    using std::chrono::milliseconds;

    std::vector<std::vector<std::string>> tests = { {" -f", "test\\in1.txt", "test\\outfile1.txt", "test\\outfile11.txt"},
    {"-f", "test\\in2.txt", "test\\outfile2.txt", "test\\outfile21.txt"},
    {"-f", "test\\in3.txt", "test\\outfile3.txt", "test\\outfile31.txt"},
    {"-f", "test\\in4.txt", "test\\outfile4.txt", "test\\outfile41.txt"},
    {"-f", "test\\in5.txt", "test\\outfile5.txt", "test\\outfile51.txt"} };

    for (auto z : tests) {

        auto t1 = high_resolution_clock::now();
        _spawnlp(_P_WAIT, "task.exe", "task.exe", z[0].c_str(), z[1].c_str(), z[2].c_str(), z[3].c_str(), NULL);
        auto t2 = high_resolution_clock::now();
        auto ms_int = duration_cast<milliseconds>(t2 - t1);
        std::cout << z[1] << " " << ms_int.count() << " ms. " << std::endl;
    }
}