#ifndef DERIVEDNODE_H
#define DERIVEDNODE_H

#include "approach/Render/node.h"
#include <opencv2/opencv.hpp>

namespace MyNamespace {
 class DerivedNode : public Approach::Render::Node {
 public:
  DerivedNode();
  void someMethod();
 };
}

#endif // DERIVEDNODE_H
