#include "Render/outline.h"
#include <iostream>
using namespace Approach::Render;

int main() {
 auto outline = Outline("root");
 auto child1 = Outline("child1");
 auto child2 = Outline("child2");
 auto subchild1 = Outline("subchild1");

 child1 << subchild1;

 outline << child1;
 outline << child2;

 std::cout << outline << '\n';
}
