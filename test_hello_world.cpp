#define CATCH_CONFIG_MAIN
#include "catch_amalgamated.hpp"
#include <sstream>
#include <iostream>

using namespace std;

TEST_CASE("Program prints Hello World!", "[hello]") {
    // Redirect std::cout
    ostringstream buffer;
    streambuf* old = cout.rdbuf(buffer.rdbuf());

    // Call the student's main()
    // (If they have a normal main, we can just declare it here)
    extern int main();
    REQUIRE(main() == 0);

    cout.rdbuf(old); // restore cout

    string out = buffer.str();
    // trim trailing newline
    while (!out.empty() && (out.back() == '\n' || out.back() == '\r'))
        out.pop_back();

    REQUIRE(out == "Hello World!");
}
