#include <iostream>
#include <stdexcept>

#include <daltool/d_dlbparser.h>


int main(int argc, char** argv) {
    return dal::parseDLB_v1(nullptr, 0) ? -1 : 0;
}
